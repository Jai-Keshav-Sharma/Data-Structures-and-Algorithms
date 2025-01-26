// LeetCode 134. Gas Station

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Determines the starting gas station index from which a car can complete a circuit.
 * 
 * Given two integer vectors, gas and cost, this function calculates if there is a starting gas station index
 * from which a car can complete a circuit around all gas stations. The car can travel from station i to station i+1
 * if it has enough gas to cover the cost. The car starts with an empty tank.
 * 
 * @param gas A vector of integers where gas[i] is the amount of gas available at the i-th station.
 * @param cost A vector of integers where cost[i] is the amount of gas required to travel from the i-th station to the (i+1)-th station.
 * @return int The starting gas station index if the car can complete the circuit, otherwise -1.
 */
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int N = gas.size();
    int deficit = 0; 
    int balance = 0;
    int start = 0;

    for (int i = 0; i < N; i++)
    {
        balance = balance + gas[i] - cost[i];

        if (balance < 0)
        {
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (balance + deficit >= 0)
        return start;

    return -1;
}