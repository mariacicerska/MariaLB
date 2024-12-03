#include <iostream>
#include <cstdio>  // ��� ������ � fopen, fclose, fgetc, fputchar
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 10;

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, FILE* out) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(out, "%d ", matrix[i][j]);  // ������������� fprintf ��� ������ � ����
        }
        fprintf(out, "\n");
    }
}

// �������� ���� ������ �� p ��������
void cyclicShiftRight(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int p) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int newJ = (j + p) % cols;
            swap(matrix[i][j], matrix[i][newJ]);
        }
    }
}

// �������� ���� ���� �� p ��������
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

    // ³�������� ������� ���� ��� ����������
    FILE* inputFile = fopen("matrix.txt", "r");  // ��������� ���� ��� �������
    if (inputFile == nullptr) {
        cerr << "Cannot open file" << endl;
        return 1;
    }

    // ������� ������ ������� �� ��������
    fscanf(inputFile, "%d %d", &rows, &cols);  // ������� ������ �������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(inputFile, "%d", &matrix[i][j]);  // ������� �������� �������
        }
    }
    fclose(inputFile);  // ��������� ���� ���� ����������

    // ��������� ������� �� �����
    cout << "Matrix elements:" << endl;
    printMatrix(matrix, rows, cols, stdout);  // �������� �� �����

    // ³�������� ������� ���� ��� ������ � ��������� ����
    FILE* outputFile = fopen("matrix_output.txt", "w");
    if (outputFile == nullptr) {
        cerr << "Cannot open file for writing" << endl;
        return 1;
    }

    // ��������� ������� � ��������� ����
    printMatrix(matrix, rows, cols, outputFile);
    fclose(outputFile);  // ��������� ���� ��� ������

    // �������� ��������� �����
    cout << "Enter shift count: ";
    cin >> shiftCount;
    cout << "Enter direction (r for right, d for down): ";
    cin >> direction;

    // ��������� ��������� �����
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

    // ��������� ���������� ����� �� �����
    cout << "Matrix after cyclic shift:" << endl;
    printMatrix(matrix, rows, cols, stdout);  // �������� �� �����

    // ����� ���������� � ������� ����
    FILE* binaryFile = fopen("matrix_output.bin", "wb");  // ��������� ������� ���� ��� ������
    if (binaryFile == nullptr) {
        cerr << "Cannot open binary file for writing" << endl;
        return 1;
    }

    // �������� ������� � ������� ����
    for (int i = 0; i < rows; i++) {
        fwrite(matrix[i], sizeof(int), cols, binaryFile);  // �������� ����� ����� � ������� ����
    }
    fclose(binaryFile);  // ��������� ������� ����

    return 0;
}
