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

// Brute Force - O(max(a[]) * N)
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalTime(vector<int> &v, int hour)
{
    int totalHour = 0;
    int n = v.size();
    for(int i = 0; i < n; i++)
    {
        totalHour += ceil((double)(v[i]) / (double)(hour));
    }
    return totalHour;
}

int kokoEatingBanana(vector<int> &v, int h)
{
    int maximumele = findMax(v);
    for(int i = 1; i <= maximumele; i++)
    {
        int totalTime = calculateTotalTime(v, i);
        if(totalTime <= h)
        {
            return i;
        }
    }
    return maximumele;
}

// Optimal O(N * log(max(a[])))
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

long long calculateTotalHour(vector<int> &v, int banana)
{
    long long totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(banana));
    }
    return totalH;
}

int kokoEatingBanana(vector<int> &v, int h)
{
    int low = 1;
    int high = findMax(v);
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        long long totalHour = calculateTotalHour(v, mid);
        if(totalHour <= h)
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
        vector<int> v = {7, 15, 6, 3};
        int h = 8;
        int ans = kokoEatingBanana(v, h);
        cout << ans << endl;
    }

    return 0;
}