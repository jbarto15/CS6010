//
//  PoliStructs.cpp
//  Structs
//
//  Created by Josh Barton on 8/29/23.
//

#include "PoliStructs.hpp"

//implementation of Javacans function
std::vector<Politician> Javacans(std::vector<Politician> politicians) {
    std::vector<Politician> politiciansThatAreJavacans = {};
    std::string partyAffiliation = politicians[0].partyAffiliation;
    for (int i = 0; i < politicians.size(); i++) {
        if (partyAffiliation == "javacans" || partyAffiliation == "Javacans") {
            //if partyAffiliation is equal to Javacans, store that politicans info (politicians[i]) in the variable politicians that are Javacans.
            politiciansThatAreJavacans.push_back(politicians[i]);
        }
    }
    return politiciansThatAreJavacans;
}


//implementation of federalCplusers function
std::vector<Politician> federalCplusers(std::vector<Politician> politicians) {
    std::vector<Politician> politiciansThatAreCplusers = {};
    std::string partyAffiliation = politicians[0].partyAffiliation;
    for (int i = 0; i < politicians.size(); i++) {
        if (partyAffiliation == "federalCplusers" || partyAffiliation == "FederalCplusers") {
            //if partyAffiliation is equal to federalCplusers, store that politicans info (politicians[i]) in the variable politicians that are federalCplusers.
            politiciansThatAreCplusers.push_back(politicians[i]);
        }
    }
    return politiciansThatAreCplusers;
}
