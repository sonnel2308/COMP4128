#include <bits/stdc++.h>

using namespace std;

int main() {
    // n days total, k coupons used
    long long nDays = 0, kCoupons = 0;
    cin >> nDays;
    cin >> kCoupons;

    long long curr_coupons = 0;
    long long deal = 1;
    long long bookings = 0;
    for (int i = 0; i < nDays; i++) {
        if (curr_coupons <= kCoupons) {
            curr_coupons += deal;
            deal++;
        } else {
            bookings++;
            curr_coupons--;
        }
    }

    cout << bookings << "\n";
}