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

#include <raycasting/CvProjectionRenderer.hpp>
#include <iostream>
#include <stdlib.h>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

CvProjectionRenderer::CvProjectionRenderer(cv::Mat* prj, raycasting::Player * plr,
                                           std::vector<std::pair<raycasting::Point,
                                           raycasting::Point> > &w, raycasting::DisplaySize ds):
                                           ProjectionRenderer(plr, w ,ds), projection(prj) {}

void CvProjectionRenderer::rendercol(int col){

    for(auto &wall : walls){

        const float walldist = getWallDist(wall, col);
        const float eyesource = 20;
        const float refheight = this->projection->rows;

        //cout << walldist << endl;

        if(walldist > 0){

            int wallheight = (refheight/walldist)*eyesource;
            cv::line((*this->projection),
                Point(col,(refheight/2)- wallheight/2),
                Point(col,(refheight/2)+ wallheight/2),
                Scalar(255, 255, 255),1, 8, 0);

        }

    }

}

CvProjectionRenderer::~CvProjectionRenderer(){



}
