//
//  rectangle.hpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

//use so that the rectangle class can see the circle class
class Circle;


class rectangle {
public:
    //rectangle shape
    sf::RectangleShape r_;
    
    //rectangle constructor
    rectangle(sf::Vector2f pos);
    
    void moveRectangle();
    
    void draw(sf::RenderWindow& window) const;
    
    bool shouldDestroy(const sf::RenderWindow& window) const;
    
    friend bool collisions(const Circle& circle, const rectangle& rectangle);
    
private:
    
    float x_;
    float y_;
};


#endif /* rectangle_hpp */
