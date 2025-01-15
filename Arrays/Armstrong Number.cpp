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

int totalCount(int n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

bool armstrongNumber(int n)
{
    int real = n;
    int sum = 0;
    int digits = totalCount(n);

    while(n > 0)
    {
        int power = 1;
        int digit = n % 10;
        for (int i = 0; i < digits; i++) 
        {
            power *= digit;
        }

        sum += power;
        n /= 10;
    }

    return sum == real;
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

        if(armstrongNumber(n))
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