class Solution {
public:
int reverse(int n){
    int sum = 0;
    while(n>0){
    int rem = n%10;
    sum = sum*10+rem;
    n = n/10;
    }
    return sum;
}
    int countNicePairs(vector<int>& nums) {
        long long mod = 1e9+7;
        unordered_map<int,long long>mp;
        long long result= 0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i] - reverse(nums[i]);
            if(mp.find(num)!=mp.end()){
                result = result+mp[num];
            }
            mp[num]++;
        }
        return result%mod;
    }
};