#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0;
        int sum = 0;
        int res = INT_MAX;

        while (high < n) {
            sum += nums[high];

            while (sum >= target) {
                res = min(res, high - low + 1);
                sum -= nums[low];
                low++;
            }

            high++;
        }

        if (res == INT_MAX){
            return 0;
        }else{
            return res;
        }
       // return (res == INT_MAX) ? 0 : res;
    }
};

int main() {
    Solution obj;

    int target, n;

    cout << "Enter target: ";
    cin >> target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = obj.minSubArrayLen(target, nums);

    cout << "Minimum subarray length: " << ans << endl;

    return 0;
}