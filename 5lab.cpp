#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для виведення матриці
void outputMatr(vector<vector<int>>& matr) {
    for (int i = 0; i < matr.size(); i++) {
        for (int j = 0; j < matr[i].size(); j++) {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функція для знаходження суми додатних елементів
int sumPositiveElements(const vector<vector<int>>& matr) {
    int sum = 0;
    for (int i = 0; i < matr.size(); i++) {
        for (int j = 0; j < matr[i].size(); j++) {
            if (matr[i][j] > 0) {
                sum += matr[i][j];
            }
        }
    }
    return sum;
}

// Функція для сортування головної діагоналі
void sortMainDiagonal(vector<vector<int>>& matr) {
    int n = matr.size();
    vector<int> diag(n);

    // Записуємо елементи головної діагоналі в окремий масив
    for (int i = 0; i < n; i++) {
        diag[i] = matr[i][i];
    }

    // Сортуємо головну діагональ
    sort(diag.begin(), diag.end());

    // Перезаписуємо відсортовані елементи назад у матрицю
    for (int i = 0; i < n; i++) {
        matr[i][i] = diag[i];
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    // Створюємо квадратну матрицю
    vector<vector<int>> matr(n, vector<int>(n));

    // Вводимо елементи матриці
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matr[i][j];
        }
    }

    // Виведення початкової матриці
    cout << "Original matrix:" << endl;
    outputMatr(matr);

    // Знаходимо суму додатних елементів
    int sum = sumPositiveElements(matr);
    cout << "Sum of positive elements: " << sum << endl;

    // Сортуємо головну діагональ
    sortMainDiagonal(matr);
    cout << "Matrix after sorting the main diagonal:" << endl;
    outputMatr(matr);

    return 0;
}
