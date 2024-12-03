#include <iostream>
#include "myHeader.h"

using namespace std;

int main() {
    const int N = 10;
    double arr[N];
    double a = -5, b = 5;
    int count = 0;
    double sum = 0;

    // �������� ������
    INPUT_ARRAY(arr, N);

    // ��������� ������
    OUTPUT_ARRAY(arr, N);

    // ϳ�������� ������� �������� � ������� [a, b]
    COUNT_IN_RANGE(arr, N, a, b, count);
    cout << "Elements in range [" << a << ", " << b << "]: " << count << endl;

    // ���������� ���� �������� ���� �������������
    SUM_AFTER_MAX(arr, N, sum);
    cout << "Sum of elements after max: " << sum << endl;

    // ���������� �� ��������� ������
    SORT_DESC_BY_ABS(arr, N);
    cout << "Array sorted by descending absolute values: ";
    OUTPUT_ARRAY(arr, N);

    return 0;
}
