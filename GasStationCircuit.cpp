//There are some gas stations along a circular route. 
//You are given two integer arrays gas[] denoted as the amount of gas present at each station and cost[] denoted as the cost of travelling to the next station. 
//You have a car with an unlimited gas tank. You begin the journey with an empty tank from one of the gas stations.
//Return the index of the starting gas station if it's possible to travel around the circuit without running out of gas at any station in a clockwise direction.
//If there is no such starting station exists, return -1.
//Note: If a solution exists, it is guaranteed to be unique.


class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
         int total_gas = 0, total_cost = 0, start_index = 0, current_gas = 0;

        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_gas += gas[i] - cost[i];

            // If at any point current gas becomes negative, reset the start index
            if (current_gas < 0) {
                start_index = i + 1;
                current_gas = 0;
            }
        }

        return (total_gas >= total_cost) ? start_index : -1;      
    }
};
