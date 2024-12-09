#include <bits/stdc++.h>
using namespace std;
 

int countSubsetSum(vector<int> arr, int sum)
{
    const unsigned int M = 1000000007;
    int n = arr.size();
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));

    t[0][0] = 1;
        
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 0; j < sum + 1; j++)
        {
            if(arr[i - 1] <= j)
                t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % M;
            else 
                t[i][j] = t[i - 1][j];
        }
    }
    
    return t[n][sum];
}


int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    
    if ((d + sum) % 2 != 0 || d > sum) {
        return 0; // Invalid partition
    }
    int s1 = (d + sum) / 2;
    
    return countSubsetSum(arr, s1);
}