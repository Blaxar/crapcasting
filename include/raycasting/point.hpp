/* 
 * File:   point.hpp
 * Author: blax
 *
 * Created on January 25, 2014, 4:50 PM
 */

#ifndef POINT_HPP
#define	POINT_HPP

namespace raycasting{

    class Point{

        public:
            
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

};

#endif	/* POINT_HPP */

