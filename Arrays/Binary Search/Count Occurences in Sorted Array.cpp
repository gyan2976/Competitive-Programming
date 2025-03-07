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

// Brute Force O(N)
int countOccurence(vector<int> &arr, int n, int x)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            count += 1;
        }
    }
    return count;
}

// Optimal O(2 * logN) -> Same as first and last occurence 
// count = last - first + 1
int getFirst(vector<int> &arr, int n, int x)
{
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            ans = mid;
            high = mid - 1;     // Look left side
        }
        else if(arr[mid] < x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int getLast(vector<int> &arr, int n, int x)
{
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            ans = mid;
            low = mid + 1;     // Look right side
        }
        else if(arr[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int countOccurence(vector<int> &arr, int n, int x)
{
    int f = getFirst(arr, n, x);
    int l = getLast(arr, n, x);
    cout << f << " " << l << endl;
    int res = l - f + 1;
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
        vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
        int n = 8, x = 8;
        int ans = countOccurence(arr, n, x);
        cout << ans << endl;   
    }

    return 0;
}