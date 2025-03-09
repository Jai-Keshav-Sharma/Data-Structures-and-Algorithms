#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Calculates the minimum cost to join all ropes into one rope.
 * 
 * This function takes a vector of integers representing the lengths of ropes 
 * and returns the minimum cost required to join all the ropes into one rope. 
 * The cost to join two ropes is equal to the sum of their lengths.
 * 
 * @param arr A vector of integers representing the lengths of the ropes.
 * @return int The minimum cost to join all the ropes into one rope.
 */
int minCost(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> v;
    int cost = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        minh.push(arr[i]);
    }

    while (!minh.empty())
    {
        int sum = minh.top();
        minh.pop();

        if (minh.empty())
        {
            break;
        }

        sum += minh.top();
        minh.pop();

        minh.push(sum);
        cost += sum;
    }
    return cost;
}
