#include <map>
#include <set>

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> values;

    for (auto el : m) {
        values.insert(el.second);
    }

    return values;
}