//
//  circles.cpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#include "circles.hpp"


//circle constructor
Circle::Circle() {
    c_.setRadius(15);
    c_.setFillColor(sf::Color(0, 100, 200));
    c_.setOutlineThickness(1.f);
    c_.setOutlineColor(sf::Color(0, 100, 200));
    sf::FloatRect boundingBoxRect = c_.getGlobalBounds();
    shouldRender = true;
    x_ = 0;
    y_ = 0;
}

//sets the initial position randomly on the x axis
//set the circle close to the top of the y axis
void Circle::setInitPos() {
    // Seed the random number generator with a value (e.g., time)
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    x_ = rand() % 800;
    y_ = 50;
    c_.setPosition(x_, y_);
}

void Circle::moveCircle(){
    c_.move(0, 1);
}

//erase circle implementation
void Circle::eraseCircle() {
    shouldRender = false;
}

//restore the circle's rendering
void Circle::restoreCircle() {
    shouldRender = true;
}
