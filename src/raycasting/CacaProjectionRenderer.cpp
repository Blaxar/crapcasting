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

#include <raycasting/CacaProjectionRenderer.hpp>
#include <iostream>
#include <stdlib.h>
#include <float.h>

using namespace cv;
using namespace std;

const unsigned int shades[] = {CACA_BLACK, CACA_DARKGRAY, CACA_LIGHTGRAY, CACA_WHITE};

CacaProjectionRenderer::CacaProjectionRenderer(caca_display_t* d, caca_canvas_t* c,
                                               raycasting::Player * plr,
                                               std::vector<std::pair<raycasting::Point,
                                               raycasting::Point> > &w, raycasting::DisplaySize ds):
                                               ProjectionRenderer(plr, w ,ds), dp(d), cv(c) {}

void CacaProjectionRenderer::rendercol(int col){

    float z = FLT_MAX;

    for(auto &wall : walls){

        const float walldist = getWallDist(wall, col);
        const float eyesource = 20;
        const float refheight = caca_get_canvas_height(cv);

        if(walldist > 0 && walldist < z){

            z = walldist;
            
            double wallheight_halved = (refheight/(double)walldist)*eyesource / 2;
            double integral;
            double fractional = modf(wallheight_halved, &integral);

            const int y_start = (refheight/2) - integral;
            const int y_stop = (refheight/2) + integral;

            caca_set_color_ansi(cv, CACA_BLACK, CACA_WHITE);
            caca_draw_line (cv, col, y_start, col, y_stop, ' ');

            caca_set_color_ansi(cv, CACA_BLACK, shades[(int)(fractional*4)]);
            caca_put_char (cv, col, y_start - 1, ' ');
            caca_put_char (cv, col, y_stop + 1, ' ');

        }

    }

}

CacaProjectionRenderer::~CacaProjectionRenderer(){



}
