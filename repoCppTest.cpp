#include <bits/stdc++.h>
using namespace std;

int r, n; string s;
// dp[i] records the grow rates & corresponding max count at i
vector<unordered_map<int, int>> dp(n+1); // 1 -> n

int isS (int idx) {
    return s[idx-1] == 's' ? 1 : 0;
}

int findMaxCount (int idx) {
    int max_count = INT_MIN;
    for (auto p : dp[idx]) {
        max_count = max(max_count, p.second);
    }
    return max_count;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> r >> n >> s;

    dp[0].emplace(r, 0);

    for (int i = 0; i <= n; ++i) {
        if (dp[i].empty()) continue;
        // for all possible grow rates
        for (auto p : dp[i]) {
            // p.first = grow rates at node i
            // p.second = max count at the grow rate of p.first
            for (int cur_r = p.first-1; cur_r <= p.first+1; ++cur_r) {
                int dest = i + cur_r;
                if (dest > n) break;
                if (dp[dest].find(cur_r) == dp[dest].end())
                    dp[dest].emplace(cur_r, p.second+isS(dest));
                else
                    dp[dest][cur_r] = max(dp[dest][cur_r], p.second+isS(dest));
            }
        }
        if (i >= 1)
            cout << i << " " << findMaxCount(i) << endl;
    }

    cout << findMaxCount(n);

    return 0;
}
