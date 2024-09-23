#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "";
    cin >> s;
    int target_len = s.length();

    string t = "";
    string u = "";
    while (u.length() < target_len) {
        cout << "s: " << s << "\tt: " << t << "\tu:" << u << "\n";

        if (s.length() > 0 && (t.length() == 0 || s[0] < t[t.length() - 1])) {
            t += s[0];
            s.erase(0, 1);
        } else {
            u += t[t.length() - 1];
            t.erase(t.length() - 1, 1);
        }
    }

    cout << u << "\n";
}