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

void printAllSubarray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            cout << "[";
            for(int s = i; s <= j; ++s)
            {
                cout << arr[s];
                if(s < j)
                {
                    cout << ", ";
                }
            }
            cout << "]\n" ;
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
        int arr[] = {2, 3, 5, 1, 9};

        printAllSubarray(arr, n);
    }

    return 0;
}
