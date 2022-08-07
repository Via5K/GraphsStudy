#include<bits/stdc++.h>
using namespace std;

int main(){
    //create a adjacency Matrix of n nodes and v vertices.
    
    int n,e;
    cout<<"Enter the number of Nodes & Edges : (Node Starts from 1 & NOT 0)";
    cin>>n>>e;
    //creates a 2D Matrix of size n+1(node+1) and E+1
    vector<vector<int>>adjMatrix(n+1,vector<int>(e+1,0));
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<e+1;j++){
            cout<<adjMatrix[i][j]<<" ";
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