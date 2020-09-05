/*

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        int prevFreshOrange = -1;
        int minutes = 0;
        stack<pair<int,int>> rOrange;
        stack<pair<int,int>> tOrange;
        
        for(int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[i].size(); ++j){
                if (grid[i][j] == 2){
                    rOrange.push(pair<int,int>{i,j});
                }
                else if (grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        
        if (freshOranges == 0){
            return 0;
        }
        
        
        // i : row
        // j : column
        
        
        while (rOrange.size()){
            int x = rOrange.top().first;
            int y = rOrange.top().second;
            rOrange.pop();
            // up 
            if (x-1 >= 0 && grid[x-1][y+0] == 1){
                grid[x-1][y+0] = 2;
                --freshOranges;
                tOrange.push(pair<int,int>{x-1,y});
            }
            // down
            if (x+1 < grid.size() && grid[x+1][y+0] == 1){
                grid[x+1][y+0] = 2;
                --freshOranges;
                tOrange.push(pair<int,int>{x+1,y});
            }
            // left
            if (y-1 >= 0 && grid[x+0][y-1] == 1){
                grid[x+0][y-1] = 2;
                --freshOranges;
                tOrange.push(pair<int,int>{x,y-1});
            }
            // right
            if (y+1 < grid[x].size() && grid[x+0][y+1] == 1){
                grid[x+0][y+1] = 2;
                --freshOranges;
                tOrange.push(pair<int,int>{x,y+1});
            }
            if (!rOrange.size()){
                ++minutes;
                if (freshOranges == 0){
                   break;
                }
                rOrange = tOrange;
                tOrange = stack<pair<int,int>>();
                
            }
            
        }
        
        if (rOrange.size()){
            ++minutes;
        }
        
        
        
        return (freshOranges == 0) ? minutes : -1;
    }
};

// [1]
// [2]
// [1]
// [2]