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

// 1. Hashmap - O((m+n) * log(m+n))
void findUnion(int *arr1, int n, int *arr2, int m)
{
    map<int, int> frequencies;
    vector<int> UnionOfArray;
    for(int i = 0 ; i < n; i++)
    {
        frequencies[arr1[i]]++;
    }

    for(int i = 0 ; i < m; i++)
    {
        frequencies[arr2[i]]++;
    }

    for(auto it: frequencies)
    {
        UnionOfArray.push_back(it.first);
    }

    for(auto val: UnionOfArray)
    {
        cout << val << " ";
    }
}

// 2. Set - O((m+n) * log(m+n))
void findUnion(int *arr1, int n, int *arr2, int m)
{
    set<int> s;
    vector<int> UnionOfArray;
    for(int i = 0 ; i < n; i++)
    {
        s.insert(arr1[i]);
    }

    for(int i = 0 ; i < m; i++)
    {
        s.insert(arr2[i]);
    }

    for(auto it: s)
    {
        UnionOfArray.push_back(it);
    }

    for(auto val: UnionOfArray)
    {
        cout << val << " ";
    }
}

// 3. Two Pointers - O(m+n)
void findUnion(int *arr1, int n, int *arr2, int m)
{
    int i = 0, j = 0;
    vector<int> Union;

    while (i < n && j < m) 
    {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
            Union.push_back(arr1[i]);
            i++;
        } 
        else // case 3
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
            Union.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n) // IF any element left in arr1
    {
        if (Union.back() != arr1[i])
        Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
        Union.push_back(arr2[j]);
        j++;
    }

    for(auto val: Union)
    {
        cout << val << " ";
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
        int n = 10, m = 8;

        int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int arr2[] = {1, 2, 3, 4, 4, 5, 11, 12};

        findUnion(arr1, n, arr2, m);
    }

    return 0;
}