class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(begin(temp),end(temp));
        unordered_map<int,int>rank;
        int r = 1;
        for(int x:temp){
            if(rank.find(x)==rank.end()){
                rank[x] = r++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};