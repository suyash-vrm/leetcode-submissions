class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        long long dp = 1;   // empty subsequence
        long long last[26] = {};

        for (char c : s) {
            int x = c - 'a';

            long long oldDp = dp;

            dp = (2 * dp - last[x] + MOD) % MOD;

            last[x] = oldDp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};