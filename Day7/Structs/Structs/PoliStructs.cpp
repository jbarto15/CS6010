//
//  PoliStructs.cpp
//  Structs
//
//  Created by Josh Barton on 8/29/23.
//

#include "PoliStructs.hpp"

//implementation of Javacans function
std::vector<Politician> Javacans(std::vector<Politician> politicians){
    
    std::vector<Politician> politiciansThatAreJavacans = {};
    
    for (int i = 0; i < politicians.size(); i++) {
        if ( politicians[i].partyAffiliation == "javacans" ||  politicians[i].partyAffiliation == "Javacans") {
            //if partyAffiliation is equal to Javacans, store that politicans info (politicians[i]) in the variable politicians that are Javacans.
            politiciansThatAreJavacans.push_back(politicians[i]);
        }
    }
    return politiciansThatAreJavacans;
}


//implementation of federalCplusers function
std::vector<Politician> federalCplusers(std::vector<Politician> politicians) {
    
    std::vector<Politician> politiciansThatAreCplusers = {};
    
    for (int i = 0; i < politicians.size(); i++) {
        if ( politicians[i].partyAffiliation == "federalCpluser" || politicians[i].partyAffiliation == "FederalCpluser") {
            //if partyAffiliation is equal to federalCplusers, store that politicans info (politicians[i]) in the variable politicians that are federalCplusers.
            politiciansThatAreCplusers.push_back(politicians[i]);
        }
    }
    return politiciansThatAreCplusers;
}
