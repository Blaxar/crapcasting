#include <raycasting/projectionrenderer.hpp>
#include <iostream>
#include <stdlib.h>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

ProjectionRenderer::ProjectionRenderer(cv::Mat* projection, raycasting::Player * player,
        std::vector<std::pair<raycasting::Point, raycasting::Point> > &walls){
    
    this->projection = projection;
    this->player = player;
    this->walls = walls;
    
}

void ProjectionRenderer::render(){
    
    for(int col=0; col < projection->cols; col++){
           
        rendercol(col);
        
    }
   
}

void ProjectionRenderer::rendercol(int col){
    
    for(auto &wall : walls){
        
        float walldist = getwalldist(wall, col);
        float eyesource = 20;
        float refheight = this->projection->rows;
        
        //cout << walldist << endl;
        
        if(walldist > 0){
            
            int wallheight = (refheight/walldist)*eyesource;
            cv::line((*this->projection),
                Point(col,(this->projection->rows/2)- wallheight/2),
                Point(col,(this->projection->rows/2)+ wallheight/2),
                Scalar(255, 255, 255),1, 8, 0);
            
        }
        
    }
    
}

float ProjectionRenderer::getwalldist(std::pair<raycasting::Point, raycasting::Point> wall, int col){
   
    float eps = 0.0001;
    
    float fov = M_PI / 3.0; // 60°
    float hfov = fov / 2.0; // 30°
    raycasting::Point direction(0,500); // the straight forward ray.
    float delta_angle = fov / this->projection->cols; // difference of angle between two rays
    
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

ProjectionRenderer::~ProjectionRenderer(){
    
    
    
}
