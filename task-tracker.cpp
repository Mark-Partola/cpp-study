#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count;

    cin >> count;

    int current_month = 0;
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> month(days[0]);
    vector<string> result;

    for (int i = 0; i < count; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string task;
            int day;
            cin >> day >> task;

            month[day - 1].push_back(task);
        } else if (command == "NEXT") {
            int next_month;

            if (current_month + 1 < days.size()) {
                next_month = ++current_month;
            } else {
                next_month = 0;
                current_month = 0;
            }

            int next_count = days[next_month];
            int curr_count = month.size();

            int diff = curr_count - next_count;

            if (diff > 0) {
                vector<string> tasks;
                for (int j = 0; j < diff; j++) {
                    vector<string> moving_tasks = month[month.size() - diff + j];
                    tasks.insert(end(tasks), begin(moving_tasks), end(moving_tasks));
                }

                month.resize(next_count);
                vector<string>& last_day_tasks = month[month.size() - 1];
                last_day_tasks.insert(end(last_day_tasks), begin(tasks), end(tasks));
            } else {
                month.resize(next_count);
            }
        } else if (command == "DUMP") {
            int day;
            cin >> day;
            vector<string> tasks = month[day - 1];
            string res;

            res += to_string(tasks.size());

            for (string task : tasks) {
                res += " " + task;
            }

            result.push_back(res);
        }
    }

    for (auto value : result) {
        cout << value << endl;
    }

    return 0;
}
