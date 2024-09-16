#include <bits/stdc++.h>

using namespace std;

double checkNumBits(int nC2) {
    double res = (1 + sqrt(1 + 8 * nC2)) / 2;
    if (res == floor(res)) {
        return res;
    } else {
        return -1;
    }
}

int getFreq_10(vector<int> bitstring) {
    int res = 0;
    int currFreq_0 = 0;
    for (int i = bitstring.size() - 1; i >= 0; i--) {
        if (bitstring[i] == 0) {
            currFreq_0++;
        } else {
            res += currFreq_0;
        }
    }
    return res;
}

int getFreq_01(vector<int> bitstring) {
    int res = 0;
    int currFreq_1 = 0;
    for (int i = bitstring.size() - 1; i >= 0; i--) {
        if (bitstring[i] == 1) {
            currFreq_1++;
        } else {
            res += currFreq_1;
        }
    }
    return res;
}

tuple<bool, vector<int>> shiftRight_1(vector<int> bitstring) {
    bool success = false;
    for (int i = bitstring.size() - 1; i >= 0; i--) {
        if (i < bitstring.size() - 1 && bitstring[i] == 1 && bitstring[i + 1] == 0) {
            bitstring[i] = 0;
            bitstring[i + 1] = 1;
            success = true;
            break;
        }
    }
    return make_tuple(success, bitstring);
}

tuple<bool, vector<int>> shiftLeft_1(vector<int> bitstring) {
    bool success = false;
    for (int i = 0; i < bitstring.size(); i++) {
        if (i > 0 && bitstring[i] == 1 && bitstring[i - 1] == 0) {
            bitstring[i] = 0;
            bitstring[i - 1] = 1;
            success = true;
            break;
        }
    }
    return make_tuple(success, bitstring);
}


int main() {
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    if (a == 1 && b == 0 && c == 0 && d == 0) {
        cout << "00\n";
        return 0;
    } else if (d == 1 && a == 0 && b == 0 && c == 0) {
        cout << "11\n";
        return 0;
    }

    int num0Bits = checkNumBits(a);
    int num1Bits = checkNumBits(d);
    if (num0Bits == -1 || num1Bits == -1) {
        cout << "impossible\n";
        return 0;
    }

    vector<int> bitstring;
    int freq_0 = 0;
    int freq_1 = 0;
    int bitFlag = 0;
    for (int i = 0; i < num0Bits + num1Bits; i++) {
        bitstring.insert(bitstring.begin() + i, bitFlag);
        if (bitFlag == 0) {
            freq_0++;
        } else {
            freq_1++;
        }

        if (bitFlag == 0 && freq_1 < num1Bits) {
            bitFlag = 1;
        } else if (bitFlag == 1 && freq_0 < num0Bits) {
            bitFlag = 0;
        }
    }

    int freq_01 = getFreq_01(bitstring);
    int freq_10 = getFreq_10(bitstring);
    if (freq_01 + freq_10 != b + c) {
        cout << "impossible\n";
        return 0;
    }

    while (freq_01 != b && freq_10 != c) {
        for (int i = 0; i < bitstring.size(); i++) {
            cout << bitstring[i];
        }
        cout << "\n";
        
        if (freq_01 < b) {
            tuple<bool, vector<int>> t = shiftRight_1(bitstring);
            if (!get<0>(t)) {
                cout << "impossible\n";
                return 0;
            } else {
                bitstring = get<1>(t);
                freq_01++;
                freq_10--;
            }
        } else if (freq_10 < c) {
            tuple<bool, vector<int>> t = shiftLeft_1(bitstring);
            if (!get<0>(t)) {
                cout << "impossible\n";
                return 0;
            } else {
                bitstring = get<1>(t);
                freq_10++;
                freq_01--;
            }
        }
    }

    for (int i = 0; i < bitstring.size(); i++) {
        cout << bitstring[i];
    }
    cout << "\n";
}