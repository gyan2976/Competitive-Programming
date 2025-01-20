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

void columnWiseSum(const vector<vector<int>> &arr, int m, int n)
{
    for(int j = 0; j < n; j++)  // Column
    {
        int sum = 0;
        for(int i = 0; i < m; i++)  // Row
        {
            sum += arr[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << sum << endl;
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

        columnWiseSum(arr, m, n);
    }

    return 0;
}
