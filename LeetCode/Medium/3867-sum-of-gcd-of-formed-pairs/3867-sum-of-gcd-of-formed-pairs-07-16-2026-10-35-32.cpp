class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long>prefixGcd;
        long long maxi=nums[0];
        prefixGcd.push_back(__gcd((long long)nums[0],maxi));
        for(int i=1;i<nums.size();i++){
            maxi = max(maxi,(long long)nums[i]);
            prefixGcd.push_back(__gcd((long long)nums[i],maxi));
        }
    
    sort(prefixGcd.begin(),prefixGcd.end());
    long long start = 0;
    long long end   = prefixGcd.size()-1;
    long long sum = 0;
        while(start<end){
            sum+=__gcd(prefixGcd[start],prefixGcd[end]);
            start++;
            end--;
        }
    return sum;
    }
    
};