#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <iostream>
#include <cmath>    // ��� std::abs
#include <algorithm> // ��� std::swap

using namespace std;

// ������ ��� �������� ������
#define INPUT_ARRAY(arr, n)               \
    for (int i = 0; i < n; ++i) {         \
        cout << "Enter element " << i + 1 << ": "; \
        cin >> arr[i];                    \
    }

// ������ ��� ��������� ������
#define OUTPUT_ARRAY(arr, n)              \
    cout << "Array elements: ";           \
    for (int i = 0; i < n; ++i) {         \
        cout << arr[i] << " ";            \
    }                                     \
    cout << endl;

// ������ ��� ��������� ������� �������� � ������� [a, b]
#define COUNT_IN_RANGE(arr, n, a, b, count) \
    count = 0;                              \
    for (int i = 0; i < n; ++i) {           \
        if (arr[i] >= a && arr[i] <= b) {   \
            count++;                        \
        }                                   \
    }

// ������ ��� ���������� ���� �������� ���� �������������
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

// ������ ��� ���������� �� ��������� ������
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
