class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        int ans = 0;
        for (auto& [x, freq] : mp) {
            if (mp.count(x + 1)) {
                ans = max(ans, freq + mp[x + 1]);
            }
        }
        return ans;
        
    }
};