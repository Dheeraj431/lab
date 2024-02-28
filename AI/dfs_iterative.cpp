#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
private:
    unordered_map<int, vector<int>> adjList;

public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        // Assuming an undirected graph, if directed, remove the next line
        adjList[v].push_back(u);
    }

    vector<int> dfs(int start, int goal)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            if (current == goal)
            {
                vector<int> path;
                while (current != start)
                {
                    path.push_back(current);
                    current = parent[current];
                }
                path.push_back(start);
                reverse(path.begin(), path.end());
                return path;
            }

            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    s.push(neighbor);
                }
            }
        }

        return vector<int>(); // No path found
    }
};

int main()
{
    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);
    graph.addEdge(5, 6);

    int start = 1;
    int goal = 6;

    vector<int> path_to_goal = graph.dfs(start, goal);

    if (!path_to_goal.empty())
    {
        cout << "Path found: ";
        for (int node : path_to_goal)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found." << endl;
    }

    return 0;
}
