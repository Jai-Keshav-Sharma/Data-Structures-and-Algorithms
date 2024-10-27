/**
 * @file permutation_in_string.cpp
 * @brief This file contains the implementation of the Solution class which provides a method to check if one string's permutation is a substring of another string.
 */

/**
 * @class Solution
 * @brief A class to solve the problem of checking if a permutation of one string is a substring of another string.
 */

/**
 * @brief Checks if two integer arrays of size 26 are equal.
 * 
 * @param arr1 The first integer array.
 * @param arr2 The second integer array.
 * @return true if both arrays are equal, false otherwise.
 */
bool checkEqual(int arr1[], int arr2[]);

/**
 * @brief Checks if a permutation of string s1 is a substring of string s2.
 * 
 * This function uses a sliding window approach to compare character counts of substrings of s2 with s1.
 * 
 * @param s1 The string whose permutation is to be checked as a substring.
 * @param s2 The string in which to check for the permutation of s1.
 * @return true if any permutation of s1 is a substring of s2, false otherwise.
 */
bool checkInclusion(string s1, string s2);
class Solution {
public:
    bool checkEqual(int arr1[], int arr2[])
    {
        for(int i = 0; i < 26; i++)
        {
            if(arr1[i] != arr2[i])
            {
                return 0;
            }
        }
        return 1;
    }


    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        for(int i = 0; i < s1.length(); i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int count2[26] = {0};
        int i = 0;
        int windowSize = s1.length();

        //for window 1
        while(i < windowSize and i < s2.length())
        {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if(checkEqual(count1, count2))
        {
            return true;
        }

        //for next windows
        while(i < s2.length()){
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;

            i++;

            if(checkEqual(count1, count2))
            {
                return true;
            }
        }
        return false;
    }
};