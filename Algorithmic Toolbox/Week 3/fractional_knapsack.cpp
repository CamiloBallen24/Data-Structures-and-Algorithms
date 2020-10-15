#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  vector<double> values_unit(weights.size());
  for(int i = 0; i<weights.size(); i++){
    values_unit[i] = (double)values[i]/ (double)weights[i];
  }

  while (capacity>0 && weights.size()>0) {
    auto best_i = distance(values_unit.begin(), max_element(values_unit.begin(), values_unit.end()));
    if(capacity>=weights[best_i]){
      capacity = capacity - weights[best_i];
      value = value + values[best_i];
      weights.erase(weights.begin() + best_i);
      values.erase(values.begin() + best_i);
      values_unit.erase(values_unit.begin() + best_i);
    }
    else{
      return value + values_unit[best_i]*capacity;
    }
  }
  
  

  return value;
}




int main() {
  
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
  
   
}
