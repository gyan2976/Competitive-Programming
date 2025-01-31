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

// 1. Brute Force O(n^3)
vector<vector<int>> threeSumProblem(vector<int> &arr)
{
    int n = arr.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    // Store all list of set in ans [[], [], []]
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Hashing O(n^2 * log(unique variables))
// Logic:
// arr[i] + arr[j] + ar[k] == 0
// arr[k] = -(arr[j] + arr[k])
vector<vector<int>> threeSumProblem(vector<int> &arr)
{
    int n = arr.size();
    set<vector<int>> st;
    for(int i = 0; i < n; i++)
    {
        set<int> hashset;
        for(int j = i+1; j < n; j++)
        {
            int x = -(arr[i] + arr[j]);
            if(hashset.find(x) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], x};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    // Store all list of set in ans [[], [], []]
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimal - Two Pointers O(n + n)
vector<vector<int>> threeSumProblem(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
    {
        if(i != 0 && arr[i] == arr[i-1])
        {
            continue;
        }

        int j = i+1;
        int k = n-1;
        while(j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j < k && arr[j] == arr[j-1])
                {
                    j++;
                }

                while(j < k && arr[k] == arr[k-1])
                {
                    k--;
                }
            }
        }
        
    }

    return ans;
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
        vector<int> arr = {-1, 0, 1, 2, -1, -4, -3, 2, -2, 1, 0};
        vector<vector<int>> ans = threeSumProblem(arr);

        cout << "Triplets that add up to zeros are: " << endl;
        for(auto it: ans)
        {
            for(auto ele: it)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }

    return 0;
}