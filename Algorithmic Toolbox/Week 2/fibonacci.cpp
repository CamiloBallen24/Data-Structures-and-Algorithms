#include <iostream>
#include <cassert>


int fibonacci_fast(int n) {
    if(n <= 1){return n;}
    else{
        long long fib_n_1 = 0;
        long long fib_n = 1;
        
        for (int i = 1; i < n; i++){
            long long aux = fib_n + fib_n_1;
            fib_n_1 = fib_n;
            fib_n = aux;    
        }
        return fib_n;
    }
  
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
