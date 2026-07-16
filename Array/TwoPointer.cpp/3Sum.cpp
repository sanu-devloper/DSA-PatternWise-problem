#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            // here we calculate the two sum for each arr[i]
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate values for left
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate values for right
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = sol.threeSum(nums);

    for (auto &triplet : result) {
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}