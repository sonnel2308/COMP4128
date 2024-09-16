#include <bits/stdc++.h>

using namespace std;

int main() {
    int nRows;
    string word;
    cin >> nRows;
    cin >> word;

    int remainingChars = word.length();
    vector<int> rows;
    for (int i = 0; i < nRows; i++) {
        rows.insert(rows.begin() + i, 0);
    }

    int i = 0;
    // up = true, down = false
    bool direction = false;
    while (remainingChars > 0) {
        rows[i]++;
        remainingChars--;
        
        if (i == nRows - 1 && direction == false) {
            direction = true;
        } else if (i == 0 && direction == true) {
            direction = false;
        }

        if (direction) {
            i--;
        } else {
            i++;
        }
    }

    vector<string> substrings;
    for (int i = 0; i < nRows; i++) {
        substrings.insert(substrings.begin() + i, "");
    }

    int curr_row = 0;
    int curr_len = 0;
    for (int i = 0; i < word.length(); i++) {
        if (curr_len > rows[curr_row] - 1) {
            curr_row++;
            curr_len = 0;
        }

        substrings[curr_row] += word[i];
        curr_len++;
    }

    string res = "";
    vector<int> curr_index;
    for (int i = 0; i < nRows; i++) {
        curr_index.insert(curr_index.begin() + i, 0);
    }

    int curr_substring = 0;
    // right = true, left = false
    direction = true;
    remainingChars = word.length();
    while (remainingChars > 0) {
        if (curr_index[curr_substring] < substrings[curr_substring].length()) {
            res += substrings[curr_substring][curr_index[curr_substring]];
            curr_index[curr_substring]++;
            remainingChars--;
        }
        
        if (curr_substring == nRows - 1 && direction == true) {
            direction = false;
        } else if (curr_substring == 0 && direction == false) {
            direction = true;
        }

        if (direction) {
            curr_substring++;
        } else {
            curr_substring--;
        }
    }

    cout << res << "\n";
}