/* 
 * File:   player.hpp
 * Author: blax
 *
 * Created on January 25, 2014, 3:54 PM
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "point.hpp"
#define M_PI 3.14159265358979323846

namespace raycasting{

    struct Player{

        raycasting::Point position;
        float orientation;

    };

};

#endif	/* PLAYER_HPP */

