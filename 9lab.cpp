#include <iostream>
#include <vector>
#include <algorithm> // ��� min_element, max_element
using namespace std;

int main() {
    int m, n;
    cout << "������ ������� ����� (m) � �������� (n): ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    vector<int> maxElements(m);
    int attempts = 0;  // ˳������� ����� �������� ��'����� ��������

    // �������� �������� ������� � ��������� �� ��'��� ��������
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            while (true) {
                cout << "������ matrix[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
                if (matrix[i][j] >= 0) {
                    break;
                }
                else {
                    cout << "������� �� ���� ���� ��'�����. ��������� �� ���.\n";
                    attempts++;
                }
            }
        }
    }

    // ����������� ������������ �������� � ������� �����
    for (int i = 0; i < m; i++) {
        maxElements[i] = *max_element(matrix[i].begin(), matrix[i].end());
    }

    // ����������� ���������� � ������������ ��������
    int minOfMax = *min_element(maxElements.begin(), maxElements.end());

    // ��������� ����������
    cout << "\n���������� �������� ������� �����:\n";
    for (int i = 0; i < m; i++) {
        cout << "����� " << i << ": max = " << maxElements[i];
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == maxElements[i]) {
                cout << " (������� [" << i << "][" << j << "])";
            }
        }
        cout << endl;
    }

    cout << "\n̳���� � ������������ �������� ������� �����: " << minOfMax << endl;
    cout << "ʳ������ ����� ������ ��'����� �������: " << attempts << endl;

    return 0;
}
