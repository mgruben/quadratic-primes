#include <iostream>
using namespace std;

 // https://en.wikipedia.org/wiki/Primality_test#Pseudocode
bool isPrime(int n) { 
    if (n <= 1) return false;
    if (n <= 3) return true;
    if ((n % 2 == 0) || (n % 3 == 0)) return false;
    int i = 5;
    while (i * i < n) {
        if ((n % i == 0) || (n % (i + 2) == 0)) return false;
        i += 6;
    }
    return true;
}

/**
 * Given a formula of the form
 * n^2 + an + b, determine how many
 * consecutive primes it generates
 * for 0 <= n.
 * 
 * Returns the number of consecutive
 * primes generated
 */
int runOfPrimes(int a, int b) {
    int n = 0;
    while (isPrime(n*n + a*n + b)) n++;
    return n - 1; // Since the last n++ overshot.
}

int main() {
    int longestRun = 0;
    int bestA;
    int bestB;
    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int thisRun = runOfPrimes(a, b);
            if (thisRun > longestRun) {
                longestRun = thisRun;
                bestA = a;
                bestB = b;
            }
        }
    }
    cout << bestA * bestB << endl;
    return 0;
}
