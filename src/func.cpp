#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

std::vector<float> slice(std::vector<float> v, int from, int to){
    std::vector<float> rez(to-from);
    for (int i = from; i <= to; i++){
        rez[i-from] = v[i];
    }
    return rez;
}


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

std::vector<float> Merge(std::vector<float> arrb, std::vector<float> arrc){
    int p = arrb.size();
    int q = arrc.size();
    std::vector<float> rez(p+q);
    int i = 0, j = 0, k = 0;
    while (i < p and j < q)
    {
        if (arrb[i] <= arrc[j])
        {
            rez[k] = arrb[i];
            i++;
        }
        else
        {
            rez[k] = arrc[j];
            j++;
        }
        k++;
    }
    if (i==p){
        for (int a = j; a < q; a++){
            rez[k] = arrc[a];
            k++;
        }
    }
    else
    {
        for (int a = i; a < p; a++){
            rez[k] = arrb[a];
            k++;
        }
    }

    return rez;
}

std::vector<float> Mergesort(std::vector<float> arr){
    int n = arr.size();
    if (n <= 1) return arr;
    std::vector<float> rez = arr;
    std::vector<float> rezb = slice(rez, 0, n/2);
    std::vector<float> rezc = slice(rez, n/2, n);
    rezb = Mergesort(rezb);
    rezc = Mergesort(rezc);
    rez = Merge(rezb,rezc);

    return rez;
}

std::vector<float> SelectionSort(std::vector<float>& arr){
    int n = arr.size();
    std::vector<float> rez = arr;
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (rez[j] < rez[min]) {
                min = j;
            }
        }
        std::swap(rez[min], rez[i]);
    }
    return rez;
}