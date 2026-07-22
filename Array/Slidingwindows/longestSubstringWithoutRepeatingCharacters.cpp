#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> ans;

        int res = INT_MIN;
        int low = 0;

        for (int high = 0; high < n; high++) {
            ans[s[high]]++;
            int k = high - low + 1;

            while (ans.size() < k) {
                ans[s[low]]--;

                if (ans[s[low]] == 0) {
                    ans.erase(s[low]);
                }

                low++;
                k = high - low + 1;
            }

            if (ans.size() == k) {
                res = max(res, high - low + 1);
            }
        }

        return (res == INT_MIN) ? 0 : res;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Length of Longest Substring Without Repeating Characters: "
         << obj.lengthOfLongestSubstring(s) << endl;

    return 0;
}
