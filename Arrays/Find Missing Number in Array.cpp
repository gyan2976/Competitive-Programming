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

void missingNumber(int *arr, int n)
{
    cout << "Missing Numbers: ";
    
    int hash[n+1] = {0};
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for(int i = 1; i <= n; i++)
    {
        if(hash[i] == 0)
        {
            cout << i << " ";
        }
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
        int n = 5;
        int arr[] = {1, 2, 4, 5};

        missingNumber(arr, n);
    }

    return 0;
}