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

// 1. Third Largest
void thirdLargest(int *arr, int n)
{
    
    if(n < 3)
    {
        cout << -1;
    }

    int largest = INT_MIN, secondLargest = INT_MIN, thirdLargest = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest)
        {
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        }
        else if(arr[i] > thirdLargest)
        {
            thirdLargest = arr[i];
        }
    }

    cout << thirdLargest;
}

// 2. Third Smallest
void thirdSmallest(int *arr, int n)
{
    
    if(n < 3)
    {
        cout << -1;
    }

    int first = INT_MAX, second = INT_MAX, third = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if(arr[i] < second)
        {
            third = second;
            second = arr[i];
        }
        else if(arr[i] < third)
        {
            third = arr[i];
        }
    }

    cout << third;
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
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        thirdLargest(arr, n);

        thirdSmallest(arr, n);

    }

    return 0;
}