//
//  PoliTests.cpp
//  Structs
//
//  Created by Josh Barton on 8/29/23.
//

#include <stdio.h>
#include <iostream>
#include "PoliStructs.hpp"


int main(int argc, const char * argv[]) {
    
    //create a politician struct
    Politician hulkHogan {"Hulk Hogan", "federalCpluser", "Federal"};
    Politician lebronJames {"Lebron James", "javacans", "Federal"};
    Politician patrickMahomes {"Patrick Mahomes", "javacans", "State"};
    Politician taylorSwift {"Taylor Swift", "federalCpluser", "State"};
    
    //create a vector of politicians
    std::vector<Politician> politiciansList = {hulkHogan, lebronJames, patrickMahomes, taylorSwift};
    
    
    //create a series of tests to test Javacans function
    Javacans(politiciansList);
    std::vector javacansList = Javacans(politiciansList);
    
    //test for seeing if Javacans vector is equal to 2.
    if (javacansList.size() == 2) {
        std::cout << "The function worked!" << std::endl;
    } else {
        std::cout << "The function did not work!" << std::endl;
    }
    
    
    //create a series of tests to test federalCplusers function
    federalCplusers(politiciansList);
    std::vector cplusersList = federalCplusers(politiciansList);
    
    //test for seeing if cplusers vector is equal to 2.
    if (cplusersList.size() == 2) {
        std::cout << "The function worked!" << std::endl;
    } else {
        std::cout << "The function did not work!" << std::endl;
    }
    
    return 0;
}
