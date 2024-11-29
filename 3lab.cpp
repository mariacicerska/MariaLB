#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool is_digit(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string text;

    // ������� �����
    cout << "Enter text: ";
    getline(cin, text);

    stringstream ss(text);
    string word;

    // ���������� ����� ����� � �����
    while (ss >> word) {
        // ���������� �� �� �� �����
        if (!is_digit(word)) {
            // �������� �� ����� �� ������
            if (word.length() > 1) {
                // �������� ����� � ������� �����
                cout << word[0] << word[word.length() - 1] << " ";
            }
            else {
                // ���� ����� �� ���� �����, �������� �� ����
                cout << word[0] << word[0] << " ";
            }
        }
    }

    return 0;
}