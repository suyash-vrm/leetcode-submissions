class Solution {
public:
    struct State {
        long long score;
        vector<int> ids;
    };

    // Returns the better of two states
    State better(State a, State b) {
        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        // Same score -> lexicographically smaller indices
        if (a.ids != b.ids)
            return (a.ids < b.ids ? a : b);

        return a;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store:
        // [left, right, weight, original_index]
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        // right endpoints for binary search
        vector<long long> rights(n);

        for (int i = 0; i < n; i++)
            rights[i] = a[i][1];

        // prev[i] = last index j < i such that
        // a[j].right < a[i].left
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            int l = a[i][0];

            int j = lower_bound(rights.begin(),
                                rights.begin() + i,
                                l) - rights.begin();

            prev[i] = j - 1;
        }

        // dp[i][k]:
        // best result using first i intervals,
        // choosing at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {

            // Don't take interval i-1
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
            }

            // Take interval i-1
            for (int k = 1; k <= 4; k++) {

                State take;

                take.score = a[i - 1][2];

                int p = prev[i - 1];

                if (p >= 0) {
                    take.score += dp[p + 1][k - 1].score;
                    take.ids = dp[p + 1][k - 1].ids;
                }

                take.ids.push_back((int)a[i - 1][3]);

                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(dp[i][k], take);
            }
        }

        return dp[n][4].ids;
    }
};