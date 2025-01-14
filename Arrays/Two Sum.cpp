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
using namespace std;

void twoSum(int *arr, int n, int sum)
{
    for(int i = 0; i < n-1; i++)
    {
       for(int j = i+1; j < n; j++)
       {
            if(arr[i] + arr[j] == sum)
            {
                cout << arr[i] << " " << arr[j] << endl;
                break;
            }
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
        int n, sum;
        cin >> n >> sum;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        twoSum(arr, n, sum);

    }

    return 0;
}
