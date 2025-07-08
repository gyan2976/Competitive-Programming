#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype> 
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Brute Force Solution
// Time - O(n^3)
// Space - O(1)
int checking(string str) {
    unordered_map<char, int> mp;
    
    // Count character frequencies
    for(char c : str) {
        mp[c]++;
    }
    
    // Handle empty string case
    if(mp.empty()) {
        return 0;
    }
    
    // Find max and min frequencies
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    
    for(const auto& pair : mp) {
        if(pair.second > maximum) {
            maximum = pair.second;
        }
        if(pair.second < minimum) {
            minimum = pair.second;
        }
    }
    
    // Alternative using max_element/min_element:
    // auto max_it = max_element(mp.begin(), mp.end(), 
    //     [](const auto& a, const auto& b) { return a.second < b.second; });
    // auto min_it = min_element(mp.begin(), mp.end(), 
    //     [](const auto& a, const auto& b) { return a.second < b.second; });
    // int maximum = max_it->second;
    // int minimum = min_it->second;
    
    return maximum - minimum;
}

int beautySum(string s)
{
    int n = s.length();
    int sum = 0;
    for(int i = 0; i < n; i++)
    {

        for(int j = i; j < n; j++)
        {
            string ans = s.substr(i, j-i+1);
            sum += checking(ans);
        }
    }
    return sum;
}

// Optimal Solution
// Time - O(n^2)
// Space - O(1)
int beautySum(string s) 
{
    int n = s.length();
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> freq;
        for (int j = i; j < n; ++j) {
            freq[s[j]]++;
            
            int max_freq = 0;
            int min_freq = INT_MAX;
            for (const auto& pair : freq) {
                max_freq = max(max_freq, pair.second);
                min_freq = min(min_freq, pair.second);
            }
            
            sum += (max_freq - min_freq);
        }
    }
    
    return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--)
    {
        string s = "aabcb";
        string s = "aabcbaa";
        int ans = beautySum(s);
        cout << ans << endl;

    }

    return 0;
}