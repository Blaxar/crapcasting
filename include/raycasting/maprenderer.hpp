/* 
 * File:   maprenderer.hpp
 * Author: blax
 *
 * Created on January 25, 2014, 3:52 PM
 */

#ifndef MAPRENDERER_HPP
#define	MAPRENDERER_HPP

#include "player.hpp"
#include "point.hpp"
#include <opencv2/core.hpp>

class MapRenderer{
    
    private:
        
    cv::Mat * map;
    raycasting::Player * player;
    std::vector< std::pair<raycasting::Point, raycasting::Point> > walls;
    
    public:
    
    MapRenderer(cv::Mat * map, raycasting::Player * player, std::vector< std::pair<raycasting::Point, raycasting::Point> > &walls);
    
    void render();
    
    ~MapRenderer();
    
};

#endif	/* MAPRENDERER_HPP */

