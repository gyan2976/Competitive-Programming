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

void SpiralPrintMatrix(const vector<vector<int>> &arr, int m, int n)
{
    if(m == 0 || n == 0)
    {
        return;
    }

    int i, count = 0; 
    int rowStart = 0, colStart = 0;
    int numElements = m * n;
    int row = m, column = n;
    
    while(count < numElements)
    {
        for(i = colStart; i < numElements && i < column; ++i)
        {
            cout << arr[rowStart][i] << " ";
            count++;
        }
        rowStart++;

        for(i = rowStart; i < numElements && i < row; ++i)
        {
            cout << arr[i][column-1] << " ";
            count++;
        }
        column--;

        for(i = column-1; count < numElements && i >= colStart; --i)
        {
            cout << arr[row-1][i] << " ";
            count++;
        }
        row--;

        for(i = row-1; count < numElements && i >= rowStart; --i)
        {
            cout << arr[i][colStart] << " ";
            count++;
        }
        colStart++;
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

        cout << "Matrix:" << endl;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        SpiralPrintMatrix(arr, m, n);
    }

    return 0;
}