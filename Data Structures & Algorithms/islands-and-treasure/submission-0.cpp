struct NodePos
{
    int x;
    int y;
    int distance;
};

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<NodePos> nodeQueue;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                    nodeQueue.push({i, j, 0});
            }
        }

        while (!nodeQueue.empty())
        {
            NodePos curNode = nodeQueue.front();
            nodeQueue.pop();

            if (grid[curNode.x][curNode.y] == -1)
                continue;
            else if (curNode.distance > grid[curNode.x][curNode.y])
                continue;
            else
            {
                grid[curNode.x][curNode.y] = curNode.distance;
                if (curNode.x > 0)
                    nodeQueue.push({curNode.x-1, curNode.y, curNode.distance+1});
                if (curNode.x < grid.size()-1)
                    nodeQueue.push({curNode.x+1, curNode.y, curNode.distance+1});
                if (curNode.y > 0)
                    nodeQueue.push({curNode.x, curNode.y-1, curNode.distance+1});
                if (curNode.y < grid[curNode.x].size()-1)
                    nodeQueue.push({curNode.x, curNode.y+1, curNode.distance+1});
            }
        }
    }
};
