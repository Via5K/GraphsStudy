#include<bits/stdc++.h>
using namespace std;

int main(){
    //create a adjacency list of n nodes and v vertices.
    int n,e;
    cout<<"Enter the number of Nodes & Edges : (Node Starts from 1 & NOT 0)";
    cin>>n>>e;
    //creates a 2D Matrix of size n+1(node+1) and E+1
    vector<int>adjList[n+1];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    //at 0th index, there is no element stored because we dont have 0th node.
    for(int i=0;i<n+1;i++){
        int x = 0;
        cout<<i<<": ";
        while(adjList[i].size()>x){
            cout<<adjList[i][x]<<" ";
            x++;
        }
        cout<<endl;
    }
}



/*
TEST CASE

8 9
1 2
1 7
3 4
4 5
5 6
6 7
2 3
3 7
4 8

*/