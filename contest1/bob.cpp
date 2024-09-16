#include <bits/stdc++.h>

using namespace std;

bool mySort(pair<long long, long long> a, pair<long long, long long> b) {
    // return (get<1>(a) - get<0>(a)) > (get<1>(b) - get<0>(b));
    return get<0>(a) < get<0>(b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> jobs;
    for (int i = 0; i < n; i++) {
        pair<long long, long long> job;
        long long w = 0, t = 0;
        cin >> w;
        cin >> t;

        jobs.insert(jobs.begin() + i, make_pair(w, t));
    }

    sort(jobs.begin(), jobs.end(), mySort);

    long long curr_days = 0;
    long long res = 0;
    for (auto &[w, t] : jobs) {
        curr_days += w;
        res += t - curr_days;
    }

    cout << res << '\n';
}