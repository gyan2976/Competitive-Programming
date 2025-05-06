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

// Brute Force - O(N * (sum(arr[])-max(arr[])+1))
int numStudents(vector<int> &bookPages, int pages)
{
    int n = bookPages.size();
    long long totalPages = 0;
    int students = 1;

    for(int i = 0; i < n; i++)
    {
        if(totalPages + bookPages[i] <= pages)
        {
            totalPages += bookPages[i];
        }
        else
        {
            students++;
            totalPages = bookPages[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    if(m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int maximum = accumulate(arr.begin(), arr.end(), 0);

    for(int pages = low; pages <= maximum; pages++)
    {
        if(numStudents(arr, pages) == m)
        {
            return pages;
        }
    }
    return low;
}

// Optimal - O(N * log(sum(arr[])-max(arr[])+1))
int numStudents(vector<int> &bookPages, int pages)
{
    int n = bookPages.size();
    long long totalPages = 0;
    int students = 1;

    for(int i = 0; i < n; i++)
    {
        if(totalPages + bookPages[i] <= pages)
        {
            totalPages += bookPages[i];
        }
        else
        {
            students++;
            totalPages = bookPages[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    if(m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int students = numStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
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
        vector<int> arr = {25, 46, 28, 49, 24};
        int n = 5;
        int m = 4;
        int ans = findPages(arr, n, m);
        cout << ans << endl;
    }

    return 0;
}