#include <iostream>
#include <vector>
using namespace std;

double calculateValue(int N, vector<double>& memo) {
    if (N == 0) {
        return 1.0;
    }
    if (memo[N] != 0.0) {
        return memo[N];
    }
    
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += calculateValue(i, memo);
    }
    memo[N] = 2.0 * sum / N + N;
    
    return memo[N];
}

int main() {
    const int N = 4;  // Adjust N as needed
    vector<double> memo(N + 1, 0.0);

    for (int i = 0; i <= N; i++) {
        double result = calculateValue(i, memo);
        cout << "C(" << i << ") = " << result << endl;
    }

    return 0;
}
