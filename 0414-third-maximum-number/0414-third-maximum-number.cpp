class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>,less<int>>pq;
        unordered_set<int>st;
        for(int x:nums){
            st.insert(x);
        }
        for(int x:st){
            pq.push(x);
        }
        int maxi = pq.top();
        if(st.size()<3){
            return maxi;
        }
        pq.pop();
        pq.pop();
        return pq.top();
        
    }
};