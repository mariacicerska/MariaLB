#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������� ��� ��������� �������
void outputMatr(vector<vector<int>>& matr) {
    for (int i = 0; i < matr.size(); i++) {
        for (int j = 0; j < matr[i].size(); j++) {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������� ��� ����������� ���� �������� ��������
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

// ������� ��� ���������� ������� �������
void sortMainDiagonal(vector<vector<int>>& matr) {
    int n = matr.size();
    vector<int> diag(n);

    // �������� �������� ������� ������� � ������� �����
    for (int i = 0; i < n; i++) {
        diag[i] = matr[i][i];
    }

    // ������� ������� ��������
    sort(diag.begin(), diag.end());

    // ������������ ���������� �������� ����� � �������
    for (int i = 0; i < n; i++) {
        matr[i][i] = diag[i];
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    // ��������� ��������� �������
    vector<vector<int>> matr(n, vector<int>(n));

    // ������� �������� �������
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matr[i][j];
        }
    }

    // ��������� ��������� �������
    cout << "Original matrix:" << endl;
    outputMatr(matr);

    // ��������� ���� �������� ��������
    int sum = sumPositiveElements(matr);
    cout << "Sum of positive elements: " << sum << endl;

    // ������� ������� ��������
    sortMainDiagonal(matr);
    cout << "Matrix after sorting the main diagonal:" << endl;
    outputMatr(matr);

    return 0;
}
