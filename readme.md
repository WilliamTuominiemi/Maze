# c++ recursive backtracking maze

Generates a random perfect maze.

```
+-+-+-+-+-+-+-+-+-+-+
| |           |     |
+ + + +-+-+-+ +-+-+ +
| | | |   |   |     |
+ + + + +-+ +-+ +-+ +
| | | |   | |     | |
+ +-+ +-+ + +-+-+ +-+
| |   |   | |   |   |
+ + +-+ +-+ + + +-+ +
| |   |   |   |   | |
+ +-+ +-+ +-+-+-+ + +
|   |   |       | | |
+-+ +-+ + +-+-+ + + +
|   |   | | |   |   |
+ +-+ +-+ + + +-+-+ +
|     | | | |     | |
+-+-+-+ + + +-+ +-+ +
|       |   | | |   |
+ +-+-+-+-+ + + + +-+
|             |     |
+-+-+-+-+-+-+-+-+-+-+
```

## Algorithm

1. Start with a cell, mark it as visited.
2. Get all unvisited neighboring cells.
3. Randomly pick a neighbor, remove the wall between the current cell and the neighbor, and move to it.
4. Recursively repeat the process for the neighbor.
5. If a cell has no unvisited neighbors, backtrack to the previous cell.
6. Continue until all cells are visited, ensuring a perfect maze.