class Solution {
public:
    bool checkBipartite(vector<vector<int>>&graph,int u,vector<int>&color,int curr_color){
        color[u] = curr_color;
        for(int &v:graph[u]){
            if(color[v]==color[u])
            return false;
            if(color[v]==-1){
                int colorOfv = 1-curr_color;
                if(checkBipartite(graph,v,color,colorOfv)==false)
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        // unordered_map<int,vector<int>>adj;
        // for(auto &edge:graph){
        //     int a = edge[0];
        //     int b = edge[1];

        //     adj[a].push_back(b);
        //     adj[b].push_back(a);
        // }
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