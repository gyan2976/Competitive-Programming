#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 1. Brute Force - Linear Search O(n^2)
bool linearSearch(vector<int> &a, int num)
{
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}

int longestConsecutiveSequence(vector<int> &a)
{
    int n = a.size();
    int longest = 1;

    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        int count = 1;

        while(linearSearch(a, x+1) == true)
        {
            x += 1;
            count += 1;
        }

        longest = max(longest, count);
    }

    return longest;
}

// 2. Better - Sorting O(n* nlog(n))
int longestConsecutiveSequence(vector<int> a)
{
    int n = a.size();
    if(n == 0)
    {
        return 0;
    }

    sort(a.begin(), a.end());

    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++) 
    {
        if (a[i] - 1 == lastSmaller) 
        {
            cout << "y: " << a[i] << endl;
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) 
        {
            cout << "n: " << a[i] << endl;
            cnt = 1;
            lastSmaller = a[i];
        }

        longest = max(longest, cnt);
    }

    return longest;
}

// 3. Optimal - Set O(n)
int longestConsecutiveSequence(vector<int> &a)
{
    int n = a.size();
    if(n == 0)
    {
        return 0;
    }

    int longest = 1;

    unordered_set<int> st;
    for(int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    for(auto it: st)
    {
        if(st.find(it-1) == st.end())
        {
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end())
            {
                x = x + 1;
                count = count + 1;
            }
            longest = max(longest, count);
        }
    }

    return longest;
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
        vector<int> a = {100, 200, 1, 2, 3, 4};
        int ans = longestConsecutiveSequence(a);
        cout << "The longest consecutive sequence is: " << ans << endl;
    }

    return 0;
}