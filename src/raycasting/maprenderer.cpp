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

#include <raycasting/maprenderer.hpp>
#include <math.h>
#include <opencv2/imgproc.hpp>

using namespace cv;

MapRenderer::MapRenderer(cv::Mat* map, raycasting::Player* player, std::vector<std::pair<raycasting::Point, raycasting::Point> >& walls){
    
    this->map = map;
    this->player = player;
    this->walls = walls;
    
}

void MapRenderer::render(){
    
    cv::circle((*this->map), Point(this->player->position.x, this->player->position.y), 3, Scalar(0, 0, 255),1, 8, 0);
    
    raycasting::Point direction(0,10);
    
    float dirx = cos(player->orientation)*direction.x - sin(player->orientation)*direction.y + this->player->position.x;
    float diry = sin(player->orientation)*direction.x + cos(player->orientation)*direction.y + this->player->position.y;
    
    direction.x = dirx;
    direction.y = diry;
    
    cv::line((*this->map),
                Point(this->player->position.x, this->player->position.y),
                Point(direction.x, direction.y),
                Scalar(0, 0, 255),1, 8, 0);
    
    float fov = M_PI / 3.0; // 60°
    float hfov = fov / 2.0; // 30°
    
    for(int col = 0; col < 800; col++){
        
    raycasting::Point direction(0,200);
    float delta_angle = fov / 800;
    
    float rotation = player->orientation + hfov - (delta_angle*col);
    
    dirx = cos(rotation)*direction.x - sin(rotation)*direction.y + this->player->position.x;
    diry = sin(rotation)*direction.x + cos(rotation)*direction.y + this->player->position.y;
    
    direction.x = dirx;
    direction.y = diry;
    
    cv::line((*this->map),
                Point(this->player->position.x, this->player->position.y),
                Point(direction.x, direction.y),
                Scalar(0, 0, 255),1, 8, 0);
        
    }
    
    for(auto &wall : walls){

        cv::line((*this->map),
                Point(wall.first.x, wall.first.y),
                Point(wall.second.x, wall.second.y),
                Scalar(255, 255, 255),1, 8, 0);
        
    }
        
}

MapRenderer::~MapRenderer(){
    
    
    
}
