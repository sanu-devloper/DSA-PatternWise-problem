#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {

    vector<int> ans;
    int sum = 0;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        ans.push_back(sum);
    }

    return ans;

    // INPACE SOLUTION
        // for(int i=1;i<nums.size();i++){
        //     nums[i]+=nums[i-1];
        // }
        // return nums;
}

int main() {

    vector<int> nums = {1,2,3,4};

    vector<int> ans = runningSum(nums);

    for(int x : ans)
        cout << x << " ";

    return 0;
}