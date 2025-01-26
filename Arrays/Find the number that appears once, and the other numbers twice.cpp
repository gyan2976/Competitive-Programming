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

void numberAppearsOnce(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        int j = 0;
        while(j < n)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
            j++;
        }

        if(count == 1)
        {
            {
                cout << "The number is: " << arr[i] << endl;
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
        int n = 6;
        int arr[] = {4, 1, 2, 1, 2, 9};

        numberAppearsOnce(arr, n);
    }

    return 0;
}