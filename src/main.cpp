#include <iostream>
#include "func.cpp"
#include <vector>

int main(){
    std::vector<float> a = bucketSort({1,2,3.45,1});
    for (float num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}