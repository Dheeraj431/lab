#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> grid = {
    {0, 1, 0},
    {0, 1, 0},
    {0, 0, 2}};

vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

bool is_valid_move(int x, int y)
{
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != 1;
}

bool dfs(int x, int y, vector<vector<bool>> &visited, vector<pair<int, int>> &path)
{
    if (grid[x][y] == 2)
    {
        return true;
    }

    visited[x][y] = true;
    path.push_back({x, y});

    for (auto &move : movements)
    {
        int new_x = x + move.first;
        int new_y = y + move.second;
        if (is_valid_move(new_x, new_y) && !visited[new_x][new_y])
        {
            if (dfs(new_x, new_y, visited, path))
            {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main()
{
    int start_x = 0, start_y = 0;

    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<pair<int, int>> path;

    if (dfs(start_x, start_y, visited, path))
    {
        cout << "Sequence of movements to reach the bananas:" << endl;
        for (auto &pos : path)
        {
            cout << "(" << pos.first << ", " << pos.second << ")" << endl;
        }
    }
    else
    {
        cout << "The monkey cannot reach the bananas." << endl;
    }

    return 0;
}
