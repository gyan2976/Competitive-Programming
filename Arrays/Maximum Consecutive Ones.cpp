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

void countConsecutiveOnes(int *arr, int n)
{
    int count = 0;
    int maximum = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        maximum = max(maximum, count);
    }

    cout << "Maximum Count of 1's: " << maximum << endl;
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
        int arr[] = {1, 0, 1, 1, 0, 1};

        countConsecutiveOnes(arr, n);
    }

    return 0;
}