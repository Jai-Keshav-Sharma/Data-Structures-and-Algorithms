// leetCode 1423. Maximum Points You Can Obtain from Cards

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Calculates the maximum score you can obtain from cards.
     * 
     * This function takes a vector of integers representing card points and an integer k.
     * It calculates the maximum score you can obtain by picking exactly k cards from either
     * the start or the end of the cardPoints vector.
     * 
     * @param cardPoints A vector of integers representing the points of each card.
     * @param k An integer representing the number of cards to pick.
     * @return int The maximum score obtainable by picking k cards from either end of the cardPoints vector.
     */
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();

        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;

        // sum of first k elements from left side in our window
        for (int i = 0; i < k; i++)
        {
            lsum = lsum + cardPoints[i];
        }

        // initialising maxsum with sum of first k elements from left
        maxsum = lsum;

        int rightInd = n - 1;

        for (int i = k - 1; i >= 0; i--)
        {

            // removing the last visited element from left and adding the
            // non-visited element from right
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rightInd];

            rightInd--;

            // updating maxsum
            maxsum = max(maxsum, lsum + rsum);
        }
        return maxsum;
    }
};