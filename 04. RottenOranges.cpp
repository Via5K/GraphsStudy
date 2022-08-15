// 994. Rotten Oranges

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis, queue<vector<int>>&q,int n, int m){
        int mx = 0;
        
        while(!q.empty()){
            vector<int>elem = q.front();
            int i = elem[0];
            int j = elem[1];
            int t = elem[2];
            mx = max(t,mx); //find the maximum time.
            vis[i][j]=1;//rotted
            q.pop();

            //go up
            if(i-1>=0 && grid[i-1][j]==1 && vis[i-1][j]==0){
                q.push({i-1,j,t+1}); //insert this at queue.
                vis[i-1][j]=1; //mark as visited
                fresh_vis++;//increase that fresh orng has been rotten
            }
            //go down
            if(i+1<n && grid[i+1][j]==1 && vis[i+1][j]==0){
                q.push({i+1,j,t+1});
                vis[i+1][j]=1;
                fresh_vis++;
            }
            //go left
            if(j-1>=0 && grid[i][j-1]==1 && vis[i][j-1]==0){
                q.push({i,j-1,t+1});
                vis[i][j-1]=1;
                fresh_vis++;
            }
            //go right
            if(j+1<m && grid[i][j+1]==1 && vis[i][j+1]==0){
                q.push({i,j+1,t+1});
                vis[i][j+1]=1;
                fresh_vis++;
            }
            
            
        }
        return mx;
        
    }
    public:
    int fresh_vis = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int min = 0;
        int fresh = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<vector<int>>q;
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                //pushing the rotten oranges in the queue.
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
                //counting the fresh oranges.
                if(grid[i][j]==1) fresh++;
            }
        }
        
        //now our queue has all the rotten oranges..
        // call bfs 
        min = bfs(grid,vis, q, n , m);
        
        // to check if all the fresh oranges have been rotten or not?
        // for(int i=0;i<n;i++){
        //     for(int j =0;j<m;j++){
        //         if(grid[i][j]==1 && vis[i][j]==0){return -1;}// unable to rott
        //         // cout<<vis[i][j]<<" ";
        //     }
        //     // cout<<endl;
        // }
        
        if(fresh!=fresh_vis)return -1;
        return min;
    }
};