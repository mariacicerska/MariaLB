#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    int birthMonth;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<Student> students(n);

    // ������� ����� �� ����� ���������� ��������
    for (int i = 0; i < n; ++i) {
        cout << "Enter name of student #" << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter birth month of " << students[i].name << ": ";
        cin >> students[i].birthMonth;
    }

    // ��������� ����� ��� ��������� ��������, �� ���������� � ������� �����
    vector<int> monthCount(12, 0);

    // ϳ��������� ������� ��������, �� ���������� � ������� �����
    for (const auto& student : students) {
        monthCount[student.birthMonth - 1]++;
    }

    // ��������� �����, � ����� ���������� �������� ��������
    int maxMonth = 0;
    for (int i = 1; i < 12; ++i) {
        if (monthCount[i] > monthCount[maxMonth]) {
            maxMonth = i;
        }
    }

    // �������� ��������, �� ���������� � ����� � ��������� ������� ��������
    cout << "The month with the most students is: " << maxMonth + 1 << endl;
    cout << "Students born in this month are: " << endl;

    for (const auto& student : students) {
        if (student.birthMonth == maxMonth + 1) {
            cout << student.name << endl;
        }
    }

    return 0;
}