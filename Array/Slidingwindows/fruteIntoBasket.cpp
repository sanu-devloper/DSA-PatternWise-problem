#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // Stores the frequency of each fruit type in the current window
        unordered_map<int, int> basket;

        int left = 0;
        int maxFruits = 0;

        // Expand the sliding window
        for (int right = 0; right < fruits.size(); right++) {

            // Add the current fruit
            basket[fruits[right]]++;

            // If more than 2 fruit types exist, shrink the window
            while (basket.size() > 2) {

                basket[fruits[left]]--;

                // Remove fruit type if its count becomes zero
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);

                left++;
            }

            // Update the maximum number of fruits collected
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};

int main() {

    // Example Input
    vector<int> fruits = {1, 2, 3, 2, 2};

    Solution obj;

    cout << "Maximum Fruits Collected: "
         << obj.totalFruit(fruits) << endl;

    return 0;
}

/*
  Think this question in way like
  -->> find the longest subarray which has at most 2 duplicate number 
*/