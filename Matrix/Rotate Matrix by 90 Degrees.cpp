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

// Input           // Output
// 25 19 39 11       15 13 65 25
// 65 49 81 10       14 35 49 19
// 13 35 69 70       12 69 81 39
// 15 14 12 16       16 70 10 11

// O(n*n)
vector<vector<int>> rotateMatrix90(vector<vector<int>> &matrix, int row, int col)
{
    // create one empty matrix (extra space)
    vector<vector<int>> arr(row, vector<int>(col, 0));
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            arr[j][col-i-1] = matrix[i][j];
        }
    }
    return arr;
}

// Optimal Solution (No Extra Space)
// Input               // Transpose        // Reverse
// [[5  1  9  11]      [[5  2  13 15]      [[15 13 2  5]
//  [2  4  8  10]       [1  4  3  14]       [14 3  4  1]
//  [13 3  6   7]       [9  8  6  12]       [12 6  8  9]
//  [15 14 12 16]]      [11 10 7  16]]      [16 7  10 11]]

vector<vector<int>> rotateMatrix90(vector<vector<int>> &matrix, int row, int col)
{
    // Transpose
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse
    for(int i = 0; i < row; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
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

        vector<vector<int>> matrix(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        vector<vector<int>> ans = rotateMatrix90(matrix, m, n);
        for(auto it: ans)
        {
            for(auto element: it)
            {
                cout << element << " ";
            }
            cout << endl;
        }
    }

    return 0;
}