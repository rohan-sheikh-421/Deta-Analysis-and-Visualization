#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 1000;
vector<double> memoization(MAX_SIZE, 0.0);

double calculateValue(int N) {
    if (N == 0) {
        return 1.0;
    }
    if (memoization[N] != 0.0) {
        return memoization[N];
    }
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += calculateValue(i);
    }
    memoization[N] = 2.0 * sum / N + N;
    return memoization[N];
}

int main() {
    for (int N = 0; N <= 4; N++) {
        double result = calculateValue(N);
        cout << "Result for N=" << N << ": " << result << endl;
    }
    return 0;
}
