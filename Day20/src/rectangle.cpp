//
//  rectangle.cpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#include "rectangle.hpp"

//Constructor
rectangle::rectangle(sf::Vector2f pos) {
    r_.setSize(sf::Vector2f(2, 12));
    r_.setOutlineColor(sf::Color::Transparent);
    r_.setOutlineThickness(1);
    r_.setOutlineColor(sf::Color::White);
    sf::FloatRect boundingBox = r_.getGlobalBounds();
    x_ = pos.x;
    y_ = pos.y;
    r_.setPosition(x_, y_);

}

//uses the already existing move function
void rectangle::moveRectangle() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        r_.move(0, -3.0);
    }
    
}
