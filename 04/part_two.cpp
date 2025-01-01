#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int xmas_found = 0;
    vector<string> grid;

    ifstream file;
    string line;

    file.open("input.txt");

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        grid.push_back(line);
    }

    file.close();

    int rows;
    int cols;

    rows = grid.size();
    cols = grid[0].length();

    // perform the word search
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {

            if (grid[i][j] != 'A') {
                continue;
            }

            // search for diagonal X-MAS
            if (grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S') {
                if (grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S') {
                        xmas_found += 1;
                }
                else if (grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M') {
                        xmas_found += 1;
                }
            }
            else if (grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M') {
                if (grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S') {
                        xmas_found += 1;
                }
                else if (grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M') {
                        xmas_found += 1;
                }
            }
        }
    }

    cout << "Number of 'XMAS' found: " << xmas_found << "\n";

    return 0;
}
