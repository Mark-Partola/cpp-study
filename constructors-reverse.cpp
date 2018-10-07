#include <iostream>
#include <string>

using namespace std;

class ReversibleString {
public:
    ReversibleString () {}

    ReversibleString (const string& s) {
        value = s;
    }

    void Reverse () {
        string reversed;

        for (int i = value.size() - 1; i >= 0; i--) {
            reversed += value[i];
        }

        value = reversed;
    }

    string ToString () const {
        return value;
    }

private:
    string value;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
