//go deep into first node and keep track if it is visited or not using visited array.

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&graph, int s, vector<int>&path, vector<bool>&vis){
    vis[s] = true; //mark the first index as true that we have visited it and push it into stack.
    path.push_back(s); //add it into path
    //find all the neightbors of the elem
    //and the neighbours of elem will be at its index in graph...i.e graph[elem]
    for(auto it:graph[s]){
        if(!vis[it]){
            DFS(graph,it,path,vis);
        }
    }

}
int main(){
    //create a adjacency list of n nodes and v vertices.
    int n,e;
    cout<<"Enter the number of Nodes & Edges : (Node Starts from 1 & NOT 0)";
    cin>>n>>e;
    //creates a 2D Matrix of size n+1(node+1) and E+1
    // vector<int>adjList[n+1];
    vector<vector<int>>adjList(n+1);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int>path;
    vector<bool>visited(adjList.size()+1,false);
    //traverse DFS
    int s;
    cin>>s;
    DFS(adjList,s,path,visited);
    
    //print the path
    cout<<"Traversal Followed Is"<<endl;
    for(auto i:path){
        cout<<i<<" ";
    }
    return 0;
    
}

/*


8 9
1 2
1 7
2 3
3 4
3 7
4 5
4 8
5 6
6 7
*/