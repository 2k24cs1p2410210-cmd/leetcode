class Solution {
public:
    bool checkBipartite(vector<vector<int>>&graph,int node,vector<int>&color,int curr_color){
        queue<int>q;
        q.push(node);
        color[node] = curr_color;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v:graph[u]){
                if(color[v]==color[u]){
                    return false;
                }
                if(color[v]==-1){
                    color[v] = 1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int>color(N,-1);
        for(int i=0;i<N;i++){
            if(color[i]==-1){
            if(checkBipartite(graph,i,color,1)==false){
                return false;
            }
            }
        }
        return true;
    }
};