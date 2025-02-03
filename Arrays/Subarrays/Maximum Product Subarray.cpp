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
int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int product = 1;
            for(int k = j; k < n; k++)
            {
                product = product * nums[k];
            }

            maximum = max(maximum, product);
        }
    }
    return maximum;
}

// 2. Optimal O(n)
int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        return nums[0];
    }
    int prefix = 1, suffix = 1;
    int maximum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(prefix == 0)
        {
            prefix = 1;
        }

        if(suffix == 0)
        {
            suffix = 1;
        }

        prefix = prefix * nums[i];
        suffix = suffix * nums[n-i-1];

        maximum = max(maximum, max(prefix, suffix));
    }

    return maximum;
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
        vector<int> nums = {1,2,-3,0,-4,-5};

        int ans = maximumProduct(nums);
        cout << "The maximum product of subarray is: " << ans << endl;
    }

    return 0;
}