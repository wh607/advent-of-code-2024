#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main() {
    int N = 1000;
    // part1
    // create two vectors
    vector<int> x, y;

    // run in terminal and paste the input
    cout << "Paste puzzle input: ";

    // read input and populate the vectors
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    // sort the vectors asc
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    // get the differences
    int total_distance = 0;
    for (int i = 0; i < N; i++) {
        total_distance += abs(x[i] - y[i]);
    }

    cout << "Total distance: " << total_distance << "\n";

    // part2
    // get unique values in list 1
    vector<int> x_unique = x; // make a copy of x

    vector<int>::iterator it;
    it = unique(x_unique.begin(), x_unique.end());
    // now x_unique becomes {[unique vals] [*]}
    // where * are undefined

    // remove undefined terms at end of vector
    x_unique.resize(distance(x_unique.begin(), it));

    // define a map to store value, count
    map <int, int> counter;

    // loop through the x_unique vector
    int similarity_score = 0;
    for (int i = 0; i < x_unique.size(); i++) {
        counter[x_unique[i]] = count(y.begin(), y.end(), x_unique[i]);
    }

    // loop through x, lookup number of occurences in y in
    // count map and calculate similarity score
    for (int i = 0; i < N; i++) {
        similarity_score += x[i] * counter[x[i]];
    }

    cout << "Similarity score: " << similarity_score << "\n";

    return 0;
}
