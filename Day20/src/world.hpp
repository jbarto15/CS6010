//
//  world.hpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#ifndef world_hpp
#define world_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "triangle.hpp"
#include "circles.hpp"

class World {
public:
    World()
    :window(sf::VideoMode(800, 600), "Galaga")
    {
        reset();
    }
    
    void loop();

private:
    
    void draw();

    void shoot();

    void reset();

    void handleCollisions();


    sf::RenderWindow window;
    
    Triangle triangle;

    std::vector<Circle> circles;

    //std::vector<rectangle> rectangles;

};





#endif /* world_hpp */
