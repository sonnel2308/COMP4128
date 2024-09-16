#include <bits/stdc++.h>

using namespace std;

int main() {
    string grid[16];
    for (int i = 0; i < 16; i++) {
        cin >> grid[i];
    }

    vector<set<string>> wordsets;

    int nLines = 0;
    cin >> nLines;
    for (int i = 0; i < nLines; i++) {
        string word1 = "", word2 = "";
        cin >> word1;
        cin >> word2;
        
        // CASE: WHEN WORD ALSO APPEARS IN ANOTHER SET IT MUST BE DELETED
        bool found = false;
        for (int j = 0; j < wordsets.size(); j++) {
            if (wordsets[j].find(word1) != wordsets[j].end()) {
                found = true;
                wordsets[j].insert(word2);
            } else if (wordsets[j].find(word2) != wordsets[j].end()) {
                found = true;
                wordsets[j].insert(word1);
            }

            if (found) {
                // for (int k = j; k < wordsets.size(); k++) {
                //     if ()
                // }

                break;
            }
        }
        if (!found) {
            set<string> s = {word1, word2};
            wordsets.push_back(s);
        }
    }

    int nSize4Sets = 0;
    for (int i = 0; i < wordsets.size(); i++) {
        if (wordsets[i].size() >= 4) {
            nSize4Sets++;
        }
    }
    if (nSize4Sets < 4) {
        cout << "nSize4Sets: " << nSize4Sets << "\n";
        cout << "Impossible\n";
        return 0;
    }

    cout << "Possible\n";
    for (int i = 0; i < wordsets.size(); i++) {
        if (wordsets[i].size() < 4) {
            continue;
        }

        int j = 0;
        for (auto s : wordsets[i]) {
            if (j >= 4) {
                break;
            }
            j++;
            cout << s << " ";
        }
        cout << "\n";
    }
}