#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        if (n < k)
            return 0;

        int low = 0;
        int high = k - 1;
        int sum = 0;
        int result = INT_MIN;

        // Calculate the sum of the first window
        for (int i = 0; i <= high; i++) {
            sum += arr[i];
        }

        result = sum;

        // Slide the window
        while (high < n - 1) {
            low++;
            high++;
            sum = sum - arr[low - 1] + arr[high];
            result = max(result, sum);
        }

        return result;
    }
};

int main() {
    Solution obj;

    int n, k;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the window size (k): ";
    cin >> k;

    int ans = obj.maxSubarraySum(arr, k);

    cout << "Maximum sum of a subarray of size " << k << " is: " << ans << endl;

    return 0;
}