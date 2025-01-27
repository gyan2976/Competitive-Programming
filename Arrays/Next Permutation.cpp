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

void nextPermutation(int *arr, int n)
{
    int index = -1;
    for(int i = n-2; i >= 0; i--)
    {
        if(arr[i] < arr[i+1])
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        reverse(arr, arr+n);
    }
    else
    {
        for(int i = n-1; i > index; i--)
        {
            if(arr[i] > arr[index])
            {
                swap(arr[i], arr[index]);
                break;
            }
        }

        reverse(arr+index+1, arr+n);
    }

    // Print Next Permutation
    cout << "Next Permutation: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

        nextPermutation(arr, n);
    }

    return 0;
}