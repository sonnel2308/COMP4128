#include <bits/stdc++.h>

using namespace std;

double getNumBits(int nC2) {
    if (nC2 == 0) return 0;
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

    int num0Bits = getNumBits(a);
    int num1Bits = getNumBits(d);

    if (num0Bits == -1 || num1Bits == -1) {
        cout << "impossible\n";
        return 0;
    }
    if (num0Bits == 0 && num1Bits > 0) {
        num0Bits = 1;
    } else if (num1Bits == 0 && num0Bits > 0) {
        num1Bits = 1;
    } else if (num0Bits * num1Bits != b + c) {
        cout << "impossible\n";
        return 0;
    } 
    cout << "num0bits: " << num0Bits << " num1bits: " << num1Bits << "\n";

    vector<int> bitstring;
    for (int i = 0; i < num0Bits; i++) {
        bitstring.insert(bitstring.begin() + i, 0);
    }

    int currFreq_1 = 0;
    while (currFreq_1 < num1Bits) {
        
    }

    cout << "possible\n";

}