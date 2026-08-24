class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Convert stones into prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // DP value for the last possible move
        int dp = stones[n - 1];

        // Work backwards
        for (int i = n - 2; i > 0; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};