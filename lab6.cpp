#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

void cyclicShiftRight(int** mas, int n, int m, int p) {
    p %= m; // ������� p �� ������ �����
    int* temp = new int[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[(j + p) % m] = mas[i][j];
        }
        for (int j = 0; j < m; j++) {
            mas[i][j] = temp[j];
        }
    }
    delete[] temp;
}

int main() {
    FILE* fin = nullptr;
    char namef[40];
    puts("Input file name:");
    fgets(namef, sizeof(namef), stdin);
    char* p = strchr(namef, '\n');
    if (p) *p = '\0';

    fin = fopen(namef, "r");
    if (!fin) {
        printf("Cannot open file\n");
        return 1;
    }

    int n, m;
    fscanf(fin, "%d%d", &n, &m);
    int** mas = new int* [n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[m];
        for (int j = 0; j < m; j++) {
            fscanf(fin, "%d", &mas[i][j]);
        }
    }
    fclose(fin);

    // ���� ��������� �������
    printf("Original matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", mas[i][j]);
        }
        printf("\n");
    }

    // ����� ��������� ������� � ��������� ����
    FILE* fout = fopen("f2.txt", "w");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fout, "%5d", mas[i][j]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);

    // ����� ��������� ������� � ������� ����
    fout = fopen("f3.b", "wb");
    for (int i = 0; i < n; i++) {
        fwrite(mas[i], sizeof(int) * m, 1, fout);
    }
    fclose(fout);

    // ���� ������� ������ �� p �������
    int shift;
    printf("Enter shift value (p): ");
    scanf("%d", &shift);
    cyclicShiftRight(mas, n, m, shift);

    // ���� ������ �������
    printf("Shifted matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", mas[i][j]);
        }
        printf("\n");
    }

    // ���������� ����� � ��������� ����
    fout = fopen("f2.txt", "a");
    fprintf(fout, "\nShifted matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fout, "%5d", mas[i][j]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);

    // ��������� �����
    for (int i = 0; i < n; i++) {
        delete[] mas[i];
    }
    delete[] mas;

    printf("Finish\n");
    return 0;
}
