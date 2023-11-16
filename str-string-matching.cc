#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        
        if (pattern[i] == pattern[len]) {

            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                
                len = lps[len - 1];
            } else {

                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    string pattern;
    int count = 0;
    
    cin >> str >> pattern;

    const int n = str.size();
    const int m = pattern.size();

    vector<int> lps = computeLPS(pattern);

    int i = 0;
    int j = 0;

    while (i < n) {

        if (pattern[j] == str[i]) {
            
            i++;
            j++;
        }

        if (j == m) {

            count++;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != str[i]) {
 
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    cout << count;

    return 0;
}
