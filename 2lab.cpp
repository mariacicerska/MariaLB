#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ��������� ������ �������
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // ��������� �������
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix:" << endl;
    // ������� �������� �������
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // �������� ��������� ������� �� ���� �������
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

    // ���������� �����
    if (minElement % 2 == 0 && minRow % 2 == 0) {
        cout << "Minimum element is even and its row is even. Sorting the third column." << endl;

        // ������� ����� �������� (���� ���� ����� ��������)
        if (cols >= 3) {
            // ��������� ����� ��� �������� �������� �������
            vector<int> thirdColumn;
            for (int i = 0; i < rows; ++i) {
                thirdColumn.push_back(matrix[i][2]);  // ����� �������� �� ���������� 2
            }

            // ������� ����� ��������
            sort(thirdColumn.begin(), thirdColumn.end());

            // ���������� ���������� �������� ����� � �������
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

    // �������� �������� �������
    cout << "Updated matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}