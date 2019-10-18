/**
 * Copyright (c) 2014, Julien 'Blaxar' Bardagi <blaxar.waldarax@gmail.com>
 * All rights reserved.
 *
 * This file is part of crapcasting.
 *
 * crapcasting is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <cstdlib>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <raycasting/maprenderer.hpp>
#include <raycasting/CvProjectionRenderer.hpp>
#include <raycasting/CacaProjectionRenderer.hpp>
#include <cstdlib>
#include <time.h>

using namespace std;
using namespace cv;

void update_player(raycasting::Player * player, char key);

int main(int argc, char** argv) {

    raycasting::DisplaySize cv_display_size = DEFAULT_PROJECTION_SIZE;
    raycasting::DisplaySize caca_display_size = {cv_display_size.width/4, cv_display_size.height/8};
    int map_width = 500;
    int map_height = 500;
    float frame_interval_ms = 1000.0/60.0;

    raycasting::Player * player = new raycasting::Player;
    player->position.x = 250;
    player->position.y = 220;
    player->orientation = M_PI ;

    vector< pair<raycasting::Point,raycasting::Point> > walls;

    walls.push_back(pair<raycasting::Point,raycasting::Point>(raycasting::Point(150,250), raycasting::Point(250,150)));
    walls.push_back(pair<raycasting::Point,raycasting::Point>(raycasting::Point(350,150), raycasting::Point(350,350)));
    walls.push_back(pair<raycasting::Point,raycasting::Point>(raycasting::Point(350,350), raycasting::Point(150,350)));
    walls.push_back(pair<raycasting::Point,raycasting::Point>(raycasting::Point(150,350), raycasting::Point(150,150)));

    Mat map = Mat::zeros(map_height, map_width, CV_8UC3);
    Mat viewpoint = Mat::zeros(cv_display_size.height, cv_display_size.width, CV_8UC3);

    caca_canvas_t *caca_cv;
    caca_display_t *caca_dp;

    caca_cv = caca_create_canvas(caca_display_size.width, caca_display_size.height);
    if(caca_cv == NULL)
    {
        printf("Failed to create canvas\n");
        return 1;
    }

    caca_dp = caca_create_display(caca_cv);
    if(caca_dp == NULL)
    {
        printf("Failed to create display\n");
        return 1;
    }

    MapRenderer mapr(&map, player, walls);
    CvProjectionRenderer cv_projr(&viewpoint, player, walls, cv_display_size);
    CacaProjectionRenderer caca_projr(caca_dp, caca_cv, player, walls, caca_display_size);

    char key = 0;

    while(key != 27){ //escape key

        map = Mat::zeros(map_height, map_width, CV_8UC3);
        viewpoint = Mat::zeros(cv_display_size.height, cv_display_size.width, CV_8UC3);
        caca_set_color_ansi(caca_cv, CACA_BLACK, CACA_BLACK);
        caca_clear_canvas(caca_cv);

        mapr.render();
        cv_projr.render();
        caca_projr.render();

        caca_refresh_display(caca_dp);

        imshow("viewpoint", viewpoint);
        flip(map, map, 0);
        imshow("map", map);

        key = waitKey(frame_interval_ms);

        update_player(player, key);

    }

    caca_free_display(caca_dp);
    caca_free_canvas(caca_cv);

    return 0;

}

void update_player(raycasting::Player * player, char key){

    switch(key){

        case 'z': //forward "z"
        {
            raycasting::Point direction1(0,0.5);

            float dirx1 = cos(player->orientation)*direction1.x - sin(player->orientation)*direction1.y + player->position.x;
            float diry1 = sin(player->orientation)*direction1.x + cos(player->orientation)*direction1.y + player->position.y;

            player->position.x = dirx1;
            player->position.y = diry1;
        }
        break;

        case 's': //backward "s"
        {
            raycasting::Point direction2(0,-0.5);

            float dirx2 = cos(player->orientation)*direction2.x - sin(player->orientation)*direction2.y + player->position.x;
            float diry2 = sin(player->orientation)*direction2.x + cos(player->orientation)*direction2.y + player->position.y;

            player->position.x = dirx2;
            player->position.y = diry2;
        }    
        break;

        case 'q': //turn left "q"
        {    
            player->orientation += M_PI/60;
        }    
        break;

        case 'd': //turn right "d"
        {    
            player->orientation -= M_PI/60;
        }    
        break;

    }

}
