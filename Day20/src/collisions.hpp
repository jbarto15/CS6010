//
//  collisions.hpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#ifndef collisions_hpp
#define collisions_hpp

#include <stdio.h>

#include "circles.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

bool collisions(Circle& circ, rectangle& rect);

bool collisions(Circle& circ, Triangle& tri);



#endif /* collisions_hpp */
