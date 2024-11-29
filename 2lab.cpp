#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Визначаємо розміри матриці
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Створюємо матрицю
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix:" << endl;
    // Вводимо елементи матриці
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Знайдемо мінімальний елемент та його позицію
    int minElement = matrix[0][0];
    int minRow = 0, minCol = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    // Перевіряємо умови
    if (minElement % 2 == 0 && minRow % 2 == 0) {
        cout << "Minimum element is even and its row is even. Sorting the third column." << endl;

        // Сортуємо третій стовпець (якщо існує третій стовпець)
        if (cols >= 3) {
            // Створюємо масив для елементів третього стовпця
            vector<int> thirdColumn;
            for (int i = 0; i < rows; ++i) {
                thirdColumn.push_back(matrix[i][2]);  // третій стовпець має індексацію 2
            }

            // Сортуємо третій стовпець
            sort(thirdColumn.begin(), thirdColumn.end());

            // Вставляємо відсортовані значення назад в матрицю
            for (int i = 0; i < rows; ++i) {
                matrix[i][2] = thirdColumn[i];
            }
        }
        else {
            cout << "Matrix doesn't have a third column!" << endl;
        }
    }
    else {
        cout << "Minimum element is either odd or its row is odd. No sorting performed." << endl;
    }

    // Виведемо оновлену матрицю
    cout << "Updated matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}