class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int i, int M) {

        // Can take all remaining piles
        if (i >= n)
            return 0;

        if (2 * M >= n - i)
            return suffix[i];

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M; X++) {

            int newM = max(M, X);

            // Current player gets:
            // remaining stones - opponent's maximum
            int current = suffix[i] - solve(i + X, newM);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // suffix[i] = total stones from i to n-1
        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        // dp[i][M]
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};