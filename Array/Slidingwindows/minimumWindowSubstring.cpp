#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

bool sahi(vector<int> &have, vector<int> &need)
{
    for (int i = 0; i < 256; i++)
    {
        if (have[i] < need[i])
        {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t)
{
    if (s.empty() || t.empty())
    {
        return "";
    }

    vector<int> need(256, 0);
    vector<int> have(256, 0);

    for (char ch : t)
    {
        need[(unsigned char)ch]++;
    }

    int low = 0;
    int start = -1;
    int minLength = INT_MAX;

    for (int high = 0; high < s.length(); high++)
    {
        have[(unsigned char)s[high]]++;

        while (sahi(have, need))
        {
            int currentLength = high - low + 1;

            if (currentLength < minLength)
            {
                minLength = currentLength;
                start = low;
            }

            have[(unsigned char)s[low]]--;
            low++;
        }
    }

    if (start == -1)
    {
        return "";
    }

    return s.substr(start, minLength);
}

int main()
{
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    string ans = minWindow(s, t);

    if (ans.empty())
    {
        cout << "No valid window found." << endl;
    }
    else
    {
        cout << "Minimum Window Substring: " << ans << endl;
    }

    return 0;
}


/*
Enter intput string s: ADOBECODEBANC
Enter intput string t: ABC
Expeacted output Minimum Window Substring: BANC
*/