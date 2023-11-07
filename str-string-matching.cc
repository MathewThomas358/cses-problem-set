#include <bits/stdc++.h>

using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    string pattern;
    int count = 0;
    
    cin >> str >> pattern;

    const int patlen = pattern.size();

    if(patlen > str.size()) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i <= str.size() - patlen; i++) {

        if(pattern == str.substr(i, patlen))
            count++;
    }

    cout << count;

    return 0;
}