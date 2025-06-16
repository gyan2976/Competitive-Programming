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

// Brute Force - O(n1 + n2)
// Space Complexity - O(n1+n2) Extra array space is taken to store elements
double median(vector<int>& a, vector<int>& b)
{
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            arr3.push_back(a[i++]);
        }
        else
        {
            arr3.push_back(b[j++]);
        }
    }

    //copy the left-out elements:
    if(i < n1) arr3.push_back(a[i++]);
    if(j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if(n%2 == 1)    // Odd 
    {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;    // Even
    return median;
}

// Better - O(n1+n2)
// Space Complexity - O(1)
double median(vector<int>& a, vector<int>& b)
{
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size

    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

// Optimal - O(log(min(n1,n2)))
// Space Complexity - O(1)
double median(vector<int>& a, vector<int>& b)
{
    int n1 = a.size();
    int n2 = b.size();

    if(n1 > n2) return median(b, a);

    // Always perfom binary search on smaller array
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2; // number of elements required on left

    int n = n1 + n2;
    while(low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1)
        {
            // Odd n case
            if(n%2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
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
        vector<int> a = {1, 4, 7, 10, 12};
        vector<int> b = {2, 3, 6, 15};
        cout << "Median of 2 sorted array is: " << fixed << setprecision(1) << median(a, b);
    }

    return 0;
}