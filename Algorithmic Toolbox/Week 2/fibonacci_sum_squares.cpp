#include <iostream>

long long pisano_period(long long m){
    long long previous = 0;
    long long current  = 1;
    for (long long i = 0; i < m*m; i++){
        long long aux = (previous + current) % m;
        previous = current;
        current = aux;
        if (previous == 0 and current == 1){
            return i + 1;
        }
    }
    
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    

    long long previous = 0;
    long long current  = 1;
    n = n % pisano_period(m);

    if (n <= 1)
        return n;
    for (long long i = 0; i < n - 1; ++i) {
        long long aux = (previous + current) % m;
        previous = current;
        current = aux;
    }

    return current;
}


int fibonacci_sum_squares_fast(long long n) {
    long long fib_n = get_fibonacci_huge_fast(n, 10);
    long long fib_n_1 = get_fibonacci_huge_fast(n+1, 10);
    return (fib_n*fib_n_1) %10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
