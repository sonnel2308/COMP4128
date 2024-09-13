#include <bits/stdc++.h>

using namespace std;

int calc_n(int nCk) {
    double res = (1 + sqrt(1 + 8 * nCk)) / 2;
    if (res == floor(res)) {
        return res;
    } else {
        return 0;
    }
}

int main() {
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;


    // build the bitstring
    int num_zeroes = calc_n(a);
    if (num_zeroes == -1) {
        cout << "impossible\n";
        return -1;
    }
    string bitstring = string(num_zeroes, '0');
    int i = b;
    while (i) {
        if (i > num_zeroes) {
            bitstring += '1';
            i -= num_zeroes;
        } else {
            string temp;
            for (int j = 0; j < bitstring.length(); j++) {
                if (j == i) {
                    temp += "1";
                }
                temp += bitstring[j];
            }
            bitstring = temp;
            break;
        }
    }

    // check if "10" substring frequency is valid
    int freq_10 = 0;
    bool if_1 = false;
    for (int i = 0; i < bitstring.length(); i++) {
        if (bitstring.c_str()[i] == '1') {
            if_1 = true;
        } else if (if_1) {
            freq_10++;
        }
    }
    if (freq_10 != c) {
        cout << "impossible\n";
        return 0;
    }

    // check if "11" substring frequency is valid
    int num_ones = count(bitstring.begin(), bitstring.end(), '1');
    int freq_11 = (num_ones * (num_ones - 1)) / 2;
    if (freq_11 != d) {
        cout << "impossible\n";
        return 0;
    }

    cout << bitstring << "\n";
}