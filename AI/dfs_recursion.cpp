#include <iostream>
#include <unordered_map>
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
        vector<int> path;
        dfsUtil(start, goal, visited, parent, path);
        return path;
    }

private:
    bool dfsUtil(int current, int goal, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, vector<int> &path)
    {
        if (current == goal)
        {
            path.push_back(current);
            return true;
        }

        visited[current] = true;
        for (int neighbor : adjList[current])
        {
            if (!visited[neighbor])
            {
                parent[neighbor] = current;
                if (dfsUtil(neighbor, goal, visited, parent, path))
                {
                    path.push_back(current);
                    return true;
                }
            }
        }

        return false;
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
        for (int i = path_to_goal.size() - 1; i >= 0; --i)
        {
            cout << path_to_goal[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found." << endl;
    }

    return 0;
}
