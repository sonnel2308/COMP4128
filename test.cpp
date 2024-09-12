#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";

    // cout << INT_MAX << "\n";
    // cout << pow(2, 32) << "\n";
}