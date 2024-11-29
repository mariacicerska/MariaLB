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

    // Вводимо текст
    cout << "Enter text: ";
    getline(cin, text);

    stringstream ss(text);
    string word;

    // Обробляємо кожне слово в тексті
    while (ss >> word) {
        // Перевіряємо чи це не цифра
        if (!is_digit(word)) {
            // Перевірка чи слово не порожнє
            if (word.length() > 1) {
                // Виводимо першу і останню літеру
                cout << word[0] << word[word.length() - 1] << " ";
            }
            else {
                // Якщо слово має одну літеру, виводимо її двічі
                cout << word[0] << word[0] << " ";
            }
        }
    }

    return 0;
}