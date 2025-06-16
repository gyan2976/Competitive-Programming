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
// Space Complexity - O(1)
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0;
    int index = -1;

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}


// Optimal Solution - O(m * log(n)
// Space Complexity - O(1)
// It can be solved using:
// 1. Lower Bound (1)
// 2. Upper Bound (0)
// 3. First and Last Occurence (1)
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int count_max = 0;
    int index = -1;
    for(int i = 0; i < n; i++)
    {
        // int count_ones = lowerBound(matrix[i], m, 1); // This gives rows with min 1's
        int count_ones = m - lowerBound(matrix[i], m, 1); // This gives rows with max 1's
        if(count_ones > count_max)
        {
            count_max = count_ones;
            index = i;
        }
    }
    return index;
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
        vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
        int n = 3, m = 3;
        cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << endl;
    }

    return 0;
}