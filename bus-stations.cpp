#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool has_in_stop (vector<string>& stops_list, string name) {
    for (auto bus : stops_list) {
        if (bus == name) {
            return true;
        }
    }

    return false;
}

void add_bus (string name, int count, map<string, vector<string>>& buses_dict, map<string, vector<string>>& stops_dict) {
    vector<string> stops(count);

    for (auto& stop : stops) {
        cin >> stop;

        if (!has_in_stop(stops_dict[stop], name)) {
            stops_dict[stop].push_back(name);
        }
    }

    buses_dict[name] = stops;
}

void show_buses_for_stop (string stop, map<string, vector<string>>& stops_dict) {
    if (stops_dict.count(stop) == 0) {
        cout << "No stop" << endl;
        return;
    }

    bool is_first = true;
    for (auto bus : stops_dict[stop]) {
        cout << (is_first ? "" : " ") << bus;
        is_first = false;
    }

    cout << endl;
}

void show_stops_for_bus (string bus, map<string, vector<string>>& buses_dict, map<string, vector<string>>& stops_dict) {
    if (buses_dict.count(bus) == 0) {
        cout << "No bus" << endl;
        return;
    }

    for (auto stop : buses_dict[bus]) {
        vector<string> buses_list;

        for (auto bus_name : stops_dict[stop]) {
            if (bus_name != bus) {
                buses_list.push_back(bus_name);
            }
        }

        cout << "Stop " << stop << ":";

        if (buses_list.empty()) {
            cout << " no interchange" << endl;
            continue;
        }

        for (auto bus_name : buses_list) {
            cout << " " << bus_name;
        }

        cout << endl;
    }
}

void show_all_buses (map<string, vector<string>>& buses_dict) {
    if (buses_dict.empty()) {
        cout << "No buses" << endl;
        return;
    }

    for (auto bus : buses_dict) {
        cout << "Bus " << bus.first << ":";

        for (auto stop : bus.second) {
            cout << " " << stop;
        }

        cout << endl;
    }
}

int main() {
    int count;
    cin >> count;

    map<string, vector<string>> buses_dict;
    map<string, vector<string>> stops_dict;

    for (int i = 0; i < count; i++) {
        string command;
        cin >> command;

        if (command == "NEW_BUS") {
            string name;
            cin >> name;

            int stops_count;
            cin >> stops_count;

            add_bus(name, stops_count, buses_dict, stops_dict);
        }

        if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;

            show_buses_for_stop(stop, stops_dict);
        }

        if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;

            show_stops_for_bus(bus, buses_dict, stops_dict);
        }

        if (command == "ALL_BUSES") show_all_buses(buses_dict);
    }

    return 0;
}
