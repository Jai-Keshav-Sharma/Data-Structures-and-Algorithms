// LeetCode 632. Smallest Range Covering Elements from K Lists

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        int row;
        int col;
    
        Node(int data, int row, int col) {
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };
    
    class compare {
    public:
        bool operator()(Node* a, Node* b) { return a->data > b->data; }
    };
    
    class Solution {
    public:
        /**
         * @brief Finds the smallest range that includes at least one number from each of the k lists.
         * 
         * This function takes a vector of k sorted lists and returns the smallest range [minValue, maxValue]
         * that includes at least one number from each of the k lists.
         * 
         * @param nums A vector of k sorted lists.
         * @return A vector containing two integers representing the smallest range [minValue, maxValue].
         */
        vector<int> smallestRange(vector<vector<int>>& nums) {
            priority_queue<Node*, vector<Node*>, compare> minh;
            vector<int> ans;
            int mini = INT_MAX; // tracks minimum value
            int maxi = INT_MIN; // tracks maximum value
            int diff = INT_MAX; // answer range diff
    
            int minValue; // lower limit of answer range
            int maxValue; // upper limit of answer range
    
            // pushing list Nodes intp the heap and keeping track of the maximum
            // value among all lists
            for (int i = 0; i < nums.size(); i++) {
                Node* temp = new Node(nums[i][0], i, 0);
    
                // updating maxi
                maxi = max(maxi, nums[i][0]);
    
                minh.push(temp);
            }
    
            while (!minh.empty()) {
                Node* temp = minh.top();
                minh.pop();
    
                mini = temp->data;
    
                // current range
                int currDiff = maxi - mini;
                // updating answer range if current range is smaller;
                // in case an equal range is found, this code works as the latter
                // range will definitely have higher ans[0](i.e. lower limit of
                // range) as we are always increasing the lower limit of range hence
                // the new range will not be stored in case of equal ranges
                if (currDiff < diff) {
                    minValue = mini;
                    maxValue = maxi;
    
                    // updating answer range diff
                    diff = currDiff;
                }
    
                int row = temp->row;
                int col = temp->col;
    
                // pushing next value of current list if present
                if (col + 1 < nums[row].size()) {
                    Node* newNode = new Node(nums[row][col + 1], row, col + 1);
    
                    maxi = max(maxi, newNode->data);
    
                    minh.push(newNode);
                } else { // if any list is exhausted, we are done
                    break;
                }
            }
            // framing the answer
            ans.push_back(minValue);
            ans.push_back(maxValue);
            return ans;
        }
    };