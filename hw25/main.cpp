//
//  main.cpp
//  hw25
//
//  Created by Valeria Dudinova on 22.12.2024.
//

#include <iostream>
using namespace std;

// Функтор для поиска минимального значения
struct FindMin {
    int operator()(const int* arr, int size) const {
        int minValue = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] < minValue) {
                minValue = arr[i];
            }
        }
        return minValue;
    }
};

// Функтор для поиска максимального значения
struct FindMax {
    int operator()(const int* arr, int size) const {
        int maxValue = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > maxValue) {
                maxValue = arr[i];
            }
        }
        return maxValue;
    }
};

// Функтор для сортировки по возрастанию
struct SortAscending {
    void operator()(int* arr, int size) const {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};

// Функтор для сортировки по убыванию
struct SortDescending {
    void operator()(int* arr, int size) const {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (arr[i] < arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};

// Функтор для увеличения значений на заданную константу
struct IncreaseByConstant {
    int constant;
    IncreaseByConstant(int c) : constant(c) {}
    void operator()(int* arr, int size) const {
        for (int i = 0; i < size; ++i) {
            arr[i] += constant;
        }
    }
};

// Функтор для уменьшения значений на заданную константу
struct DecreaseByConstant {
    int constant;
    DecreaseByConstant(int c) : constant(c) {}
    void operator()(int* arr, int size) const {
        for (int i = 0; i < size; ++i) {
            arr[i] -= constant;
        }
    }
};

// Функтор для удаления элементов, равных заданному значению
struct RemoveValue {
    int value;
    RemoveValue(int v) : value(v) {}
    int operator()(int* arr, int size) const {
        int newSize = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] != value) {
                arr[newSize++] = arr[i];
            }
        }
        return newSize;
    }
};

int main() {
    const int capacity = 100;
    int data[capacity] = {5, 2, 8, 1, 3, 8, 6, 8};
    int size = 8;

    // Поиск минимального значения
    FindMin findMin;
    cout << "Min value: " << findMin(data, size) << endl;

    // Поиск максимального значения
    FindMax findMax;
    cout << "Max value: " << findMax(data, size) << endl;

    // Сортировка по возрастанию
    SortAscending sortAsc;
    sortAsc(data, size);
    cout << "Sorted ascending: ";
    for (int i = 0; i < size; ++i) cout << data[i] << " ";
    cout << endl;

    // Сортировка по убыванию
    SortDescending sortDesc;
    sortDesc(data, size);
    cout << "Sorted descending: ";
    for (int i = 0; i < size; ++i) cout << data[i] << " ";
    cout << endl;

    // Увеличение значений на константу
    IncreaseByConstant increaseBy(3);
    increaseBy(data, size);
    cout << "Increased by 3: ";
    for (int i = 0; i < size; ++i) cout << data[i] << " ";
    cout << endl;

    // Уменьшение значений на константу
    DecreaseByConstant decreaseBy(2);
    decreaseBy(data, size);
    cout << "Decreased by 2: ";
    for (int i = 0; i < size; ++i) cout << data[i] << " ";
    cout << endl;

    // Удаление элементов, равных заданному значению
    RemoveValue removeValue(8);
    size = removeValue(data, size);
    cout << "After removing 8: ";
    for (int i = 0; i < size; ++i) cout << data[i] << " ";
    cout << endl;

    return 0;
}
