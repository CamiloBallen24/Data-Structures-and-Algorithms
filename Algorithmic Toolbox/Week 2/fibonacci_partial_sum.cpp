#include <iostream>
#include <vector>
using std::vector;

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

int fibonacci_sum_fast(long long n) {
    long long rta = get_fibonacci_huge_fast((long long)n+2, 10) -1;
    if(rta == -1){
        return 9;
    }
    return  rta;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long from_fib = fibonacci_sum_fast(from-1);
    long long to_fib = fibonacci_sum_fast(to);
    if(from_fib > to_fib){
        to_fib = (to_fib+10);
    }
    return to_fib -from_fib;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
