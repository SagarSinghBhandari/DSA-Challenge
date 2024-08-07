#include<bits/stdc++.h>
using namespace std;
/*
		1 --- 3
	   /      | \
	  0       |   5 
	   \      | /
	    2 --- 4 
	    
*/
void DFS(vector<vector<int> >graph,vector<bool>&visited,int v, int src){
	visited[src] = true;
	int k = graph[src].size();
	for(int i=0; i<k; i++){
		if(!visited[graph[src][i]]){
			DFS(graph,visited,v,graph[src][i]);
		} 
	}
	cout<<src<<" ";
}
int main() {
	vector<vector<int> >graph;
	vector<int>adj;
	int src,node,v;
    cout << "Enter the number of vertices: \n";
    cin>>v;
    vector<bool>visited(v,false);
    for(int i=0; i<v; i++){
    	cout<<"Enter the node: ";
    	cin>>src;
    	adj.clear();
    	while(1){
    		cout<<"Enter the adjacent node (Enter -1 if no adjacent node): ";
    		cin>>node;
    		if(node==-1){
    			break;                                   
			}
            adj.push_back(node);
		}
		graph.push_back(adj);
	}
    cout << "The adjacency list is:\n";
    for(int i=0; i<v; i++){
    	cout<<"\n["<<i<<"]->";
    	for(int j=0; j<graph[i].size(); j++){
    		cout<<graph[i][j]<<"->";
		}
	}
	
	cout<<"\nDepth First Traversal is: ";
	DFS(graph,visited,v,0);
    return 0;
}
