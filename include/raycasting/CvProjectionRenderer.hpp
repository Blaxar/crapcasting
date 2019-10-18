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

#ifndef CVPROJECTIONRENDERER_HPP
#define	CVPROJECTIONRENDERER_HPP

#include <opencv2/core/core.hpp>
#include "ProjectionRenderer.hpp"

class CvProjectionRenderer: public virtual ProjectionRenderer {

    private:

    cv::Mat * projection;


    public:

    CvProjectionRenderer(cv::Mat* projection,
                         raycasting::Player* player,
                         std::vector< std::pair<raycasting::Point, raycasting::Point> >& walls,
                         raycasting::DisplaySize ds = DEFAULT_PROJECTION_SIZE);

    virtual void render();

    void rendercol(int col);

    float getwalldist(std::pair<raycasting::Point, raycasting::Point> wall, int col);

    virtual ~CvProjectionRenderer();

};    

#endif	/* CVPROJECTIONRENDERER_HPP */
