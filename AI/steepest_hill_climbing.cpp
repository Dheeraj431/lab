#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> graph = {
    {},
    {2, 3},
    {4, 5},
    {6},
    {7},
    {8},
    {9},
    {},
    {},
    {}};

int heuristic(int node, int goal)
{
    return abs(goal - node); // Manhattan distance heuristic
}

int steepestHillClimbing(int current, int goal, unordered_set<int> &visited)
{
    visited.insert(current);

    if (current == goal)
    {
        cout << "Goal node " << goal << " found!" << endl;
        return current;
    }

    int bestNeighbor = -1;
    int bestHeuristic = INT_MAX;

    for (int neighbor : graph[current])
    {
        if (visited.find(neighbor) == visited.end())
        {
            int neighborHeuristic = heuristic(neighbor, goal);
            if (neighborHeuristic < bestHeuristic)
            {
                bestNeighbor = neighbor;
                bestHeuristic = neighborHeuristic;
            }
        }
    }

    if (bestNeighbor != -1)
    {
        return steepestHillClimbing(bestNeighbor, goal, visited);
    }

    return -1;
}

int main()
{
    int start = 1;
    int goal = 9;
    unordered_set<int> visited;

    int result = steepestHillClimbing(start, goal, visited);

    if (result == -1)
    {
        cout << "Goal node " << goal << " not found!" << endl;
    }

    return 0;
}
