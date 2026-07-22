#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {

        // Stores frequency of characters inside current window
        unordered_map<char, int> mp;

        int left = 0;
        int maxLength = INT_MIN;

        // Expand the window
        for (int right = 0; right < s.length(); right++) {

            // Include current character
            mp[s[right]]++;

            // If distinct characters become more than k,
            // shrink the window
            while (mp.size() > k) {

                mp[s[left]]--;

                // Remove character when frequency becomes zero
                if (mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

            // Update answer only when exactly k distinct characters exist
            if (mp.size() == k) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        // If no valid substring exists
        return (maxLength == INT_MIN) ? -1 : maxLength;
    }
};

int main() {

    string s = "aabacbebebe";
    int k = 3;

    Solution obj;

    cout << "Longest Substring Length = "
         << obj.longestKSubstr(s, k);

    return 0;
}
