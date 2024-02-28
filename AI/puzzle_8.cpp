#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 3;

// Define movements: up, down, left, right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// Check if the given position is valid
bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}


bool dfs(vector<vector<int>> &board, int zx, int zy, const vector<vector<int>> &goal, set<vector<vector<int>>> &visited)
{
    if (board == goal)
    {
        return true; // Goal state reached
    }

    visited.insert(board);

    for (int dir = 0; dir < 4; ++dir)
    {
        int newX = zx + dx[dir];
        int newY = zy + dy[dir];

        if (isValid(newX, newY))
        {
            swap(board[zx][zy], board[newX][newY]);

            if (dfs(board, newX, newY, goal, visited))
            {
                return true; // Goal found in this branch
            }

            // Undo the move
            swap(board[zx][zy], board[newX][newY]);
        }
    }

    return false; // Goal not found in this branch
}

int main()
{
    // Define initial and goal states
    vector<vector<int>> initialBoard = {{1, 2, 3}, {4, 0, 5}, {7, 6, 8}}; // Modified initial state
    vector<vector<int>> goalBoard = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    set<vector<vector<int>>> visited;

    if (dfs(initialBoard, 1, 1, goalBoard, visited))
    {
        cout << "Goal state is reachable from the initial state using DFS." << endl;
    }
    else
    {
        cout << "Goal state is not reachable from the initial state using DFS." << endl;
    }

    return 0;
}
