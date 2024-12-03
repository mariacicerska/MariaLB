#include <iostream>
#include <vector>
#include <algorithm> // для min_element, max_element
using namespace std;

int main() {
    int m, n;
    cout << "Введіть кількість рядків (m) і стовпців (n): ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    vector<int> maxElements(m);
    int attempts = 0;  // Лічильник спроб введення від'ємних елементів

    // Введення елементів матриці з перевіркою на від'ємні значення
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            while (true) {
                cout << "Введіть matrix[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
                if (matrix[i][j] >= 0) {
                    break;
                }
                else {
                    cout << "Елемент не може бути від'ємним. Спробуйте ще раз.\n";
                    attempts++;
                }
            }
        }
    }

    // Знаходження максимальних елементів у кожному рядку
    for (int i = 0; i < m; i++) {
        maxElements[i] = *max_element(matrix[i].begin(), matrix[i].end());
    }

    // Знаходження мінімального з максимальних елементів
    int minOfMax = *min_element(maxElements.begin(), maxElements.end());

    // Виведення результатів
    cout << "\nМаксимальні елементи кожного рядка:\n";
    for (int i = 0; i < m; i++) {
        cout << "Рядок " << i << ": max = " << maxElements[i];
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == maxElements[i]) {
                cout << " (позиція [" << i << "][" << j << "])";
            }
        }
        cout << endl;
    }

    cout << "\nМінімум з максимальних елементів кожного рядка: " << minOfMax << endl;
    cout << "Кількість спроб ввести від'ємний елемент: " << attempts << endl;

    return 0;
}
