class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int minn=INT_MAX;
        int maxn=INT_MIN;
        for(auto x:nums){
            minn=min(minn,x);
            maxn=max(maxn,x);
        }
        return gcd(minn,maxn);
    }
};