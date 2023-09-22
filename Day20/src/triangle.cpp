//
//  triangle.cpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#include "triangle.hpp"
#include <iostream>

//constructor
Triangle::Triangle() {
    _triangle.setRadius(25.f);
    _triangle.setPointCount(3);
    _triangle.setPosition(380.f, 550.f);
    _triangle.setFillColor(sf::Color(100, 250, 50));
    _triangle.getPosition();
    sf::FloatRect boundingBox = _triangle.getGlobalBounds();
}

//move method for triangle class
void Triangle::move(sf::RenderWindow& window) {
    
        //most left position
        sf::Vector2f mostLeftPosition = sf::Vector2f(0.f, 550.f);
        
        //most right position
        sf::Vector2f mostRightPosition = sf::Vector2f(750.f, 550.f);
        sf::Vector2f trianglePosition = _triangle.getPosition();
    
        
        //check if left key is pressed, if so, move the triangle
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            //stop the triangle from moving more left if it hits x = 0
            if (trianglePosition.x > mostLeftPosition.x) {
                _triangle.move(-2.0f, 0.f);
            }
        }
        
        //check if right key is pressed, if so, move the triangle
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            //stop the triangle from moving more right if it hits x = 800
            if (trianglePosition.x < mostRightPosition.x) {
                //right key is pressed: move our character
                _triangle.move(2.0f, 0.f);
            }
    }
}

    //reset position method if hit
    void Triangle::resetPosition() {
        //set the position of the triangle
        _triangle.setPosition(380.f, 550.f);
    }


    //get the triangle position
    sf::Vector2f Triangle::getPosition() const {
        //get the triangle position
        return _triangle.getPosition();
}

    //draw function implementation
void Triangle::draw(sf::RenderWindow& window) const {
    window.draw(_triangle);
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //void triangle() {
    //    //create a window
    //    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    //
    //    //create window bounds
    //    sf::FloatRect windowBounds({0.f, 550.f}, window.getDefaultView().getSize());
    //
    //
    //    //create a triangle shape
    //    sf::CircleShape triangle(25.f, 3);
    //
    //    //set the shape color to green
    //    triangle.setFillColor(sf::Color(100, 250, 50));
    //
    //    //create a variable that will store the position of the starting point of the triangle
    //    sf::Vector2f trianglePosition(380.f, 550.f);
    //
    //    //varaible that will store the stop position for triangle on the left side
    //    sf::Vector2f stopLeftPosition(0.f, 550.f);
    //
    //    //varaible that will store the stop position for triangle on the left side
    //    sf::Vector2f stopRightPosition(800.f, 550.f);
    //
    //    //assign triangle position to our stored position variable
    //    triangle.setPosition(trianglePosition);
    //
    //    //opening a window and keep it running as long as its open
    //    while (window.isOpen())
    //    {
    //        //check all the window's events that were triggered since the last iteration of the loop
    //        sf::Event event;
    //        while (window.pollEvent(event))
    //            {
    //            // "close requested" event: we close the window
    //                if (event.type == sf::Event::Closed)
    //                        window.close();
    //                }
    //
    //        // clear the window with black color
    //        window.clear(sf::Color::Black);
    //
    //        //draw the shape in the window
    //        window.draw(triangle);
    //
    //        // end the current frame
    //        window.display();
    //
    //
    //        //check if left key is pressed, if so, move the triangle
    //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //        {
    //            //left key is pressed: move our character
    //            triangle.move(-1.f, 0.f);
    //
    //            //stop the triangle from moving more left if it hits x = 0
    //            if (trianglePosition.x < stopLeftPosition.x) {
    //                //stop triangle from moving more left
    //                triangle.move(stopLeftPosition);
    //            }
    //
    //            //stop the triangle from moving more right if it hits x = 800
    //            if (trianglePosition.x > stopRightPosition.x) {
    //                //stop triangle from moving more right
    //                triangle.move(stopRightPosition);
    //            }
    //        }
    //
    //        //check if right key is pressed, if so, move the triangle
    //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //        {
    //            //right key is pressed: move our character
    //            triangle.move(1.f, 0.f);
    //        }
    //    }
    //
    //
    //}

