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

//m = no. of boquets
//k = no. of flowers

// Brute Force - O((max(arr[])-min(arr[])+1) * N)
bool check(vector<int> &arr, int n, int day, int k, int m)
{
    int count = 0;
    int numberOfBoquets = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= day)
        {
            count++;
        }
        else
        {
            numberOfBoquets += (count / k);
            count = 0;
        }
    }
    numberOfBoquets += (count / k);
    //return numberOfBoquets >= m;
    if(numberOfBoquets >= m)
    {
        return true;
    }
    return false;
}

int bloomFlowerBouquets(vector<int> &arr, int k, int m)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size();
    if (val > n) 
    {
        return -1;
    }
    
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++) {
        if (check(arr, n, i, m, k))
            return i;
    }
    return -1;
}

bool check(vector<int> &arr, int n, int day, int k, int m)
{
    int count = 0;
    int numberOfBoquets = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= day)
        {
            count++;
        }
        else
        {
            numberOfBoquets += (count / k);
            count = 0;
        }
    }
    numberOfBoquets += (count / k);
    //return numberOfBoquets >= m;
    if(numberOfBoquets >= m)
    {
        return true;
    }
    return false;
}

// Optimal - O(log(max(arr[])-min(arr[])+1) * N)
bool check(vector<int> &a, int day, int m, int k) 
{
    int bouquets = 0, flowers = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= day) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
    }
    return bouquets >= m;
}

int bloomFlowerBouquets(vector<int> &arr, int k, int m)
{
    long long val = 1LL * m * k;
    int n = arr.size();
    if (val > n) 
    {
        return -1;
    }
    
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int low = mini, high = maxi;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if(check(arr, mid, m, k)) 
        {
            high = mid - 1;
        }
        else low = mid + 1;
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
        vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
        int k = 3;
        int m = 2;
        int ans = bloomFlowerBouquets(arr, k, m);
        cout << ans << endl;
    }

    return 0;
}