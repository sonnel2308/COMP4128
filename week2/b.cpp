#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "";
    cin >> s;
    long long target_len = s.length();

    vector<int> right_lex_min;
    right_lex_min.reserve(target_len);
    for (int i = 0; i < target_len; i++) right_lex_min.push_back(0);
    char curr_min = 'z';
    for (int i = right_lex_min.size() - 1; i >= 0; i--) {
        // cout << "I:" << i << "\t" << s[i] << " < " << curr_min << "? " << (s[i] < curr_min) << "\n";
        if (s[i] < curr_min) {
            curr_min = s[i];
        }
        right_lex_min[i] = curr_min;
    }
    // for (int i = 0; i < right_lex_min.size(); i++) {
    //     cout << right_lex_min[i] << " ";
    // }
    // cout << "\n";

    string t = "";
    string u = "";
    int curr_index = 0;
    while (u.length() < target_len) {
        // cout << "s: " << s << "\tt: " << t << "\tu:" << u << "\t" << "curr_index: " << curr_index << "\t" << int(s[0]) << ">" << right_lex_min[curr_index] << "? " << (s[0] > right_lex_min[curr_index]) << "\n";
        if (s.length() == 0 || (t.length() > 0 && t[t.length() - 1] < right_lex_min[curr_index])) {
            u += t[t.length() - 1];
            t.erase(t.length() - 1, 1);
        } else {
            t += s[0];
            s.erase(0, 1);
            if (curr_index < target_len) curr_index++;
        }
    }

    cout << u << "\n";
}