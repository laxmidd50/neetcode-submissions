class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        return countPathsRecurse(grid, 0, 0);
    }

    int countPathsRecurse(vector<vector<int>> grid, int x, int y)
    {
        if (grid[x][y] == 1)
            return 0;
        
        if (x == grid.size()-1 && y == grid[x].size()-1)
        {
            return 1;
        }

        grid[x][y] = 1;

        int count = 0;
        if (x > 0 && grid[x-1][y] != 1)
            count += countPathsRecurse(grid, x-1, y);
        if (x < grid.size()-1 && grid[x+1][y] != 1)
            count += countPathsRecurse(grid, x+1, y);
        if (y > 0 && grid[x][y-1] != 1)
            count += countPathsRecurse(grid, x, y-1);
        if (y < grid[x].size()-1 && grid[x][y+1] != 1)
            count += countPathsRecurse(grid, x, y+1);
        return count;
    }
};
