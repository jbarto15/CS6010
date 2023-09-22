#include <SFML/Graphics.hpp>
#include "triangle.hpp"
#include "circles.hpp"
#include "rectangle.hpp"
#include "collisions.hpp"
#include <iostream>


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(100);
    
    //boolean values to determine if shapes should be rendered
    bool shouldRenderCircle = true;
    bool shouldRenderRectangle = true;
    
    //boolean value to check the game state
    bool isPlaying = true;

    //create all our circles
    Circle c1, c2, c3, c4, c5;
    //create triangle class
    Triangle t1;

    //seed the time so the circles spawn randomly
    srand(time(0));

    //set the initial postion of all 5 circles
    c1.setInitPos();
    c2.setInitPos();
    c3.setInitPos();
    c4.setInitPos();
    c5.setInitPos();
    //set the initial postion of the test rectangle using Vector2f and getPosition()
    sf::Vector2f t1Pos = t1._triangle.getPosition();
    
    //create movement for the rectangle
    rectangle r1(t1Pos);


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (isPlaying) {
            //create movement for the triangle
            t1.move(window);
            //create movement for the circles
            c1.moveCircle();
            c2.moveCircle();
            c3.moveCircle();
            c4.moveCircle();
            c5.moveCircle();
            
        }
        
        r1.moveRectangle();
        
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        if (shouldRenderCircle) {
            //draw the circles
            window.draw(c1.c_);
            window.draw(c2.c_);
            window.draw(c3.c_);
            window.draw(c4.c_);
            window.draw(c5.c_);
        }
        
        if (shouldRenderRectangle) {
            //draw the rectangles
            window.draw(r1.r_);
        }
        //draw the shape in the window
        window.draw(t1._triangle);
        
        
        //display the window
        window.display();
        
        //call collision function 1
        if (collisions(c1, r1)) {
            c1.c_.setPosition(-1000.f, -1000.f);
            shouldRenderCircle = false;
        }
        
        //call collision function 2
        if (collisions(c1, t1)) {
            c1.c_.setPosition(-1000.f, -1000.f);
            shouldRenderCircle = false;
            isPlaying = false;
        }
    }
    return 0;
}



//int main()
//{
//    //create a window
//    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
//
////    //create window size variable
////    sf::Vector2f windowSize = window.getSize();
//
//    //create window bounds
//    sf::FloatRect windowBounds({0.f, 550.f}, window.getDefaultView().getSize());
//
//    //create triangle object
//    Triangle tri1;
//
//    //create a circle object
//    Circle c1;
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
//        window.draw(tri1._triangle);
//        window.draw(c1.c_);
//
//        //call the move function
//        tri1.move(window);
//
//        // end the current frame
//        window.display();
//
//
//
//
//}
//
//
//
//
//    return 0;
//}
