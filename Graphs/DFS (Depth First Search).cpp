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

// DFS (Depth First Search)

void printAdjList(const vector<int> *adj, int n) {
    for (int i = 0; i < n; i++) 
    {
        cout << i << ": ";
        for (int neighbor : adj[i]) 
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

void printDFS(vector<int> *adj, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;

    for (long long i = 0; i < adj[sv].size(); i++) 
    {
        int neighbor = adj[sv][i];
        if (!visited[neighbor]) 
        {
            printDFS(adj, neighbor, visited);
        }
    }

    // for(int neighbor : adj[sv])
    // {
    //     if(!visited[neighbor])
    //     {
    //         print(adj, neighbor, visited);
    //     }
    // }
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
        int n, e;       // Number of Nodes & Number of Edges
        cin >> n >> e;

        vector<int> *adj = new vector<int>[n];  // Create Adjacency List
        for(int i = 0; i < e; i++)
        {
            int f, s;
            cin >> f >> s;
            adj[f].push_back(s);
            adj[s].push_back(f);    // We don't need this in case of Directed Graph
        }

        // Print the adjacency list
        cout << "Adjacency List:" << endl;
        printAdjList(adj, n);

        bool *visited = new bool[n];    // Create Visited Array
        for(int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        cout << "DFS Traversal:" << endl;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                printDFS(adj, i, visited);
            }
        }

        delete[] visited;
        delete[] adj;

    }

    return 0;
}