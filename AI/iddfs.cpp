#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
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

    vector<int> iddfs(int start, int goal)
    {
        int maxDepth = 0;
        while (true)
        {
            unordered_map<int, bool> visited;
            stack<pair<int, int>> stk;
            stk.push({start, 0});

            while (!stk.empty())
            {
                int current = stk.top().first;
                int depth = stk.top().second;
                stk.pop();

                if (current == goal)
                {
                    vector<int> path;
                    getPath(start, goal, visited, path);
                    return path;
                }

                if (depth < maxDepth)
                {
                    visited[current] = true;
                    for (int neighbor : adjList[current])
                    {
                        if (!visited[neighbor])
                        {
                            stk.push({neighbor, depth + 1});
                        }
                    }
                }
            }

            maxDepth++;
        }
    }

private:
    void getPath(int start, int goal, unordered_map<int, bool> &visited, vector<int> &path)
    {
        int current = goal;
        while (current != start)
        {
            path.push_back(current);
            for (int neighbor : adjList[current])
            {
                if (visited[neighbor])
                {
                    current = neighbor;
                    break;
                }
            }
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
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

    vector<int> path_to_goal = graph.iddfs(start, goal);

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
