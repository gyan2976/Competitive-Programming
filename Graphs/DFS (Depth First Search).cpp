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

// Function to print the adjacency list
void printAdjList(const vector<vector<int>>& edges, int n) {
    for (int i = 0; i < n; i++) 
    {
        cout << i << ": ";
        // for (int neighbor : edges[i]) 
        // {
        //     cout << neighbor << " ";
        // }
        for (size_t j = 0; j < edges[i].size(); j++) 
        { // Use size_t for the loop variable or long long int
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

// DFS function
void printDFS(const vector<vector<int>>& edges, int sv, vector<bool>& visited) {
    cout << sv << " ";
    visited[sv] = true;

    for (int neighbor : edges[sv]) 
    {
        if (!visited[neighbor]) 
        {
            printDFS(edges, neighbor, visited);
        }
    }

    // for(long long int i = 0; i < edges.size(); i++)
    // {
    //     if(edges[sv][i] == 1 && !visited[i])
    //     {
    //         dfs(edges, i, visited);
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
        // Write a code of DFS (Depth First Search)
        int n, e;
        cin >> n >> e;

        // Create adjacency matrix
        // 1. Dynamically
        // int **edges = new int*[n];
        // for(int i = 0; i < n; i++)
        // {
        //     edges[i] = new int[n];
        //     for(int j = 0; j < n; j++)
        //     {
        //         edges[i][j] = 0;
        //     }
        // }
        // 2. STL Vector
        // vector<vector<int>> edges(n, vector<int>(n));

        // Create adjacency list
        // 1. Dynamically
        // vector<int> *edges = new vector<int>[n];
        // 2. STL Vector
        vector<vector<int>> edges(n);

        // Read edges
        for(int i = 0; i < n; i++)
        {
            int f, s;
            cin >> f >> s;
            edges[f].push_back(s);
            edges[s].push_back(f);  // Undirected graph
        }

        // Print the adjacency list
        cout << "Adjacency List:" << endl;
        printAdjList(edges, n);

        // Create boolean vector visited
        // 1. Dynamically
        // bool *visited = new bool[n];
        // 2. STL Vector
        vector<bool> visited(n, false);

        // DFS traversal
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                printDFS(edges, i, visited);
            }
        }

        // Delete vectors if dynamically created
        // delete[] edges;
        // delete[] visited;
    }

    return 0;
}