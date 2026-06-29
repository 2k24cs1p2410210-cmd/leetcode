class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        sort(arr.begin(),arr.end());
        unordered_map<int,long long>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=1;
        }
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int num = arr[i]/arr[j];
                    if(mp.find(num)!=mp.end()){
                        long long mul = mp[arr[j]]*mp[num]%mod;
                        mp[arr[i]] = (mp[arr[i]]+mul)%mod;
                    }
                }
            }
        }
        long long count = 0;
        for(auto it:mp){
            count+=it.second;
        }
        return count%mod;
    }
};