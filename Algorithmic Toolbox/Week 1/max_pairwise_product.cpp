#include <iostream>
#include <vector>
#include <algorithm>

long long  MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    int index_1 = -1;
    for (int i = 0; i < n; i++){
        if((index_1 == -1) || (numbers[i]>numbers[index_1])){
            index_1 = i;
        }
    }

    

    int index_2 = -1;
    for (int i = 0; i < n; i++){
        if( (index_2 == -1 || numbers[i]>numbers[index_2] )&& (index_1 != i)){
            index_2 = i;
        }
    }
    
    return ((long long)numbers[index_1])*numbers[index_2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers);
    return 0;
}
