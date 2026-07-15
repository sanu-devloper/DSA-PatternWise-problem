#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
///  FIRST APPROACH 
vector<int> sortedSquares(vector<int>& nums) {

    vector<int> pos;
    vector<int> neg;

    // Separate positive and negative numbers
    for (int num : nums) {
        if (num < 0)
            neg.push_back(num);
        else
            pos.push_back(num);
    }

    // Square negative numbers
    for (int i = 0; i < neg.size(); i++) {
        neg[i] *= neg[i];
    }

    // Reverse because after squaring,
    // values become decreasing
    reverse(neg.begin(), neg.end());

    // Square positive numbers
    for (int i = 0; i < pos.size(); i++) {
        pos[i] *= pos[i];
    }

    // Merge two sorted arrays
    vector<int> ans;

    int i = 0;
    int j = 0;

    while (i < neg.size() && j < pos.size()) {

        if (neg[i] < pos[j]) {
            ans.push_back(neg[i]);
            i++;
        }
        else {
            ans.push_back(pos[j]);
            j++;
        }
    }

    while (i < neg.size()) {
        ans.push_back(neg[i]);
        i++;
    }

    while (j < pos.size()) {
        ans.push_back(pos[j]);
        j++;
    }

    return ans;
}


/// SECROUND APPROACH

/*
vector<int> sortedSquares(vector<int>& nums) {

    int n = nums.size();

    vector<int> ans(n);

    int left = 0;
    int right = n - 1;

    int index = n - 1;

    while (left <= right) {

        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            ans[index] = leftSquare;
            left++;
        }
        else {
            ans[index] = rightSquare;
            right--;
        }

        index--;
    }

    return ans;
}

*/
int main() {

    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> ans = sortedSquares(nums);

    cout << "Sorted Squares: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}



/*

Complexity Comparison

Approach	                    Time	            Space
Your Split + Merge	            O(n)	            O(n) (three vectors: pos, neg, ans)
Two Pointers	                O(n)	            O(n) (only the output vector)
*/