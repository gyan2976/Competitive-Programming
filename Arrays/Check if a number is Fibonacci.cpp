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
using namespace std;

int func(int n)
{
    if(n < 0)
    {
        return false;
    }

    int t1=0, t2=1;

    if((t2 == n || t1 == n))
    {
        return true;
    }

    while(t2 < n)
    {
        int temp = t1 + t2;
        t1 = t2;
        t2 = temp;
    }

    return (t2 == n);

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
        int n = 21;
        if(func(n)) 
        {
            cout << n << " is a Fibonacci number.\n";
        } 
        else 
        {
            cout << n << " is not a Fibonacci number.\n";
        }

    }

    return 0;
}