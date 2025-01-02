#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// custom sort function
bool comp(int a, int b, const multimap<int, int>& rules) {
    if (a == b) {
        return false;
    }

    // use map to lookup whether a < b
    auto lookup = rules.equal_range(a);

    for (auto it = lookup.first; it != lookup.second; ++it) {
        if (it->second == b) {
            return true; // a < b
        }
    }
    // we didn't find a < b in the lookup so we must have a > b
    return false;
}

int main() {
    int sum_middle = 0;

    multimap <int, int> rules;
    vector<vector<int> > pages;
    const string delimiter = "|";

    // read in the page ordering rules
    ifstream file;
    string line;

    file.open("input.txt");

    bool reading_rules = true;

    while (getline(file, line)) {
        // first read the rules
        if (reading_rules) {
            if (line.empty()) {
                reading_rules = false; // reached end of rules
                continue;
            }

            // read first and second numbers from "x|y"
            int first = stoi(line.substr(0, line.find(delimiter)));
            int second = stoi(line.substr(line.find(delimiter) + 1, line.length()));

            rules.insert(pair<int, int>(first, second));
        } else {
        // then read the page numbers
        if (line.empty()) {
            continue;
        }

        vector<int> page;
        istringstream ss(line);
        string num;

        // extract integers from stream into vector
        while (getline(ss, num, ',')) {
            page.push_back(stoi(num));
        }

        // push the vector back into pages
        pages.push_back(page);

        }
    }

    file.close();

    // sort the vectors & get middle number
    for (int i = 0; i < pages.size(); i++) {
        // check that the pages are incorrectly ordered
        if (!is_sorted(pages[i].begin(), pages[i].end(), [&rules](int a, int b) {return comp(a, b, rules);})) {
            // sort according to rules
            sort(pages[i].begin(), pages[i].end(), [&rules](int a, int b) {return comp(a, b, rules);});
            // find the middle value and sum
            sum_middle += pages[i][pages[i].size()/2];
        }
    }

    cout << "Sum of middle page numbers: " << sum_middle << "\n";

    return 0;
}
