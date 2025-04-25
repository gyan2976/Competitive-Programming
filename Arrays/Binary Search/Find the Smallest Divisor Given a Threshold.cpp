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

// Brute Force - O(max(arr[])*N), where max(arr[])
int smallestDivisor(vector<int> &nums, int threshold)
{
    int maxi = *max_element(nums.begin(), nums.end());
    
    for(int i = 1; i <= maxi; i++)
    {
        int ans = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            ans += ceil((double)(nums[j]) / (double)(i));
        }
        if(ans <= threshold)
        {
            return i;
        }
        
    }
    return -1;
}

// Optimal - O(log(max(arr[]))*N)
int check(vector<int> &arr, int m)
{
    int n = arr.size(); //size of array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(m));
    }
    return sum;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    if (nums.size() > threshold)
    {
        return -1;
    }

    int maxi = *max_element(nums.begin(), nums.end());
    int low = 1, high = maxi;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(check(nums, mid) <= threshold)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
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
        vector<int> arr = {1, 2, 3, 4, 5};
        int limit = 8;
        int ans = smallestDivisor(arr, limit);
        cout << ans << endl;
    }

    return 0;
}