#include <iostream>
#include "func.cpp"
#include <vector>

int main(){
    std::vector<float> arr = inputFloatVectorWithValidation();
    std::vector<float> a = bucketSort(arr);
    for (float num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::vector<float> b = bucketSort(arr);
    for (float num : b) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::vector<float> c = bucketSort(arr);
    for (float num : c) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}