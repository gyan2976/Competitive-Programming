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

int findFirst(vector<int>& nums, int target) 
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) 
        {
            ans = mid;  // Possible first occurrence
            high = mid - 1;  // Continue searching in left half
        } else if (nums[mid] < target) 
        {
            low = mid + 1;
        } else 
        {
            high = mid - 1;
        }
    }
    return ans;
}

int findLast(vector<int>& nums, int target) 
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) 
        {
            ans = mid;  // Possible last occurrence
            low = mid + 1;  // Continue searching in right half
        } else if (nums[mid] < target) 
        {
            low = mid + 1;
        } else 
        {
            high = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) 
{
    int f = findFirst(nums, target);
    int l = findLast(nums, target);
    return {f, l};  // Return directly as a vector
    // vector<int> res;
    // res.push_back(f);
    // res.push_back(l);
    // return res;
    
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
        vector<int> nums = {5, 7, 7, 8, 8, 10};
        int target = 7;
        vector<int> result = searchRange(nums, target);
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }

    return 0;
}