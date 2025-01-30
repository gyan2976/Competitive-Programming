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

//              Pascal Triangle
//                      1
//                  1       1
//              1       2       1
//          1       3       3      1
//      1       4       6       4     1
//  1       5       10      10     5      1

// Question: Print Pascal Triangle

vector<int> nCr(int row)
{
    long long ans = 1;
    vector<int> v;
    v.push_back(1);

    for(int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        v.push_back(ans);
    }
    return v;
}

vector<vector<int>> PascalTriangle(int n)
{
    vector<vector<int>> ans;
    for(int row = 1; row <= n; row++)
    {
        ans.push_back(nCr(row));
    }

    return ans;
}


// vector<vector<int>> generatePascalTriangle(int numRows) 
// {
//     vector<vector<int>> ansRow;
//     for(int i = 0; i < numRows; i++)
//     {
//         long long ans = 1;
//         vector<int> output;
//         output.push_back(ans);
//         for(int col = 1; col <= i; col++)
//         {
//             ans = ans * (i - col + 1);
//             ans = ans / col;
//             output.push_back(ans);
//         }
//         ansRow.push_back(output);
//     }
//     return ansRow;
// }

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

        vector<vector<int>> ans = PascalTriangle(n);
        //vector<vector<int>> ans = generatePascalTriangle(n);

        for(auto it: ans)
        {
            for(auto ele: it)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }

    return 0;
}