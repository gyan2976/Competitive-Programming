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

void printBFS(vector<int> *adj, int n, int sv, bool *visited) {
    // Create a queue for BFS
    queue<int> q;
    
    // Mark the source node as visited and enqueue it
    visited[sv] = true;
    q.push(sv);
    
    // Start BFS
    while (!q.empty()) {
        // Dequeue a vertex and print it
        int current = q.front();
        cout << current << " ";
        q.pop();
        
        // Visit all neighbors of the current node
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
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
        int n, e;
        cin >> n >> e;

        // Create an adjacency list
        vector<int> *adj = new vector<int>[n];

        // Read edges and add them to the adjacency list
        for (int i = 0; i < e; i++) 
        {
            int f, s;
            cin >> f >> s;
            adj[f].push_back(s);
            adj[s].push_back(f); // Since this is an undirected graph
        }

        // Initialize visited array
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++) 
        {
            visited[i] = false;
        }

        // Call BFS for each unvisited node
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i]) 
            {
                printBFS(adj, i, visited);
            }
        }

        // Clean up dynamically allocated memory
        delete[] adj;
        delete[] visited;

    }

    return 0;
}