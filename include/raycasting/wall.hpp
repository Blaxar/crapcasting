/* 
 * File:   wall.hpp
 * Author: blax
 *
 * Created on March 13, 2014, 6:47 PM
 */

#ifndef WALL_HPP
#define	WALL_HPP

#include "point.hpp"

namespace raycasting{

    class Wall{

        public:
        
        unsigned short int type;
        raycasting::Point begin;
        raycasting::Point end;
        
        Wall(){}
        Wall(raycasting::Point begin, raycasting::Point end)
        {this->begin=begin; this->end=end;}
        Wall(raycasting::Point begin, raycasting::Point end, unsigned short int type)
        {this->begin=begin; this->end=end; this->type=type;}
        Wall(unsigned short int type)
        {this->type=type;}
        ~Wall(){}

    };

}

#endif	/* WALL_HPP */

