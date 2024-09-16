#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        int num_cards = 0;
        cin >> num_cards;
        for (int j = 0; j < num_cards; j++) {
            int card_type;
            cin >> card_type;
            map[card_type]++;
        }
    }

    // check if a full set can be made
    for (int i = 1; i <= m; i++) {
        if (map[i] == 0) {
            cout << 0 << "\n";
            return 0;
        }
    }

    int min = INT_MAX;
    for (const auto &[key, val] : map) {
        if (val < min) {
            min = val;
        }
    }
    cout << min << "\n";
}