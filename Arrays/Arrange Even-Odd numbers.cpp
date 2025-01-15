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

// Input: 1 2 3 4 5 6 7 3 9 5
// Output: 2 4 6 1 3 5 7 3 9 5 

void arrangeEvenOdd(int *arr, int n)
{

    int start = 0;
    int end = n-1;
    int index = 0;
    
    // Create a temporary array to store the result
    int temp[n];

    // Collect even numbers first
    while (start <= end) 
    {
        if (arr[start] % 2 == 0) 
        {
            temp[index++] = arr[start];
        }
        start++;
    }

    // Reset start pointer for odd number collection
    start = 0;

    // Collect odd numbers
    while (start <= end) 
    {
        if (arr[start] % 2 != 0) 
        {
            temp[index++] = arr[start];
        }
        start++;
    }

    // Copy temp array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        arrangeEvenOdd(arr, n);

    }

    return 0;
}