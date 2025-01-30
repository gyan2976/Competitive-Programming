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

// Input               // Transpose        
// [[5  1  9  11]      [[5  2  13 15]      
//  [2  4  8  10]       [1  4  3  14]      
//  [13 3  6   7]       [9  8  6  12]      
//  [15 14 12 16]]      [11 10 7  16]]

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

        cout << "Original Matrix:"
        for(auto it: matrix)
        {
            for(auto element: it)
            {
                cout << element << " ";
            }
            cout << endl;
        }
        cout << endl;

        vector<vector<int>> transpose = rotateMatrix90(matrix, m, n);

        cout << "Transpose Matrix";
        for(auto it: transpose)
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