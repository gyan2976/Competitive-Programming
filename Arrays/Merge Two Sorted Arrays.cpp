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

// 1. Brute Force O(m+n) + O(m+n) [Extra Space]
void mergeSortedArrays(long long *arr1, int m, long long *arr2, int n)
{
    long long arr3[m+n];
    int left = 0;
    int right = 0;
    int index = 0;

    while(left < m && right < n)
    {
        if(arr1[left] <= arr2[right])
        {
            arr3[index++] = arr1[left++];
        }
        else
        {
            arr3[index++] = arr2[right++];
        }
    }

    while(left < m)
    {
        arr3[index++] = arr1[left++];
    }

    while(right < n)
    {
        arr3[index++] = arr2[right++];
    }

    // Put back sorted elements back in arrays
    for(int i = 0; i < m+n; i++)
    {
        if(i < m)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i-m] = arr3[i];
        }
    }
}

// 2. Optima 1 - O(min(n, m)) + O(n*logn) + O(m*logm)
void mergeSortedArrays(long long *arr1, int m, long long *arr2, int n)
{
    // Swap and Sort
    int left = m-1;
    int right = 0;

    while(left >= 0 && right < n)
    {
        if(arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1, arr1+m);
    sort(arr2, arr2+n);
}

// 3. Optimal 2 - O((n+m)*log(n+m))
// Using Gap Method - Shell Short
void swapIfGreater(long long arr1[], int ind1, long long arr2[], int ind2) 
{
    if (arr1[ind1] > arr2[ind2]) 
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void mergeSortedArrays(long long arr1[], int m, long long arr2[], int n) 
{
    int len = m + n;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) 
    {
        int left = 0;
        int right = left + gap;
        while (right < len) 
        {
            if (left < m && right >= m) 
            {
                swapIfGreater(arr1, left, arr2, right - m);
            }
            else if (left >= m) 
            {
                swapIfGreater(arr2, left - m, arr2, right - m);
            }
            else 
            {
                swapIfGreater(arr1, left, arr1, right);
            }
            left++, right++;
        }
        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
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
        long long arr1[] = {1, 4, 8, 10};
        long long arr2[] = {2, 3, 9};
        int m = 4, n = 3;
        mergeSortedArrays(arr1, m, arr2, n);

        for(auto it: arr1)
        {
            cout << it << " ";
        }

        cout << endl;

        for(auto second: arr2)
        {
            cout << second << " ";
        }
    }

    return 0;
}