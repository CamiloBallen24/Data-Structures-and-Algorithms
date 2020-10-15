#include <iostream>

int get_fibonacci_last_digit_fast(int n) {
    if(n <= 1){return n;}
    else{
        int  fib_n_1 = 0;
        int  fib_n = 1;
        
        for (int i = 1; i < n; i++){
            int aux = (fib_n + fib_n_1) % 10;
            fib_n_1 = fib_n;
            fib_n = aux;    
        }
        return fib_n;
    }
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
