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

#ifndef MAPRENDERER_HPP
#define	MAPRENDERER_HPP

#include <opencv2/core.hpp>
#include "types.hpp"

class MapRenderer{
    
    private:
        
    cv::Mat * map;
    raycasting::Player * player;
    std::vector< std::pair<raycasting::Point, raycasting::Point> > walls;
    
    public:
    
    MapRenderer(cv::Mat * map,
                raycasting::Player* player,
                std::vector< std::pair<raycasting::Point, raycasting::Point> > &walls);
    
    void render();
    
    ~MapRenderer();
    
};

#endif	/* MAPRENDERER_HPP */

