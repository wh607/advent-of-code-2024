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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // if not a start/end character, move on
            if (grid[i][j] != 'X' && grid[i][j] != 'S') {
                continue;
            }

            // left -> right (horizontal)
            // do not search if too close to right
            if (j <= cols - 4) {
                // search for XMAS
                if (grid[i][j] == 'X') {
                    if (grid[i][j + 1] == 'M') {
                        if (grid[i][j + 2] == 'A') {
                            if (grid[i][j + 3] == 'S') {
                                xmas_found += 1;
                            }
                        }
                    }
                }
                // search for SAMX
                else if (grid[i][j] == 'S') {
                    if (grid[i][j + 1] == 'A') {
                        if (grid[i][j + 2] == 'M') {
                            if (grid[i][j + 3] == 'X') {
                                xmas_found += 1;
                            }
                        }
                    }
                }
            }

            // up -> down (vertical)
            // do not search if too close to bottom
            if (i <= rows - 4) {
                // search for XMAS
                if (grid[i][j] == 'X') {
                    if (grid[i + 1][j] == 'M') {
                        if (grid[i + 2][j] == 'A') {
                            if (grid[i + 3][j] == 'S') {
                                xmas_found += 1;
                            }
                        }
                    }
                }
                // search for SAMX
                else if (grid[i][j] == 'S') {
                    if (grid[i + 1][j] == 'A') {
                        if (grid[i + 2][j] == 'M') {
                            if (grid[i + 3][j] == 'X') {
                                xmas_found += 1;
                            }
                        }
                    }
                }
            }

            // top left -> bottom right (diagonal)
            // do not search if too close to bottom or right
            if (i <= rows - 4 && j <= cols - 4) {
                // search for XMAS
                if (grid[i][j] == 'X') {
                    if (grid[i + 1][j + 1] == 'M') {
                        if (grid[i + 2][j + 2] == 'A') {
                            if (grid[i + 3][j + 3] == 'S') {
                                xmas_found += 1;
                            }
                        }
                    }
                }
                // search for SAMX
                else if (grid[i][j] == 'S') {
                    if (grid[i + 1][j + 1] == 'A') {
                        if (grid[i + 2][j + 2] == 'M') {
                            if (grid[i + 3][j + 3] == 'X') {
                                xmas_found += 1;
                            }
                        }
                    }
                }
            }

            // top right -> bottom left (diagonal)
            // do not search if too close to bottom or left
            if (i <= rows - 4 && j >= 3) {
                // search for XMAS
                if (grid[i][j] == 'X') {
                    if (grid[i + 1][j - 1] == 'M') {
                        if (grid[i + 2][j - 2] == 'A') {
                            if (grid[i + 3][j - 3] == 'S') {
                                xmas_found += 1;
                            }
                        }
                    }
                }
                // search for SAMX
                else if (grid[i][j] == 'S') {
                    if (grid[i + 1][j - 1] == 'A') {
                        if (grid[i + 2][j - 2] == 'M') {
                            if (grid[i + 3][j - 3] == 'X') {
                                xmas_found += 1;
                            }
                        }
                    }
                }
            }

        }
    }

    cout << "Number of 'XMAS' found: " << xmas_found << "\n";

    return 0;
}
// 0 1 2 3 4 5 6 7 8
// y y y y y y n n n
