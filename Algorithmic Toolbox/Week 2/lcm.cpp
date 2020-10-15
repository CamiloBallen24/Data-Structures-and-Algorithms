#include <iostream>

int gcd_fast(int a, int b) {
  if(b == 0){
    return a;
  }
  else{
    return gcd_fast(b, a%b);
  }
}

long long lcm_naive(int a, int b) {
    long long gcd = (long long) gcd_fast(a,b);
    long long ab = (long long)a * (long long)b;
    return ab/gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
