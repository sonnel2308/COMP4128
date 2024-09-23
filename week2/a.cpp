#include <bits/stdc++.h>

using namespace std;

bool sortFinishTimes(pair<long long, long long> a, pair<long long, long long> b) {
    return a.second < b.second;
} 

int main() {
    // k classrooms; n activities
    long long n = 0, k = 0;
    cin >> n;
    cin >> k;

    vector<pair<long long, long long>> activities;
    for (long long i = 0; i < n; i++) {
        long long start = 0, finish = 0;
        cin >> start;
        cin >> finish;
        pair<long long, long long> activity = make_pair(start, finish);
        activities.push_back(activity);
    }

    sort(activities.begin(), activities.end(), sortFinishTimes);

    // rooms[i] = finish time of last activity in classroom i
    vector<long long> rooms;
    for (long long i = 0; i < k; i++) {rooms.push_back(0);}
    
    long long ans = 0;
    for (long long i = 0; i < activities.size(); i++) {
        for (long long j = 0; j < rooms.size(); j++) {
            if (rooms[j] < activities[i].first) {
                rooms[j] = activities[i].second;
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";
}