// 547. Number of Provinces
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>&v, vector<int>&vis,int s){
        vis[s] = 1;
        for(auto i:v[s]){
            if(!vis[i]){
                dfs(v,vis,i);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        //undirected graph....
        int n = isConnected.size();
        
        //create a adjacency list here...
        vector<vector<int>>lis(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){ //avoid self loops
                    lis[i].push_back(j);
                    lis[j].push_back(i);
                }
            }
        }
        // STORES THE ANSWER...
        int count = 0;
        vector<int>vis(n,0); //Visited array
        //So here what we need is an index to start visiting the graph.
        //Hence we run a for loop and check for all the values of i, 
        //if it is visisted then dont traverse again otherwise traverse 
        //and make sure that you count that traverse.
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                count++;
                dfs(lis,vis,i);
            }
        }
        return count;
    }
};