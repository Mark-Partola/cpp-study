#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Lambda:
 * syntax [](){}
 * [] - capturing.
 *  - [a, b] - use
 *  - [=] - copy parent scope
 *  - [&] - all by reference
 *  - [&, i] - all by ref, but i by value
 *  - [=, &i] - all by val, but i by ref
 * []() -> int {} - explicit return type
 */

void print (const vector<int>& values) {
    for (int i = 0; i < values.size(); i++) {
        bool is_last = i == (values.size() - 1);
        cout << values[i] << (is_last ? "" : " ");
        if (is_last) cout << endl;
    }
}

int main () {
    int count;
    cin >> count;

    vector<int> values(count);

    for (auto& el : values) {
        cin >> el;
    }

    sort(values.begin(), values.end(), [](int a, int b) {
        return (abs(b) - abs(a)) > 0;
    });

    print(values);

    return 0;
}