class Solution {
public:
    struct Node {
        int start, end, weight, index;
    };

    struct State {
        long long score = 0;
        array<int, 4> indices{};
        int len = 0;
    };

    bool smaller(const State& a, const State& b) {
        int n = min(a.len, b.len);

        for (int i = 0; i < n; i++) {
            if (a.indices[i] != b.indices[i]) {
                return a.indices[i] < b.indices[i];
            }
        }

        return a.len < b.len;
    }

    State addIndex(State s, int idx) {
        int pos = s.len;

        while (pos > 0 && s.indices[pos - 1] > idx) {
            s.indices[pos] = s.indices[pos - 1];
            pos--;
        }

        s.indices[pos] = idx;
        s.len++;

        return s;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<Node> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](const Node& x, const Node& y) {
            if (x.start != y.start) {
                return x.start < y.start;
            }

            if (x.end != y.end) {
                return x.end < y.end;
            }

            return x.index < y.index;
        });

        vector<int> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i].start;
        }

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin() + i + 1,
                starts.end(),
                a[i].end
            ) - starts.begin();
        }

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                State skip = dp[i + 1][k];

                State take = dp[nxt[i]][k - 1];
                take.score += a[i].weight;
                take = addIndex(take, a[i].index);

                if (take.score > skip.score) {
                    dp[i][k] = take;
                }
                else if (take.score < skip.score) {
                    dp[i][k] = skip;
                }
                else {
                    if (smaller(take, skip)) {
                        dp[i][k] = take;
                    }
                    else {
                        dp[i][k] = skip;
                    }
                }
            }
        }

        vector<int> result;

        for (int i = 0; i < dp[0][4].len; i++) {
            result.push_back(dp[0][4].indices[i]);
        }

        return result;
    }
};