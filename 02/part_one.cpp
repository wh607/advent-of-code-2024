#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// for sorting descending
bool comp(int a, int b) {
      return a > b;
}

int main() {
    // open the input file
    ifstream file;
    file.open("input.txt");
    // read line by line, each line is a report
    string line;

    int safe_reports = 0;

    while (getline(file, line))  {
        if (line.empty()) {
            continue; // handle empty lines
        }

        vector<int> report;
        // create string stream from current line
        istringstream stream(line);

        int num;
        // extract integers from stream
        // and put into the vector
        while (stream >> num) {
            report.push_back(num);
        }

        // check if the report is safe
        bool isSafe = true;

        bool isIncreasing = false;
        bool isDecreasing = false;

        // check if sequence is increasing/decreasing
        isIncreasing = is_sorted(report.begin(), report.end());
        isDecreasing = is_sorted(report.begin(), report.end(), comp);

        if (!isIncreasing && !isDecreasing) {
            // levels not increasing or decreasing
            isSafe = false; // report not safe
        } else {
            for (int i = 1; i < report.size(); i++) {
                if (abs(report[i] - report[i-1]) > 3) {
                    isSafe = false; // report not safe
                }
                else if (report[i] == report[i-1]) {
                    isSafe = false; // report not safe
                }
            }
        }

        if (isSafe) {
            safe_reports += 1;
        }

        for (int i = 0; i < report.size(); i++) {
            cout << report[i] << " ";
        }
        cout << isSafe << "\n";
    }

    // close the input file
    file.close();

    cout << "Number of safe reports: " << safe_reports << "\n";

    return 0;
}
