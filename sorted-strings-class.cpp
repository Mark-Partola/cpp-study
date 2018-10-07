#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        words.push_back(s);
    }

    vector<string> GetSortedStrings() {
        sort(words.begin(), words.end());

        return words;
    }

private:
    vector<string> words;
};

int main () {
    SortedStrings ss;
    ss.AddString("a");
    ss.AddString("hello");
    ss.AddString("a");
    ss.AddString("bbb");
    ss.AddString("zzZ");

    ss.GetSortedStrings();

    bool is_first = true;
    for (const auto& s : ss.GetSortedStrings()) {
        cout << (is_first ? "" : " ") << s;
        is_first = false;
    }
    cout << endl;

    return 0;
}