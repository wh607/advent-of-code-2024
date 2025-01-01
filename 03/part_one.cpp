#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

int main() {
    int total_mult = 0;

    const regex regex_mul("mul\\(([0-9]+),([0-9]+)\\)");

    // read the input file
    ifstream file;
    file.open("input.txt");

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
    // match regex
    sregex_iterator words_begin(line.begin(), line.end(), regex_mul);
    sregex_iterator words_end;
    for (sregex_iterator i = words_begin; i != words_end; i++) {
        smatch match_mul = *i;
        // we have matched instances of "mul(x,y)""
        // where x is the first group, y is the second
        int x, y;
        x = stoi(match_mul[1].str()); // first group
        y = stoi(match_mul[2].str()); // second group

        total_mult += x * y;

        }
    }

    file.close();

    cout << "Total mult: " << total_mult << "\n";

    return 0;
}
