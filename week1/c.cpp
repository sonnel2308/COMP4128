#include <bits/stdc++.h>

using namespace std;

double getNumBits(int nC2) {
    double res = (1 + sqrt(1 + 8 * nC2)) / 2;
    if (res == floor(res)) {
        return res;
    } else {
        return -1;
    }
}

int main() {
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    if (a == 0 && b == 0 && c == 0 && d == 0) {
        cout << "1\n";
        return 0;
    }

    int num0Bits = getNumBits(a);
    int num1Bits = getNumBits(d);

    if (num0Bits == -1 || num1Bits == -1 || num0Bits * num1Bits != b + c) {
        cout << "impossible\n";
        return 0;
    }
    // cout << "num0bits: " << num0Bits << " num1bits: " << num1Bits << "\n";

    vector<int> bitstring;
    while (num0Bits > 0 || num1Bits > 0) {
        if (num1Bits == 0) {
            bitstring.push_back(0);
            num0Bits--;
        } if (num0Bits == 0) {
            bitstring.push_back(1);
            num1Bits--;
        } else if ((b > c && b >= num1Bits) || (c > b && c < num1Bits)) {
            bitstring.push_back(0);
            num0Bits--;
            b -= num1Bits;
        } else {
            bitstring.push_back(1);
            num1Bits--;
            c -= num0Bits;
        }
    }

    for (auto i : bitstring) {
        cout << i;
    }
    cout << "\n";
}