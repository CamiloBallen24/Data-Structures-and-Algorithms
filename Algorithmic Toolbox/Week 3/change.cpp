#include <iostream>
#include <cassert>

int get_change(int m) {
  if(m>=10){
    return get_change(m-10)+1;
  }
  else if(m>=5){
    return get_change(m-5)+1;
  }
  else if(m>=1){
    return get_change(m-1)+1;
  }
  return 0;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
