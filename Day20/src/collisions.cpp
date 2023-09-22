//
//  collisions.cpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#include "collisions.hpp"
#include "circles.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include <iostream>


bool collisions(Circle& circ, rectangle& rect) {
    //collision detection between circle and rectangle
    if (rect.r_.getGlobalBounds().intersects(circ.c_.getGlobalBounds()))
    {
        std::cout<< "Collision!" << std::endl;
        //erase the circle when it collides with the rectangle by moving it off screen
        circ.eraseCircle();
        return true;
    }
    return false;
}

bool collisions(Circle& circ, Triangle& tri) {
    //collision detection between triangle and circle
    if (tri._triangle.getGlobalBounds().intersects(circ.c_.getGlobalBounds()))
    {
        std::cout<< "Collision!" << std::endl;
        
        //reset triangle position after hit
        tri.resetPosition();
        
        //erase the circle when it collides with the triangle by moving it off screen
        circ.eraseCircle();
        
        return true;
    }
    return false;
}
