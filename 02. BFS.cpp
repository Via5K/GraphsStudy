//done using queue...

#include<bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>>&graph, int s){
    vector<bool>visited(graph.size()+1,false);
    queue<int>q;
    vector<int>path;
    visited[s] = true; //mark the first index as true that we have visited it and push it into queue.
    q.push(s); //starting from this index.
    while(!q.empty()){
        int elem = q.front(); //get the queue elem
        q.pop(); //pop from queue
        path.push_back(elem); //add it into path

        //find all the neightbors of the elem
        //and the neighbours of elem will be at its index in graph...i.e graph[elem]

        // for(int i=0;i<graph[elem].size();i++){
        //     //push all those elements into the queue....
        //     //as well as write them into the path vector.
        //     //and do this only if the node is not visited yet.
        //     if(!visited[graph[elem][i]]){ //if not visisted the element yet
        //         visited[graph[elem][i]] = true; //now we have visited them so mark them as visited also.
        //         q.push(graph[elem][i]); //and add that visisted elem into queue
        //     }
        // }
        //both above and below are same just that this is more readable.
        for(auto it: graph[elem]){
            if(!visited[it]){
                visited[it]=true;
                q.push(it);
            }
        }

    }

    //print the path
    cout<<"Traversal Followed Is"<<endl;
    for(auto i:path){
        cout<<i<<" ";
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


    //traverse BFS
    int s;
    cin>>s;
    BFS(adjList,s);
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