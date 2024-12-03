#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <iostream>
#include <cmath>    // Для std::abs
#include <algorithm> // Для std::swap

using namespace std;

// Макрос для введення масиву
#define INPUT_ARRAY(arr, n)               \
    for (int i = 0; i < n; ++i) {         \
        cout << "Enter element " << i + 1 << ": "; \
        cin >> arr[i];                    \
    }

// Макрос для виведення масиву
#define OUTPUT_ARRAY(arr, n)              \
    cout << "Array elements: ";           \
    for (int i = 0; i < n; ++i) {         \
        cout << arr[i] << " ";            \
    }                                     \
    cout << endl;

// Макрос для підрахунку кількості елементів у діапазоні [a, b]
#define COUNT_IN_RANGE(arr, n, a, b, count) \
    count = 0;                              \
    for (int i = 0; i < n; ++i) {           \
        if (arr[i] >= a && arr[i] <= b) {   \
            count++;                        \
        }                                   \
    }

// Макрос для обчислення суми елементів після максимального
#define SUM_AFTER_MAX(arr, n, sum) {       \
    int maxIndex = 0;                      \
    for (int i = 1; i < n; ++i) {          \
        if (arr[i] > arr[maxIndex]) {      \
            maxIndex = i;                  \
        }                                  \
    }                                      \
    sum = 0;                               \
    for (int i = maxIndex + 1; i < n; ++i) {\
        sum += arr[i];                     \
    }                                      \
}

// Макрос для сортування за спаданням модулів
#define SORT_DESC_BY_ABS(arr, n) {         \
    for (int i = 0; i < n - 1; ++i) {      \
        for (int j = 0; j < n - i - 1; ++j) {\
            if (std::abs(arr[j]) < std::abs(arr[j + 1])) {\
                std::swap(arr[j], arr[j + 1]);\
            }                              \
        }                                  \
    }                                      \
}

#endif // MY_HEADER_H
#pragma once
