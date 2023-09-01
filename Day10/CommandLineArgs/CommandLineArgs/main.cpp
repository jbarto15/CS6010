//
//  main.cpp
//  CommandLineArgs
//
//  Created by Josh Barton on 9/1/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //print out int argc
    std::cout << argc << std::endl;
    
    //print out const char * argv[]
    std::cout <<  * argv << std::endl;
    
    return 0;
}
