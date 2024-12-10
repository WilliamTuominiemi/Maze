#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;

class Cell
{
public:
    bool visited = false;
    int xPos, yPos;

    bool walls[4] = {true, true, true, true};

    Cell(int x, int y)
    {
        xPos = x;
        yPos = y;
    }

    void removeWall(pair<int, int> direction)
    {
        if (direction == pair<int, int>{-1, 0})
            walls[0] = false;
        else if (direction == pair<int, int>{0, 1})
            walls[2] = false;
        else if (direction == pair<int, int>{1, 0})
            walls[3] = false;
        else if (direction == pair<int, int>{0, -1})
            walls[1] = false;
    }
};

pair<int, int> getDirection(pair<int, int> from, pair<int, int> to)
{
    return {to.first - from.first, to.second - from.second};
}

vector<Cell *> getNeighbors(vector<vector<Cell>> &grid, Cell &cell)
{
    vector<Cell *> neighbors;
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (auto &dir : directions)
    {
        int newRow = cell.yPos + dir.first;
        int newCol = cell.xPos + dir.second;

        if (newRow >= 0 && newRow < HEIGHT &&
            newCol >= 0 && newCol < WIDTH &&
            !grid[newRow][newCol].visited)
        {
            neighbors.push_back(&grid[newRow][newCol]);
        }
    }

    return neighbors;
}

void generateMaze(vector<vector<Cell>> &grid, Cell &cell)
{
    cell.visited = true;
    vector<Cell *> neighbors = getNeighbors(grid, cell);
    while (!neighbors.empty())
    {
        Cell *nextCell = neighbors[rand() % neighbors.size()];

        pair<int, int> direction = getDirection({cell.yPos, cell.xPos}, {nextCell->yPos, nextCell->xPos});
        cell.removeWall(direction);
        nextCell->removeWall({-direction.first, -direction.second});

        generateMaze(grid, *nextCell);

        neighbors = getNeighbors(grid, cell);
    }
}

void printMaze(vector<vector<Cell>> &grid)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            cout << "+";
            cout << (grid[y][x].walls[0] ? "-" : " ");
        }
        cout << "+" << endl;

        for (int x = 0; x < WIDTH; x++)
        {
            cout << (grid[y][x].walls[1] ? "|" : " ");
            cout << " ";
        }
        cout << "|" << endl;
    }

    for (int x = 0; x < WIDTH; x++)
    {
        cout << "+-";
    }
    cout << "+" << endl;
}

int main()
{
    srand(time(NULL));
    vector<vector<Cell>> grid;

    for (int y = 0; y < HEIGHT; y++)
    {
        vector<Cell> row;
        for (int x = 0; x < WIDTH; x++)
        {
            row.emplace_back(Cell(x, y));
        }
        grid.push_back(row);
    }

    generateMaze(grid, grid[0][0]);
    printMaze(grid);

    return 0;
}