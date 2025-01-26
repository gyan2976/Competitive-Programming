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

// Brute Force O(n^3)
void KadensAlgorithm(int *arr, int n) 
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            int sum = 0;
            for(int k = i; k <= j; k++)
            {
                sum += arr[k];
                maxi = max(maxi, sum);
            }
        }
    }

    cout << "Subarray with Maximum Sum is: " << maxi << endl;
}

// O(n^2)
void KadensAlgorithm(int *arr, int n) 
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) 
    {
        int sum = 0;
        for (int j = i; j < n; j++) 
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }

    cout << "Subarray with Maximum Sum is: " << maxi << endl;
}

// Optimal O(n)
void KadensAlgorithm(int *arr, int n) 
{
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < n; i++) 
    {
        currentSum += arr[i];

        if(currentSum > maxSum)
        {
            maxSum = currentSum;
        }

        if(currentSum < 0)
        {
            currentSum = 0;
        }

    }

    cout << "Subarray with Maximum Sum is: " << maxSum<< endl;
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
        int n = 7;
        int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

        KadensAlgorithm(arr, n);
    }

    return 0;
}