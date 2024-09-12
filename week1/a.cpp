#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string curr;
        cin >> curr;
        if (curr != to_string(i + 1) && curr != "mumble") {
            cout << "something is fishy\n";
            return 0;
        }
    }

    cout << "makes sense\n";
}