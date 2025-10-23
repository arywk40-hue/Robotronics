#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void bfsConnected(map<int, vector<int>>& adj, int src, map<int, bool>& visited, vector<int>& res) {
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

vector<int> bfs(map<int, vector<int>>& adj) {
    map<int, bool> visited;
    
   
    for(auto &node : adj) {
        visited[node.first] = false;  
        for(int neighbor : node.second) {
            visited[neighbor] = false; 
        }
    }

    vector<int> res;

    for(auto &node : visited) {
        if (!node.second) {
            bfsConnected(adj, node.first, visited, res);
        }
    }
    return res;
}

int main() {
    map<int, vector<int>> adj;
    
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
    
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> res = bfs(adj);

    for (int i : res)
        cout << i << " ";
}

// This code performs a breadth-first search (BFS) traversal on an undirected graph represented using an adjacency list.
// It handles disconnected components by initiating a BFS from each unvisited node.
// The graph is represented as a map where keys are node identifiers and values are vectors of adjacent nodes.
// The bfsConnected function performs BFS from a given source node, marking nodes as visited and recording the traversal order.
// The bfs function iterates through all nodes, ensuring all components of the graph are covered.
// The main function demonstrates the usage of the BFS implementation with a sample graph.


// **BFS should be implemented in maze-solving robots because:**

// 1. It guarantees the shortest path - always finds the most efficient route from start to finish

// 2. Prevents getting stuck - systematically explores all directions and remembers visited spots to avoid cycles

// 3. Simple  - easy to implement on robot hardware while handling complex maze layouts perfectly