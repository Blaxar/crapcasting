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

#include <raycasting/ProjectionRenderer.hpp>

using namespace std;

float ProjectionRenderer::getWallDist(std::pair<raycasting::Point, raycasting::Point> wall, int col){

    const float eps = 0.0001;

    float fov = M_PI / 3.0; // 60°
    float hfov = fov / 2.0; // 30°
    raycasting::Point direction(0,500); // the straight forward ray.
    float delta_angle = fov / this->displaySize.width; // difference of angle between two rays

    /* The first column depends on the first ray on the far left
     * of the field of view, therefor it has an angular difference of
     * half the field of view from the central ray (the straight forward ray,
     * which is the direction the player is facing, the "orientation").
     * From the column index, we deduce the correct angle of the ray (delta_angle*col).
     */
    float colangle = (delta_angle*col);
    float rotation = player->orientation + hfov - colangle;

    float dirx = cos(rotation)*direction.x - sin(rotation)*direction.y + this->player->position.x;
    float diry = sin(rotation)*direction.x + cos(rotation)*direction.y + this->player->position.y;

    direction.x = dirx;
    direction.y = diry;

    /* ray and wall intersection detection using vector cross products */

    raycasting::Point p(this->player->position.x, this->player->position.y);
    raycasting::Point q(wall.first.x, wall.first.y);
    raycasting::Point r = direction - this->player->position;
    raycasting::Point s(wall.second.x-wall.first.x,wall.second.y-wall.first.y);
    raycasting::Point qmp = q - p;
    float rts = r * s; //cross product

    float t = (qmp*s)/rts;
    float u = (qmp*r)/rts;

    if( ((rts < -eps) || (rts > eps)) &&
        (0 <= t) && (t <= 1) && (0 <= u) && (u <= 1)){ // If the ray do intersect a wall.

        /* We get the intersection point. */
        raycasting::Point intersection = player->position + (r * t);

        /* We get the distance between the eye and the intersection point. */
        float dist = sqrt( (intersection.x-player->position.x)*(intersection.x-player->position.x)+
                     (intersection.y-player->position.y)*(intersection.y-player->position.y) );

        /* We apply the distortion correction so we don't get the "fish eye" effect */
        dist = dist * cos(colangle-hfov);

        return dist;

    }else{

        return -1;

    }

}
