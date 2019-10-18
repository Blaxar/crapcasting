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

#ifndef PROJECTIONRENDERER_HPP
#define	PROJECTIONRENDERER_HPP

#include <opencv2/core/core.hpp>
#include "types.hpp"

#define DEFAULT_PROJECTION_SIZE {640, 360}

class ProjectionRenderer{

    protected:

    raycasting::Player * player;
    std::vector< std::pair<raycasting::Point, raycasting::Point> > walls;
    raycasting::DisplaySize displaySize;

    public:

    ProjectionRenderer(raycasting::Player* p,
                       std::vector< std::pair<raycasting::Point, raycasting::Point> >& w,
                       raycasting::DisplaySize ds = DEFAULT_PROJECTION_SIZE):
                       player(p), walls(w), displaySize(ds) {}

    void render() {

        for(int col=0; col < displaySize.width; col++) rendercol(col);

    }

    virtual void rendercol(int col) {}

    float getWallDist(std::pair<raycasting::Point, raycasting::Point> wall, int col);

    virtual ~ProjectionRenderer() {}

};

#endif	/* PROJECTIONRENDERER_HPP */
