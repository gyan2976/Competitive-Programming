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

vector<int> majorityElement(vector<int> &arr)
{
    int n = arr.size();
    int k = n/3;

    vector<int> list;

    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for(auto it: mp)
    {
        if(it.second > k)
        {
            list.push_back(it.first);
        }
    }

    return list;
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
        vector<int> arr = {11, 33, 33, 11, 33, 11};
        vector<int> ans = majorityElement(arr);

        for(auto it: ans)
        {
            cout << it << " ";
        }
    }

    return 0;
}