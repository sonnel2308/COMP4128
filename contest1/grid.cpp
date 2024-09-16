#include <bits/stdc++.h>

using namespace std;

bool searchPair(vector<pair<string, string>> inputPairs, string word1, string word2) {
    for (auto &[curr1, curr2] : inputPairs) {
        if ((word1 == curr1 && word2 == curr2) || (word2 == curr1 && word1 == curr2)) {
            return true;
        }
    }
    return false;
}

vector<set<string>> insertWordPair(vector<set<string>> wordsets, string word1, string word2, vector<pair<string, string>> inputPairs) {
    bool inserted = false;
    for (int i = 0; i < wordsets.size(); i++) {
        for (auto str : wordsets[i]) {
            if (!(searchPair(inputPairs, word1, str) && searchPair(inputPairs, word2, str))) {
                continue;
            }
        }
        cout << "INSERTING PAIR: " << word1 << " " << word2 << " INTO SET [" << i << "]\n";
        wordsets[i].insert(word1);
        wordsets[i].insert(word2);
        inserted = true;
    }
    if (!inserted) {
        for (int i = 0; i < wordsets.size(); i++) {
            if (wordsets[i].size() == 0) {
                wordsets[i].insert(word1);
                wordsets[i].insert(word2);
                break;
            }
        }
    }
    return wordsets;
}

int main() {
    string grid[16];
    for (int i = 0; i < 16; i++) {
        cin >> grid[i];
    }

    vector<pair<string, string>> inputPairs;
    int nLines = 0;
    cin >> nLines;
    for (int i = 0; i < nLines; i++) {
        string word1 = "", word2 = "";
        cin >> word1;
        cin >> word2;
        pair<string, string> p = make_pair(word1, word2);
        inputPairs.push_back(p);
    }

    vector<set<string>> wordsets;
    for (int i = 0; i < 4; i++) {
        set<string> set;
        wordsets.push_back(set);
    }
    for (auto &[word1, word2] : inputPairs) {
        wordsets = insertWordPair(wordsets, word1, word2, inputPairs);
    }




    cout << "\n\n";
    for (int i = 0; i < wordsets.size(); i++) {
        cout << "wordset [" << i << "] size: " << wordsets[i].size() << "\n";
        for (auto s : wordsets[i]) {
            cout << s << " ";
        }
        cout << "\n";
    }
}