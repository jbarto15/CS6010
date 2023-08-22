//
//  main.cpp
//  RoadTripCalculator
//
//  Created by Josh Barton on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // create driving distance, vehicle miles per gallon efficiency, and cost of gas in dollars per gallon variables.
    float drivingDistance;
    float vehicleMilesPerGallonEfficiency;
    float costOfGas;
    
    // Prompt the user to enter value for driving distance and then ask for that input
    std::cout << "Enter Driving Distance: ";
    std::cin >> drivingDistance;
    
    /* Prompt the user to enter value for vehicle efficiency in miles per gallon and then ask for that input*/
    std::cout << "Vehicle Efficiency in Miles per Gallon: ";
    std::cin >> vehicleMilesPerGallonEfficiency;
    
    // Prompt the user to enter value for cost of gas in dollars per gallon and then ask for that input
    std::cout << "Cost of Gas: ";
    std::cin >> costOfGas;
    
    /* create number of gallons used variable which is equivalent to vehicle miles per gallon divided by the driving distance */
    float numberOfGallonsUsed = vehicleMilesPerGallonEfficiency / drivingDistance;
    
    /* create final cost variable which is equal to the number of gallons used multiplied by the cost of gas */
    float finalCost = numberOfGallonsUsed * costOfGas;
    
    // show user the final cost by printing the final cost variable
    std::cout << "Final Cost: ";
    std::cout << finalCost;
    
    return 0;
}
