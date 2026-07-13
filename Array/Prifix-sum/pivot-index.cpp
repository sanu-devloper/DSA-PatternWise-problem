#include <iostream>
#include <vector>
using namespace std;
int findPivotIndex(vector<int>&arr)
{
    int n = arr.size();
    int sum = 0;
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int right = sum - arr[i] - left;

        if (left == right)
        {
            return i;
        }

        left += arr[i];
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 7, 3, 6, 5, 6};
    // int size = 6;
    /*
    The pivot index is 3.
      Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
      Right sum = nums[4] + nums[5] = 5 + 6 = 11
    */
    int result = findPivotIndex(arr);

    cout << "The pivot index is" << " " << result << endl;
}