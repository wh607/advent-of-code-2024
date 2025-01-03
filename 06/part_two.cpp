#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

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

    int x_guard, y_guard;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == '^') {
                x_guard = j;
                y_guard = i;
                break;
            }
        }
    }

    // simulate guard walking
    std::set<std::pair<int, int> > seen_coords;

    // store facing direct 0 : up, 1 : right, 2 : down, 3 : left
    int dir = 0;

    // store instructions to update x, y
    std::vector<std::pair<int, int> > movements = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    int x = x_guard;
    int y = y_guard;

    int x_next, y_next;

    while (true) {
        // look at where guard will move to
        x_next = x + std::get<0>(movements[dir]);
        y_next = y + std::get<1>(movements[dir]);

        if (x_next < 0 || x_next > cols || y_next < 0 || y_next > rows) {
            // out of bounds - guard has left map
            break;
        }
        else if (map[y_next][x_next] == '#') {
            while (true) { // check for subsequent obstacles
                dir = (dir + 1) % 4;
                x_next = x + std::get<0>(movements[dir]);
                y_next = y + std::get<1>(movements[dir]);
                if (map[y_next][x_next] != '#') {
                    break;
                }
            }
        }


        // move
        x = x_next;
        y = y_next;

        // track coords we have seen
        seen_coords.insert({x, y});
    }

    int caused_loop = 0;
    int x_obj, y_obj;

    std::set<std::pair<int, int> >::iterator it;
    for (it = seen_coords.begin(); it != seen_coords.end(); it++) {

        if (*it == std::make_pair(x_guard, y_guard)) {
            continue;
        }

        dir = 0;
        x = x_guard;
        y = y_guard;

        // use to log direction and position
        std::set<std::tuple<int, int, int> > seen_dir_coords = {{0, x_guard, y_guard}};

        x_obj = std::get<0>(*it);
        y_obj = std::get<1>(*it);
        map[y_obj][x_obj] = '#'; // place object temporarily

        while (true) {
                // look at where guard will move to
                x_next = x + std::get<0>(movements[dir]);
                y_next = y + std::get<1>(movements[dir]);

                if (x_next < 0 || x_next > cols || y_next < 0 || y_next > rows) {
                    // out of bounds - guard has left map
                    break;
                }
                else if (map[y_next][x_next] == '#') {
                    while (true) { // check for subsequent obstacles
                        dir = (dir + 1) % 4;
                        x_next = x + std::get<0>(movements[dir]);
                        y_next = y + std::get<1>(movements[dir]);
                        if (map[y_next][x_next] != '#') {
                            break;
                        }
                    }
                }

                // move
                x = x_next;
                y = y_next;

                // track coords we have seen
                if (seen_dir_coords.find({dir, x, y}) != seen_dir_coords.end()) {
                    caused_loop += 1;
                    break;
                }
                else {
                    seen_dir_coords.insert({dir, x, y});
                }
        }

        map[y_obj][x_obj] = '.'; // remove object

    }

    std::cout << "Objects that cause loops: " << caused_loop << "\n";
    return 0;
}
