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

void rearrangeNumbers(vector<int>& arr) {
    int n = arr.size();
    vector<int> positive, negative;

    // Separate positive and negative elements
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positive.push_back(arr[i]);
        } else {
            negative.push_back(arr[i]);
        }
    }

    // Merge alternately
    vector<int> result;
    for (int i = 0; i < n / 2; i++) {
        result.push_back(positive[i]);
        result.push_back(negative[i]);
    }

    for (int num : result) {
        cout << num << " ";
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
        vector<int> arr = {3, 1, -2, -5, 2, -4};

        rearrangeNumbers(arr);
    }

    return 0;
}