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

// 1. Brute Force O(n^2)
vector<int> findMissingRepeatingNumbers(vector<int> &arr)
{
    int n = arr.size();
    int missing = -1, repeating = -1;

    for(int i = 1; i <= n; i++)
    {
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }

        if(count > 1)
        {
            repeating = i;
        }
        else if(count == 0)
        {
            missing = i;
        }

        // if(missing != -1 && repeating != -1)
        // {
        //     break;
        // }

    }

    return {repeating, missing};
}

// 2. Hashing O(n),  Space O(n)
vector<int> findMissingRepeatingNumbers(vector<int> &arr)
{
    int n = arr.size();
    // create a hash array
    int hasharray[n+1] = {0};

    for(int i = 0; i < n; i++)
    {
        hasharray[arr[i]]++;
    }

    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++)
    {
        if(hasharray[i] > 1)
        {
            repeating = i;
        }
        else if(hasharray[i] == 0)
        {
            missing = i;
        }

        // if(missing != -1 && repeating != -1)
        // {
        //     break;
        // }
    }
    return {repeating, missing};
}

// 3. Optimal Math O(n), Space O(1)
// We can solve this using XOR also
vector<int> findMissingRepeatingNumbers(vector<int> &arr)
{
    long long n = arr.size(); // size of the array

    // Find Sn and S2n:
    // These are formulas
    long long SN = (n * (n + 1)) / 2;   // Sum of all natural n numbers
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;    // Sum of squares of all n natural numbers

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
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
        // cout << "Hi Gyan, Welcome Back :)";

        vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
        vector<int> ans = findMissingRepeatingNumbers(a);
        cout << "The repeating and missing numbers are: {"
             << ans[0] << ", " << ans[1] << "}\n";
    }

    return 0;
}