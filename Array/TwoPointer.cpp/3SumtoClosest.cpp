#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // Update closest sum if current sum is closer
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                // If exact target is found
                if (sum == target) {
                    return sum;
                }
                // Move pointers
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << sol.threeSumClosest(nums, target) << endl;

    return 0;
}