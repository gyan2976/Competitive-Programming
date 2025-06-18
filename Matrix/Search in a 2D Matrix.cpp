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

// Brute Force - O(m*n)
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// Better - O(n + log(m))
bool BinarySearch(vector<<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target)
        {
            return true;
        }
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++)
    {
        if(matrix[i][0] <= target && target <= matrix[i][m-1])
        {
            return BinarySearch(matrix[i], target);
        }
    }
    return false;
}

// Optimal - O(log(nxm))
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
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
        vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    }

    return 0;
}