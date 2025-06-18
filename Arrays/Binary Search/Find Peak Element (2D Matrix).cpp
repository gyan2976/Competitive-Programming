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

// Optimal - O(n * log(m))
int findMaxElement(vector<vector<int>> &matrix, int n, int m, int col)
{
    int maxValue = -1;
    int index = -1;
    for(int i = 0; i < n; i++)
    {
        if(matrix[i][col] > maxValue)
        {
            maxValue = matrix[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>>& matrix)
{
    int n = matrix.size();      // Total Row
    int m = matrix[0].size();   // Total Column

    int low = 0, high = m-1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        // Get the row number with max value for a column
        int maxRowIndex = findMaxElement(matrix, n, m, mid);
        int left = mid-1 > 0 ? matrix[maxRowIndex][mid-1] : -1;
        int right = mid+1 < m ? matrix[maxRowIndex][mid+1] : -1;
        if(matrix[maxRowIndex][mid] > left && matrix[maxRowIndex][mid] > right)
        {
            return {maxRowIndex, mid};
        }
        else if(matrix[maxRowIndex][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return  {-1, -1};
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
        vector<vector<int>> matrix = {{4, 2, 5, 1, 4, 5}, 
                                      {2, 9, 3, 2, 3, 2},
                                      {1, 7, 6, 0, 1, 3}, 
                                      {3, 6, 2, 3, 7, 2}};

        vector<int> ans = findPeakGrid(matrix);
        cout << ans[0] << " " << ans[1] << endl;    }

    return 0;
}