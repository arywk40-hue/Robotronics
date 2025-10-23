#include <iostream>
#include <vector>       

using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

// Recursive function for DFS traversal
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{
    // Mark the current vertex as visited
    visited[s] = true;

    res.push_back(s);

    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
}


vector<int> DFS(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
   
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[i] == false)
        {
            // If vertex i has not been visited,
            // perform DFS from it
            dfsRec(adj, visited, i, res);
        }
    }

    return res;
}

int main()
{
    int V = 6;
    
    vector<vector<int>> adj(V);

    // Define the edges of the graph
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};

   
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);
    vector<int> res = DFS(adj);

    for (auto it : res)
        cout << it << " ";
    return 0;
}