#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::vector<std::string> map;
    std::ifstream file;
    std::string line;

    file.open("input.txt");
    while (getline(file, line)) {
        if (line.empty()) {
            break;
        }

        map.push_back(line);
    }

    // locate guard
    int rows, cols;
    rows = map.size();
    cols = map[0].length();

    int x, y;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == '^') {
                map[i][j] = 'X'; // include starting pos
                x = j;
                y = i;
                break;
            }
        }
    }

    // simulate guard walking
    bool facingUp = true; // start facing up
    bool facingRight = false;
    bool facingDown = false;
    bool facingLeft = false;

    int visited = 1;

    while (true) {
        if (facingUp) {
            // check if at edge
            if (y == 0) {
                break;
            }
            // check if obstacle in front
            else if (map[y - 1][x] == '#') {
                facingRight = true; // face right
                facingUp = false;
                continue;
            }
            else {
                y -= 1; // move up one
                if (map[y][x] == 'X') {
                    continue; // been here before
                }
                else {
                    map[y][x] = 'X';
                    visited += 1;
                    continue;
                }
            }
        }

        else if (facingRight) {
            // check if at edge
            if (x == cols - 1) {
                break;
            }
            // check if obstacle in front
            else if (map[y][x + 1] == '#') {
                facingDown = true; // face down
                facingRight = false;
                continue;
            }
            else {
                x += 1; // move right one
                if (map[y][x] == 'X') {
                    continue; // been here before
                }
                else {
                    map[y][x] = 'X';
                    visited += 1;
                    continue;
                }
            }
        }

        else if (facingDown) {
            // check if at edge
            if (y == rows - 1) {
                break;
            }
            // check if obstacle in front
            else if (map[y + 1][x] == '#') {
                facingLeft = true; // face left
                facingDown = false;
                continue;
            }
            else {
                y += 1; // move down one
                if (map[y][x] == 'X') {
                    continue; // been here before
                }
                else {
                    map[y][x] = 'X';
                    visited += 1;
                    continue;
                }
            }
        }

        else if (facingLeft) {
            // check if at edge
            if (x == 0) {
                break;
            }
            // check if obstacle in front
            else if (map[y][x - 1] == '#') {
                facingUp = true; // face up
                facingLeft = false;
                continue;
            }
            else {
                x -= 1; // move left one
                if (map[y][x] == 'X') {
                    continue; // been here before
                }
                else {
                    map[y][x] = 'X';
                    visited += 1;
                    continue;
                }
            }
        }
    }

    std::cout << "Distinct positions visited: " << visited << "\n";

    return 0;
}
