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

int runOfPrimes(int a, int b) {
    int c = 0;
    while (isPrime(c*c + a*c + b)) c++;
    return c - 1;
}

int main() {
    cout << runOfPrimes(-79, 1601) << endl;
    return 0;
}
