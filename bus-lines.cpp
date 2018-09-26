#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {
    int commands_count;
    cin >> commands_count;

    map<vector<string>, int> lines;

    for (size_t i = 0; i < commands_count; i++) {
        int stops_count;
        cin >> stops_count;

        vector<string> stops(stops_count);

        for (auto& stop : stops) {
            cin >> stop;
        }

        if (lines.count(stops) > 0) {
            cout << "Already exists for " << lines[stops] << endl;
            continue;
        }

        int id = lines.size() + 1;
        lines[stops] = id;

        cout << "New bus " << id << endl;
    }

    return 0;
}