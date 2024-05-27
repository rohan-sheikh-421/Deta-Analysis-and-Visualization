#include <iostream>
using namespace std;

double calculateSeries(int N) {
    if (N == 0) {
        return 1.0;
    } else {
        double sum = 0.0;
        for (int i = 0; i < N; i++) {
            sum += calculateSeries(i);
        }
        return 2.0 * sum / N + N;
    }
}

int main() {
    for (int N = 0; N <= 4; N++) {
        double result = calculateSeries(N);
        cout << "C(" << N << ") = " << result << endl;
    }
    return 0;
}
