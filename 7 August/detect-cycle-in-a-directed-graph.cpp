class Solution {
  public:
  
    int dfs(vector<int>adj[], int v, int src, vector<bool>&visited, vector<bool>&dfscall){
        visited[src] = true;
        dfscall[src] = true;
        for(auto x: adj[src]){
            if(!visited[x] && dfs(adj,v,x,visited,dfscall))
                return 1;
            else if(dfscall[x]==true)
                return 1;
            }
        dfscall[src] = false;
        return 0;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,false),dfscall(V,false);
        int res = 0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                res = dfs(adj,V,i,visited,dfscall);
                if(res)
                    return 1;
            }
        }
        
        return 0;
    }
};