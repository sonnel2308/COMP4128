#include <bits/stdc++.h>

using namespace std;

bool sortFinishTimes(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
} 

int main() {
    // k classrooms; n activities
    int n = 0, k = 0;
    cin >> n;
    cin >> k;

    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        int start = 0, finish = 0;
        cin >> start;
        cin >> finish;
        pair<int, int> activity = make_pair(start, finish);
        activities.push_back(activity);
    }

    sort(activities.begin(), activities.end(), sortFinishTimes);
    // for (auto i : activities) {
    //     cout << "(" << i.first << ", " << i.second << ") ";
    // }
    // cout << "\n";

    // rooms[i] = finish time of last activity in classroom i
    vector<int> rooms;
    for (int i = 0; i < k; i++) {rooms.push_back(0);}
    
    int ans = 0;
    for (int i = 0; i < activities.size(); i++) {
        for (int j = 0; j < rooms.size(); j++) {
            if (rooms[j] < activities[i].first) {
                rooms[j] = activities[i].second;
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";
}