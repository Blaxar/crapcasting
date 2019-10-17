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

#ifndef TYPES_HPP
#define	TYPES_HPP

#define M_PI 3.14159265358979323846
#define DEFAULT_WALL_TYPE 0

namespace raycasting {

    struct Point {

        Point(){ x=0; y=0;};
        Point(float x, float y){ this->x=x; this->y=y;};
        ~Point(){};

        float x;
        float y;

        float operator * (const Point &p) const{

            return ((this->x*p.y) - (this->y*p.x));

        }

        const Point& operator * (const float &s) const{

            const Point& np = Point(this->x*s,this->y*s);
            return np;

        }

        const Point& operator + (const Point &p){

            const Point& np = Point(this->x+p.x,this->y+p.y);
            return np;

        }

        const Point& operator - (const Point &p){

            const Point& np = Point(this->x-p.x,this->y-p.y);
            return np;

        }

    };

    struct Player {

        Point position;
        float orientation;

    };

    struct Wall {

        Point begin;
        Point end;
        unsigned short int type;

        Wall(Point b, Point e, unsigned short int t = DEFAULT_WALL_TYPE):
            begin(b), end(e), type(t) {}

        ~Wall(){}

    };

};

#endif	/* TYPES_HPP */

