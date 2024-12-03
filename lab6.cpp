#include <iostream>
#include <cstdio>  // Для роботи з fopen, fclose, fgetc, fputchar
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 10;

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, FILE* out) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(out, "%d ", matrix[i][j]);  // Використовуємо fprintf для запису у потік
        }
        fprintf(out, "\n");
    }
}

// Циклічний зсув вправо на p елементів
void cyclicShiftRight(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int p) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int newJ = (j + p) % cols;
            swap(matrix[i][j], matrix[i][newJ]);
        }
    }
}

// Циклічний зсув вниз на p елементів
void cyclicShiftDown(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int p) {
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            int newI = (i + p) % rows;
            swap(matrix[i][j], matrix[newI][j]);
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    int shiftCount;
    char direction;

    // Відкриваємо вхідний файл для зчитування
    FILE* inputFile = fopen("matrix.txt", "r");  // відкриваємо файл для читання
    if (inputFile == nullptr) {
        cerr << "Cannot open file" << endl;
        return 1;
    }

    // Зчитуємо розміри матриці та елементи
    fscanf(inputFile, "%d %d", &rows, &cols);  // зчитуємо розміри матриці
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(inputFile, "%d", &matrix[i][j]);  // зчитуємо елементи матриці
        }
    }
    fclose(inputFile);  // Закриваємо потік після зчитування

    // Виведення матриці на екран
    cout << "Matrix elements:" << endl;
    printMatrix(matrix, rows, cols, stdout);  // Виводимо на екран

    // Відкриваємо вхідний файл для запису в текстовий файл
    FILE* outputFile = fopen("matrix_output.txt", "w");
    if (outputFile == nullptr) {
        cerr << "Cannot open file for writing" << endl;
        return 1;
    }

    // Виведення матриці у текстовий файл
    printMatrix(matrix, rows, cols, outputFile);
    fclose(outputFile);  // Закриваємо потік для запису

    // Введення параметрів зсуву
    cout << "Enter shift count: ";
    cin >> shiftCount;
    cout << "Enter direction (r for right, d for down): ";
    cin >> direction;

    // Виконання циклічного зсуву
    if (direction == 'r') {
        cyclicShiftRight(matrix, rows, cols, shiftCount);
    }
    else if (direction == 'd') {
        cyclicShiftDown(matrix, rows, cols, shiftCount);
    }
    else {
        cout << "Invalid direction!" << endl;
        return 1;
    }

    // Виведення результату зсуву на екран
    cout << "Matrix after cyclic shift:" << endl;
    printMatrix(matrix, rows, cols, stdout);  // Виводимо на екран

    // Запис результатів у бінарний файл
    FILE* binaryFile = fopen("matrix_output.bin", "wb");  // відкриваємо бінарний файл для запису
    if (binaryFile == nullptr) {
        cerr << "Cannot open binary file for writing" << endl;
        return 1;
    }

    // Записуємо матрицю у бінарний файл
    for (int i = 0; i < rows; i++) {
        fwrite(matrix[i], sizeof(int), cols, binaryFile);  // записуємо кожен рядок у бінарний файл
    }
    fclose(binaryFile);  // Закриваємо бінарний файл

    return 0;
}
