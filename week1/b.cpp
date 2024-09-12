#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> nums;
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            nums.push_back(val);
        }

        long long res = 0;
        int curr_max = nums[0];
        for (int j = 0; j < n; j++) {
            // if sign changes from j - 1 to j
            if (j > 0 && ((nums[j] >= 0 && nums[j - 1] < 0) || (nums[j] < 0 && nums[j - 1] >= 0))) {
                res += curr_max;
                curr_max = nums[j];
            } else {
                curr_max = max(curr_max, nums[j]);
            }
        }

        res += curr_max;

        cout << res << "\n";
    }
}