#include <vector>
#include <iostream>

#define NL "\n"

using std::vector;
using std::cout;
using std::cin;
using std::string;

const int MOD = 1000000007;

int main() {
    string s;
    int k;
    cin >> s >> k;

    vector<string> words(k);
    for (int i = 0; i < k; i++) {
        cin >> words[i];
    }

    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            int len = words[j].length();
            if (i >= len && s.substr(i - len, len) == words[j]) {
                dp[i] = (dp[i] + dp[i - len]) % MOD;
            }
        }
    }

    cout << dp[n] << NL;
    return 0;
}
