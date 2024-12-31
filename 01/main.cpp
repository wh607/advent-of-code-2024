#include <iostream>

using namespace std;

int main() {
    // create two vectors
    vector <int> x, y;

    // run in terminal and paste the input
    cout << "Paste puzzle input: ";

    // read input and populate the vectors
    for (int i = 0; i < 1000; i++) {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    // sort the vectors asc
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    // get the differences
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += abs(x[i] - y[i]);
    }

    cout << "Solution: " << sum << "\n";
    return 0;
}
