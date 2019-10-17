/* 
 * File:   projectionrenderer.hpp
 * Author: blax
 *
 * Created on January 25, 2014, 4:12 PM
 */

#ifndef PROJECTIONRENDERER_HPP
#define	PROJECTIONRENDERER_HPP

#include <opencv2/core/core.hpp>
#include "player.hpp"
#include "point.hpp"

class ProjectionRenderer{
    
    private:
        
    cv::Mat * projection;
    raycasting::Player * player;
    std::vector< std::pair<raycasting::Point, raycasting::Point> > walls;
    
    
    public:
    
    ProjectionRenderer(cv::Mat* projection,
                       raycasting::Player* player,
                       std::vector< std::pair<raycasting::Point, raycasting::Point> >& walls);
    
    void render();
    
    void rendercol(int col);
    
    float getwalldist(std::pair<raycasting::Point, raycasting::Point> wall, int col);
    
    ~ProjectionRenderer();

};    

#endif	/* PROJECTIONRENDERER_HPP */
