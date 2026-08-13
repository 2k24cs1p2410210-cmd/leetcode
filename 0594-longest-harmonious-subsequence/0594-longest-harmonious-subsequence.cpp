class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int ans = 0;
        sort(begin(nums),end(nums));
        while(j<n){
            while(nums[j]-nums[i]>1){
                i++;
            }
            if(nums[j]-nums[i]==1){
            ans = max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};