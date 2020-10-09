void dfs(int u){
    cout << u << " ";
    visited[u] = 1;
    for (int i=0; i<AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if (visited[v] == 0) dfs(v);
    }
}