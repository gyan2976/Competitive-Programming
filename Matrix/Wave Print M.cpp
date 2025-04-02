#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype> 
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void wavePrintM(const vector<vector<int>> &matrix, int m, int n)
{
    for(int j = 0; j < n; j++)
    {
        if(j%2 == 0)
        {
            for(int i = m-1; i >= 0; i--)
            {
                cout << matrix[i][j] << " ";
            }
        }
        else
        {
            for(int i = 0; i < m; i++)
            {
                cout << matrix[i][j] << " ";
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
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));
        for(auto& i : matrix) 
        {         
            for(int& j : i) 
            {         
                cin >> j;
            }
        }
        cout << "Original Matrix: " << endl;
        for(auto i: matrix)
        {
            for(auto j: i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << "\n";

        wavePrintM(matrix, m, n);

    }

    return 0;
}