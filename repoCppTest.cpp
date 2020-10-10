#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int isS (string& s, int idx) {
    return (s[idx-1] == 's') ? 1 : 0;
}

int main() {
    int r, n; string s;
    cin >> r >> n >> s;

    // dp[i] records the grow rates & corresponding max count at i
    vector<unordered_map<int, int>> dp(n+1); // node 0 -> n

    dp[0].emplace(r, 0);
    for (int i = 0; i <= n; ++i) {
        if (dp[i].empty()) continue;
        int max_count = INT_MIN;
        for (auto p : dp[i])
            max_count = max(max_count, p.second);
        cout << i << " " << max_count << endl;
        // for all possible pairs of grow_rate & max_count
        for (auto p : dp[i]) {
            // p.first = grow rates at node i
            // p.second = max count at the grow_rate of p.first
            for (int cur_r = p.first-1; cur_r <= p.first+1; ++cur_r) {
                if (cur_r <= 0) continue;
                int dest = i + cur_r;
                if (dest > n) break;
                if (dp[dest].empty() || dp[dest].find(cur_r) == dp[dest].end()) {
                    dp[dest].emplace(cur_r, p.second+isS(s, dest));
                }
                else
                    dp[dest][cur_r] = max(dp[dest][cur_r], p.second+isS(s, dest));
            }
        }
    }

    int max_count = INT_MIN;
    for (int i = 0; i <= n; ++i)
        for (auto p : dp[i]) {
            max_count = max(max_count, p.second);
        }
    cout << max_count;

    return 0;
}