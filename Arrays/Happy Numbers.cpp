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

// 1. Floyd-Cycle Algorithm
int square(int n)
{
    int squaresum = 0;
    while(n > 0)
    {
        int digit = n % 10;
        squaresum += digit * digit;
        n /= 10;
    }

    return squaresum;
}

bool happyNumber(int n)
{
    int slow, fast;
    slow = fast = n;

    do
    {
        slow = square(slow);
        fast = square(square(fast));
    }
    while(slow != fast);

    return slow == 1;
}

// 2. Set
bool happyNumber(int n)
{
    unordered_set<int> s;
    while(n != 1 && s.find(n) == s.end())   // Finding number in set
    {
        s.insert(n);
        int sum = 0;
        while(n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        n = sum;
    }

    return n == 1;
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
        int n;
        cin >> n;

        if(happyNumber(n))
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }

    }

    return 0;
}