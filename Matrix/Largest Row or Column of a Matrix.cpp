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

void rowWiseSum(const vector<vector<int>> &arr, int m, int n)
{
    bool isRow = true;
    int largestSum = INT_MIN;
    int num = 0;

    // Checking Rows
    for(int i = 0; i < m; i++)
    {
        int rowSum = 0;
        for(int j = 0; j < n; j++)
        {
            rowSum += arr[i][j];
        }

        if(rowSum > largestSum)
        {
            largestSum = rowSum;
            num = i;
        }
    }

    // Checking Columns
    for(int j = 0; j < n; j++)
    {
        int colSum = 0;
        for(int i = 0; i < m; i++)
        {
            colSum += arr[i][j];
        }

        if(colSum > largestSum)
        {
            largestSum = colSum;
            num = j;
            isRow = false;
        }
    }

    if(isRow)
    {
        cout << "Largest Row is " << num << ": " << largestSum; 
    }
    else
    {
        cout << "Largest Column is " << num << ": " << largestSum;
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
        int m, n;
        cin >> m >> n;

        vector<vector<int>> arr(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        cout << "My Matrix:" << endl;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        rowWiseSum(arr, m, n);
    }

    return 0;
}