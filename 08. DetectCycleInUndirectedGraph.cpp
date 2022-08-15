// GFG => https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool BFS(vector<int>adj[], int src, vector<int>&vis){
        vis[src]=1;
        queue<pair<int,int>>q;
        
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto i: adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({i,node});
                }
                else if(parent!=i){
                    
                    return true; //it is forming a cycle then....
                }
            }
        }
        return false;
        
    }
    public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool sol = BFS(adj,i,vis);
                if(sol==true) return true;
            }
        }
        return false;
    }
};