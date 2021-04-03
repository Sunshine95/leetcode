class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        
        vector<vector<bool>> adj(n+1, vector<bool>(n+1, false));
        vector<int> degree(n+1, 0);
        int min_trio_degree = INT_MAX;
        
        for(vector<int> e : edges){
            int u = min(e[0], e[1]);
            int v = max(e[0], e[1]);
            
            adj[u][v] = true;
            
            degree[u]++;
            degree[v]++;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <=n; j++){
                if(!adj[i][j]) continue;
                
                for(int k = j+1; k <=n; k++){
                    if(!adj[j][k]) continue;
                                       
                    if(adj[i][k]){
                        // found a trio
                        int trio_degree = degree[i] + degree[j] + degree[k] - 6;
                        min_trio_degree = min(min_trio_degree, trio_degree);
                    }
                }
            }
        }
        
        return min_trio_degree == INT_MAX ? -1 : min_trio_degree;
        
    }
};