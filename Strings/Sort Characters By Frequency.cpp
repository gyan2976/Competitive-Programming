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

// Solution 1 
// Time O(n + k log k)
static bool compare(pair<char, int>&a, pair<char, int>&b)
{
    return a.second > b.second;
}
string frequencySort(string s) 
{

    unordered_map<char, int> freq;
    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch]++;
    }

    vector<pair<char,int>> vec(freq.begin(), freq.end());
    // for (size_t i = 0; i < vec.size(); ++i) 
    // {
    //     cout << "Character: '" << vec[i].first << "', Frequency: " << vec[i].second << endl;
    // }
    // for (const auto& pair : vec) 
    // {
    //     cout << "Character: '" << pair.first << "', Frequency: " << pair.second << endl;
    // }

    sort(vec.begin(),vec.end(), compare);

    string ans = "";
    for(int i = 0; i < vec.size(); i++)
    {
        char ch = vec[i].first;
        int count = vec[i].second;

        for(int i = 0; i < count; i++)
        {
            ans += ch;
        }
    }
    return ans;
}

// Solution 2
string frequencySort(string s) 
{
    // Use a vector of size 128 to cover all ASCII characters
    vector<pair<int, char>> freq(128, {0, 0});
    
    // Count frequencies and store characters
    for (char c : s) {
        freq[c].first++;  // Increment frequency
        freq[c].second = c;  // Store character
    }
    
    // Sort in descending order of frequency
    sort(freq.rbegin(), freq.rend());
    
    // Build the result string efficiently
    string res;
    for (const auto& p : freq) {
        if (p.first > 0) {
            res.append(p.first, p.second);
        }
    }
    return res;
}

// Solution 3
// Bucket Sort - Time O(n), Space O(n)
string frequencySort(const string& s) 
{
    int n = s.size();
    unordered_map<char, int> cnt;
    for (char c : s) cnt[c] += 1;
    
    vector<vector<char>> bucket(n+1);
    for (const auto& pair : cnt)  // Changed from auto [c, f] to const auto& pair
        bucket[pair.second].push_back(pair.first);
    
    string ans;
    for (int freq = n; freq >= 1; --freq)
        for (char c : bucket[freq]) 
            ans.append(freq, c);
    return ans;
}

// Optimal Solution 4
// Heap Sort - Time O(nlogn)
string frequencySort(string s) 
{
    unordered_map<char, int> mp;
    priority_queue< pair<int, char> >pq;

    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }
    for(auto i: mp)
    {
        char c = i.first;
        int freq = i.second;
        pq.push({freq,c});
    }

    string res = "";
    while(!pq.empty())
    {
        auto i = pq.top();
        pq.pop();
        
        res.append(i.first, i.second);
    }
    return res;
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
        string s = "tree";
        string ans = frequencySort(s);
        cout << ans << endl;
    }

    return 0;
}