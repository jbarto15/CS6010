//
//  circles.hpp
//  testSFML
//
//  Created by Josh Barton on 9/20/23.
//

#ifndef circles_hpp
#define circles_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>


//create a circle class
class Circle {
public:
    //this circle class uses the already existing circle class
    sf::CircleShape c_;
    //rendering flag
    bool shouldRender;
    
    //circle constructor that details radius, color, and outline
    Circle();
    
    //set initial position
    void setInitPos();
    
    //create movement
    void moveCircle();
    
    //get the position of the circle so we can use SFML get position
    
    //erase circle method using set position
    void eraseCircle();
    
    //restore the circle's rendering
    void restoreCircle();
    
private:
    //saves the position of the circle
    float x_;
    float y_;
    
};




#endif /* circles_hpp */
