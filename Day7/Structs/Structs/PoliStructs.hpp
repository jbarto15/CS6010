//
//  PoliStructs.hpp
//  Structs
//
//  Created by Josh Barton on 8/29/23.
//

#ifndef PoliStructs_hpp
#define PoliStructs_hpp

#include <stdio.h>
#include <string>

//create struct for Politicians.
struct Politician {
    std::string name;
    std::string partyAffiliation;
    std::string typeOfPolitician;
};

//create Javacans function
std::vector<Politician> Javacans(std::vector<Politician> politicians);

//create federalCplusers function
std::vector<Politician> federalCplusers(std::vector<Politician> politicians);

#endif /* PoliStructs_hpp */
