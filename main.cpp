#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string to_lower_word (const string& s) {
    string result;

    for (const auto& ch : s) {
        result += tolower(ch);
    }

    return result;
}

int main () {
    int count;
    cin >> count;

    vector<string> words(count);

    for (auto& el : words) {
        cin >> el;
    }

    sort(words.begin(), words.end(), [](string l, string r) {
        return to_lower_word(l) < to_lower_word(r);
    });

    for (int i = 0; i < words.size(); i++) {
        cout << (i == 0 ? "" : " ") << words[i];
    }

    cout << endl;

    return 0;
}