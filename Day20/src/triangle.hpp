//
//  triangle.hpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#ifndef triangle_hpp
#define triangle_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

//create class called triangle that will act as our player
class Triangle {
private:


public:
    
    //create a triangle shape
    sf::CircleShape _triangle;
    
    //constructor
    Triangle();

    //need a move method
    void move(sf::RenderWindow& window);

    //need a draw method
    void draw(sf::RenderWindow& window) const;

    //reset position if hit
    void resetPosition();
    
    //get the triangle position
    sf::Vector2f getPosition() const;

    //fire a rectangle from the front of the ship
    //Rectangle makeRectangle() const;

    //create a friend variable that will help with collisions
    //friend bool collides(const Triangle& triangle, const Circle& circle);

};






//void triangle();



#endif /* triangle_hpp */
