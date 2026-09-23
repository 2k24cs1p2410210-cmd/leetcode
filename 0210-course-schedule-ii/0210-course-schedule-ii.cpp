class Solution {
public:
    vector<int>topologicalSequenceFind(unordered_map<int,vector<int>>&adj,int n,vector<int>&indegree,vector<int>&ans){
        queue<int>q;
        int count = 0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
                ans.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    ans.push_back(v);
                    count++;
                }
            }
        }
        if(count==n)
        return ans;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &vec:prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        vector<int>ans;
        return topologicalSequenceFind(adj,numCourses,indegree,ans);
        
    }
};