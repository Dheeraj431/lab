#include <bits/stdc++.h>
using namespace std;

class WaterJugProblemSolver
{
public:
    int minStepsToMeasureWater(int cap1, int cap2, int target)
    {
        vector<vector<bool>> visited(cap1 + 1, vector<bool>(cap2 + 1, false));
        vector<vector<pair<int, int>>> parent(cap1 + 1, vector<pair<int, int>>(cap2 + 1, {-1, -1}));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        int steps = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int jug1 = q.front().first;
                int jug2 = q.front().second;
                q.pop();

                if (jug1 == target || jug2 == target || jug1 + jug2 == target)
                {
                    printStates(parent, jug1, jug2);
                    return steps;
                }

                exploreState(jug1, jug2, cap1, cap2, visited, parent, q);
            }
            steps++;
        }

        return -1; // Target amount cannot be achieved
    }

private:
    void exploreState(int jug1, int jug2, int cap1, int cap2,
                      vector<vector<bool>> &visited, vector<vector<pair<int, int>>> &parent, queue<pair<int, int>> &q)
    {
        // Fill jug1
        if (jug1 < cap1 && !visited[cap1][jug2])
        {
            q.push({cap1, jug2});
            visited[cap1][jug2] = true;
            parent[cap1][jug2] = {jug1, jug2};
        }

        // Fill jug2
        if (jug2 < cap2 && !visited[jug1][cap2])
        {
            q.push({jug1, cap2});
            visited[jug1][cap2] = true;
            parent[jug1][cap2] = {jug1, jug2};
        }

        // Empty jug1
        if (jug1 > 0 && !visited[0][jug2])
        {
            q.push({0, jug2});
            visited[0][jug2] = true;
            parent[0][jug2] = {jug1, jug2};
        }

        // Empty jug2
        if (jug2 > 0 && !visited[jug1][0])
        {
            q.push({jug1, 0});
            visited[jug1][0] = true;
            parent[jug1][0] = {jug1, jug2};
        }

        // Pour from jug1 to jug2
        int pour1to2 = min(jug1, cap2 - jug2);
        if (pour1to2 > 0 && !visited[jug1 - pour1to2][jug2 + pour1to2])
        {
            q.push({jug1 - pour1to2, jug2 + pour1to2});
            visited[jug1 - pour1to2][jug2 + pour1to2] = true;
            parent[jug1 - pour1to2][jug2 + pour1to2] = {jug1, jug2};
        }

        // Pour from jug2 to jug1
        int pour2to1 = min(jug2, cap1 - jug1);
        if (pour2to1 > 0 && !visited[jug1 + pour2to1][jug2 - pour2to1])
        {
            q.push({jug1 + pour2to1, jug2 - pour2to1});
            visited[jug1 + pour2to1][jug2 - pour2to1] = true;
            parent[jug1 + pour2to1][jug2 - pour2to1] = {jug1, jug2};
        }
    }

    void printStates(vector<vector<pair<int, int>>> &parent, int jug1, int jug2)
    {
        vector<pair<int, int>> states;
        while (jug1 != -1 && jug2 != -1)
        {
            states.push_back({jug1, jug2});
            pair<int, int> p = parent[jug1][jug2];
            jug1 = p.first;
            jug2 = p.second;
        }

        for (int i = states.size() - 1; i >= 0; --i)
        {
            cout << "(" << states[i].first << ", " << states[i].second << ")" << endl;
        }
    }
};

int main()
{
    int cap1 = 4;   // Capacity of jug 1
    int cap2 = 3;   // Capacity of jug 2
    int target = 2; // Desired amount of water

    WaterJugProblemSolver solver;
    int minSteps = solver.minStepsToMeasureWater(cap1, cap2, target);

    if (minSteps == -1)
    {
        cout << "It's not possible to measure " << target << " liters of water "
             << "using jugs with capacities " << cap1 << " and " << cap2 << "." << endl;
    }
    else
    {
        cout << "Minimum steps required to measure " << target << " liters of water: " << minSteps << endl;
    }

    return 0;
}
