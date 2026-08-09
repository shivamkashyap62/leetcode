class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int i, int M, vector<int>& piles) {

        // No piles left
        if (i >= n)
            return 0;

        // We can take all remaining piles
        if (2 * M >= n - i)
            return suffix[i];

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M; X++) {

            int nextM = max(M, X);

            // Current player's score =
            // total remaining - opponent's best score
            int currentScore =
                suffix[i] - solve(i + X, nextM, piles);

            ans = max(ans, currentScore);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // suffix[i] = sum of piles[i...n-1]
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // M can be at most n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles);
    }
};
