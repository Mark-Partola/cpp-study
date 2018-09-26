#include <iostream>
#include <set>

using namespace std;

int main () {
    short count;
    cin >> count;

    set<string> values;

    for (size_t i = 0; i < count; i++) {
        string s;
        cin >> s;

        values.insert(s);
    }

    cout << values.size() << endl;

    return 0;
}