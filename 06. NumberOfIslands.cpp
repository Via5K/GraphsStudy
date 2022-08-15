// 200. Number of Islands
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //BOTH ARE SAME BUT ABOVE USED LOOP TO GOTO ITS NEIGHBORS...
    void dfs(vector<vector<char>>&grid, int i, int j, vector<vector<int>>&vis, int n, int m){
        if(vis[i][j]==0 && grid[i][j]=='1'){
            vis[i][j] = 1;
            //go right
            if(j+1<m){dfs(grid, i, j+1, vis, n,m);}
            //go up
            if(i-1>=0){dfs(grid, i-1, j, vis, n, m);}
            //go down
            if(i+1<n){dfs(grid, i+1, j, vis, n, m);}
            //go left
            if(j-1>=0){dfs(grid, i, j-1, vis, n, m);}
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    // dfs(grid, vis, i, j, n, m);
                    dfs(grid, i, j, vis, n, m);
                }
            }
        }
        return count;
        
    }
};