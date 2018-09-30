#include <iostream>
#include <set>
#include <map>

using namespace std;

int main () {
    int count_commands;
    cin >> count_commands;

    map<set<string>, int> lines;

    for (size_t i = 0; i < count_commands; i++) {
        int count_stops;
        cin >> count_stops;

        set<string> stops;

        for (size_t j = 0; j < count_stops; j++) {
            string stop;
            cin >> stop;

            stops.insert(stop);
        }

        if (lines.count(stops) > 0) {
            cout << "Already exists for " << lines[stops] << endl;
        } else {
            int line_number = lines.size() + 1;
            lines[stops] = line_number;
            cout << "New bus " << line_number << endl;
        }
    }

    return 0;
}