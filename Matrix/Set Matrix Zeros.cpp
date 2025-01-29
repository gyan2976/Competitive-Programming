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

// 1. Brute Force O(n^3)
void markRow(vector<vector<int>> &matrix, int m, int n, int i)
{
    for(int j = 0; j < n; j++)
    {
        if(matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markColumn(vector<vector<int>> &matrix, int m, int n, int j)
{
    for(int i = 0; i < m; i++)
    {
        if(matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void setMatrixZero(vector<vector<int>>  &matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(matrix[i][j] == 0)
            {
                markRow(matrix, row, column, i);
                markColumn(matrix, row, column, j);
            }
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for(auto it: matrix)
    {
        for(auto ele: it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

// 2. Better O(n^2)
void setMatrixZero(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();

    int rowArray[row] = {0};
    int columnArray[column] = {0};

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(matrix[i][j] == 0)
            {
                rowArray[i] = 1;
                columnArray[j] = 1;
            }
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(rowArray[i] || columnArray[j])
            {
                matrix[i][j] = 0;
            }
        }
    }

    for(auto it: matrix)
    {
        for(auto ele: it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

// 3. Optimal O(n^2)
void setMatrixZero(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();

    // We have to mark in the matrix itself
    // int rowArray[row] = {0};    --->  matrix[...][0] // No extra array to be created to mark
    // int colArray[column] = {0}; --->  matrix[0][...] // No extra array to be created to mark

    // Step 1: Mark for the matrix row and column
    int col0 = 1;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(matrix[i][j] == 0)
            {
                // Mark i-th row
                matrix[i][0] = 0;

                // Mark j-th column
                if(j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }

            }
        }
    }

    // Step 2: Now mark the matrix except 0th row and 0th column
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < column; j++)
        {
            if(matrix[i][j] != 0)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // Step 3: Finally mark the first column & then first row
    if(matrix[0][0] == 0)
    {
        for(int j = 0; j < column; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if(col0 == 0)
    {
        for (int i = 0; i < row; i++) 
        {
            matrix[i][0] = 0;
        }
    }

    // Print the matrix
    for(auto it: matrix)
    {
        for(auto ele: it)
        {
            cout << ele << " ";
        }
        cout << endl;
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

        vector<vector<int>> matrix(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        setMatrixZero(matrix);
    }

    return 0;
}