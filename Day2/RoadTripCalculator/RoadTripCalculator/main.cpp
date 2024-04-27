//
//  main.cpp
//  RoadTripCalculator
//
//  Created by Josh Barton on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    // create driving distance, vehicle miles per gallon efficiency, and cost of gas in dollars per gallon variables.
    float driving_distance;
    float vehicle_miles_per_gallon_efficiency;
    float cost_of_gas;
    
    // Prompt the user to enter value for driving distance and then ask for that input
    std::cout << "Enter Driving Distance: ";
    std::cin >> driving_distance;
    
    /* Prompt the user to enter value for vehicle efficiency in miles per gallon and then ask for that input*/
    std::cout << "Vehicle Efficiency in Miles per Gallon: ";
    std::cin >> vehicle_miles_per_gallon_efficiency;
    
    // Prompt the user to enter value for cost of gas in dollars per gallon and then ask for that input
    std::cout << "Cost of Gas: ";
    std::cin >> cost_of_gas;
    
    /* create number of gallons used variable which is equivalent to vehicle miles per gallon divided by the driving distance */
    float number_of_gallons_used = driving_distance / vehicle_miles_per_gallon_efficiency;
    
    /* create final cost variable which is equal to the number of gallons used multiplied by the cost of gas */
    float final_cost = number_of_gallons_used * cost_of_gas;
    
    // show user the final cost by printing the final cost variable
    std::cout << "Final Cost: ";
    std::cout << final_cost;
    
    return 0;
}
