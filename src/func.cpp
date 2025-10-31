#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

std::vector<float> inputFloatVectorWithValidation() {
    std::vector<float> numbers;
    std::string input;
    
    while (true) {
        std::cout << "Введите числа через пробелы: ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            std::cout << "Ввод не может быть пустым. Попробуйте снова." << std::endl;
            continue;
        }
        
        std::stringstream ss(input);
        float num;
        bool valid = true;
        
        numbers.clear();
        while (ss >> num) {
            numbers.push_back(num);
        }
        
        // Проверяем, что весь ввод был корректным
        if (ss.eof() && !numbers.empty()) {
            break;
        } else {
            std::cout << "Обнаружены некорректные данные. Введите только числа." << std::endl;
            // Очищаем флаг ошибки
            ss.clear();
        }
    }
    
    return numbers;
}

std::vector<float> bucketSort(std::vector<float> arr) {
    int n = arr.size();
    if (n <= 1) return arr;
    std::vector<float> rez = arr;
    
    // 3. Распределяем элементы по блокам
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (rez[j+1]<rez[j]){
                float c = rez[j+1];
                rez[j+1] = rez[j];
                rez[j] = c;
            }
    }
    }
    
    return rez;
}
