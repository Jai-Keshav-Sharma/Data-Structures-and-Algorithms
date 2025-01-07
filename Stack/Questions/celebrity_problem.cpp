/**
 * @file celebrity_problem.cpp
 * @brief Implementation of the Celebrity Problem using different approaches.
 *
 * This file contains the implementation of the Celebrity Problem using three different approaches:
 * 1. Better Approach using a stack.
 * 2. Optimal Approach 1 using a single pass to find the potential celebrity.
 * 3. Optimal Approach 2 using two pointers to find the potential celebrity.
 *
 * The Celebrity Problem is to find the celebrity in a party where a celebrity is defined as someone who:
 * - Everyone knows them.
 * - They know no one.
 *
 * The input is a matrix where mat[i][j] = 1 means person i knows person j, and mat[i][j] = 0 means person i does not know person j.
 */

 /**
 * @brief Checks if person 'a' knows person 'b'.
 * 
 * @param a The index of the first person.
 * @param b The index of the second person.
 * @param mat The matrix representing the knowledge of people.
 * @return true if person 'a' knows person 'b', false otherwise.
 */

/**
 * @brief Finds the celebrity in the party using the Optimal Approach 2.
 * 
 * @param mat The matrix representing the knowledge of people.
 * @return The index of the celebrity if one exists, otherwise -1.
 */


#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int>> &mat)
{
    if (mat[a][b] == 1)
        return true;
    return false;
}

// Better Approach
/*
    int celebrity(vector<vector<int> >& mat) {
        int n = mat[0].size();

        if(n == 1)
            return 0;

        stack<int> st;

        for(int i = 0; i < n; i++) {
            st.push(i);
        }

        while(st.size() > 1) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if(mat[a][b] == 1)
                st.push(b);
            else if(mat[b][a] == 1) {
                st.push(a);
            }
        }

        int mayBeCeleb = st.top();

        for(int i = 0; i < n; i++) {
            if(i != mayBeCeleb) {
                if(mat[mayBeCeleb][i] == 1 || mat[i][mayBeCeleb] == 0)
                    return -1;
            }
        }

        return mayBeCeleb;
    }
*/

/*-------------------------------------------------------------*/

// Optimal Apporach 1
/*
    int celebrity(vector<vector<int> >& mat) {
        int n = mat[0].size();

        if(n == 1)
            return 0;

        int mayBeCeleb = 0;

        for(int i = 1; i < n; i++) {
            if(knows(mayBeCeleb, i, mat)) {
                mayBeCeleb = i;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i != mayBeCeleb) {
                if(mat[mayBeCeleb][i] == 1 || mat[i][mayBeCeleb] == 0)
                    return -1;
            }
        }
        return mayBeCeleb;
    }
*/

/*-------------------------------------------------------------*/

// Optimal Approach 2

int celebrity(vector<vector<int>> &mat)
{
    int n = mat[0].size();

    if (n == 1)
        return 0;

    int top = 0;
    int down = n - 1;

    while (top < down)
    {
        if (mat[top][down] == 1)
            top++;
        else if (mat[down][top] == 1)
            down--;
        else
        {
            top++;
            down--;
        }
    }

    if (top > down)
        return -1;

    int mayBeCeleb = top;

    for (int i = 0; i < n; i++)
    {
        if (i != mayBeCeleb)
        {
            if (mat[mayBeCeleb][i] == 1 || mat[i][mayBeCeleb] == 0)
                return -1;
        }
    }
    return mayBeCeleb;
}
