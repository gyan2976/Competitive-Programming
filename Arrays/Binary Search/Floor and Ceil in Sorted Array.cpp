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

int findFloor(int* arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;
    
        if (arr[mid] <= x) 
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(int* arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;
    
        if (arr[mid] >= x) 
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;            
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int* arr, int n, int x)
{
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return make_pair(f, c);
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
        int n = 6;
        int arr[] = {3, 4, 4, 7, 8, 10};
        int x = 5;
        pair<int, int> ans = getFloorAndCeil(arr, n, x);

        cout << "Floor: " << ans.first << " " << "Ceil: " << ans.second << endl;

    }

    return 0;
}