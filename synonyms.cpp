#include <iostream>
#include <set>
#include <map>

using namespace std;

int main () {
    int commands_count;
    cin >> commands_count;

    map<string, set<string>> words;

    for (size_t i = 0; i < commands_count; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string w1, w2;
            cin >> w1 >> w2;

            words[w1].insert(w2);
            words[w2].insert(w1);
        } else if (command == "COUNT") {
            string word;
            cin >> word;
            cout << words[word].size() << endl;
        } else if (command == "CHECK") {
            string w1, w2;
            cin >> w1 >> w2;

            cout << (words[w1].count(w2) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}