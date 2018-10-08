class Incognizable {
public:
    Incognizable() {}

    Incognizable(const int& a) {}

    Incognizable(const int& a, const int& b) {}
};

/*
 * struct Incognizable {
 *  int x = 0;
 *  int y = 0;
 * }
 */

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}