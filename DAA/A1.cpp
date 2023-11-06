#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Function to calculate the Fibonacci sequence non-recursively
long long fibonacciNonRecursive(int n) {
    vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

// Function to calculate the Fibonacci sequence recursively
long long fibonacciRecursive(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    const int N = 20;
    const int RUNS = 1000;

    cout << "Given N = " << N << "\n" << RUNS << " runs\n";

    // Measure the time for the non-recursive Fibonacci calculation
    auto start = chrono::high_resolution_clock::now();
    long long resultNonRecursive = 0;
    for (int i = 0; i < RUNS; ++i) {
        resultNonRecursive = fibonacciNonRecursive(N);
    }
    auto end = chrono::high_resolution_clock::now();
    double timeNonRecursive = chrono::duration<double>(end - start).count();

    cout << "Fibonacci non-recursive: " << resultNonRecursive << "\tTime: " << timeNonRecursive << "s\tO(n)\tSpace: O(n)\n";

    // Measure the time for the recursive Fibonacci calculation
    start = chrono::high_resolution_clock::now();
    long long resultRecursive = 0;
    for (int i = 0; i < RUNS; ++i) {
        resultRecursive = fibonacciRecursive(N);
    }
    end = chrono::high_resolution_clock::now();
    double timeRecursive = chrono::duration<double>(end - start).count();

    cout << "Fibonacci recursive: " << resultRecursive << "\tTime: " << timeRecursive << "s\tO(2^n)\tSpace: O(n)\n";

    return 0;
}
