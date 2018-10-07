#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <functional>

using namespace std;

class Person {
public:
    Person (const string& first_name, const string& last_name, const int& year) {
        ChangeFirstName(birth_year, first_name);
        ChangeLastName(birth_year, last_name);

        birth_year = year;
    }

    void ChangeFirstName(int year, const string& first_name) {
        years_to_name[year]["first_name"].push_back(first_name);
    }

    void ChangeLastName(int year, const string& last_name) {
        years_to_name[year]["last_name"].push_back(last_name);
    }

    string GetFullName(int year) const {
        if (year < birth_year) {
            return "No person";
        }

        vector<string> fst_names = GetLatest(year, "first_name");
        vector<string> lst_names = GetLatest(year, "last_name");

        return FormatName(fst_names, lst_names, [](vector<string> names){
            return names.back();
        });
    }

    string GetFullNameWithHistory(int year) const {
        if (year < birth_year) {
            return "No person";
        }

        vector<string> fst_names = GetHistory(year, "first_name");
        vector<string> lst_names = GetHistory(year, "last_name");

        return FormatName(fst_names, lst_names, [](vector<string> names){
            string result;
            for (int i = names.size() - 1; i >= 0; i--) {
                if (i == names.size() - 1) {
                    result += names[i];

                    if (names.size() > 1) {
                        result += " (";
                    }
                } else {
                    if (i != names.size() - 2) {
                        result += ", ";
                    }

                    result += names[i];
                }

                if (i == 0) {
                    if (names.size() > 1) {
                        result += ")";
                    }
                }
            }
            return result;
        });
    }
private:
    map<int, map<string, vector<string>>> years_to_name;
    int birth_year;

    vector<string> GetLatest (int year, string part) const {
        vector<string> name;
        for (auto year_to_name : years_to_name) {
            int current_year = year_to_name.first;

            vector<string> names = year_to_name.second[part];

            if (current_year <= year) {
                if (names.size()) {
                    name = names;
                }
            } else {
                return name;
            }
        }

        return name;
    }

    vector<string> GetHistory (int year, string part) const {
        vector<string> name;
        string prev;

        for (auto year_to_name : years_to_name) {
            int currentYear = year_to_name.first;
            vector<string> names = year_to_name.second[part];

            if (currentYear <= year) {
                if (names.size()) {
                    string value = names.back();

                    if (value != prev) {
                        name.push_back(value);
                    }

                    prev = value;
                }
            } else {
                return name;
            }
        }

        return name;
    }

    string FormatName (const vector<string>& fst_names, const vector<string>& lst_names, function<string(vector<string>)> f) const {
        if (fst_names.size()) {
            if (lst_names.size()) {
                return f(fst_names) + " " + f(lst_names);
            }

            return f(fst_names) + " with unknown last name";
        }

        if (lst_names.size()) {
            return f(lst_names) + " with unknown first name";
        }

        return "Incognito";
    }
};

int main () {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
