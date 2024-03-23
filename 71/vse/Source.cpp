#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** z, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** z, const int rowCount, const int colCount);
void Sort(int** z, const int rowCount, const int colCount);
void Change(int** z, const int row1, const int row2, const int colCount);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand((unsigned)time(NULL));

    const int Low = 18;
    const int High = 74;
    const int rowCount = 9;
    const int colCount = 6;

    int** z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        z[i] = new int[colCount];

    Create(z, rowCount, colCount, Low, High);

    cout << "Original" << endl;
    Print(z, rowCount, colCount);
    cout << endl;

    int** b = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        b[i] = new int[colCount];
        for (int j = 0; j < colCount; j++)
            b[i][j] = z[i][j];
    }

    Sort(b, rowCount, colCount);

    cout << "Sorted" << endl;
    Print(b, rowCount, colCount);
    cout << endl;

    int S = 0;
    int k = 0;
    Calc(b, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "K = " << k << endl;

    cout << "Modified" << endl;
    Print(b, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] z[i];
    delete[] z;

    for (int i = 0; i < rowCount; i++)
        delete[] b[i];
    delete[] b;

    return 0;
}

void Create(int** z, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            z[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** z, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << z[i][j];
        cout << endl;
    }
}

void Sort(int** z, const int rowCount, const int colCount) {
    for (int i = 0; i < colCount - 1; i++)
        for (int j = 0; j < colCount - i - 1; j++)
            if (z[0][j] > z[0][j + 1])
                Change(z, j, j + 1, rowCount);
}

void Change(int** z, const int col1, const int col2, const int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        int temp = z[i][col1];
        z[i][col1] = z[i][col2];
        z[i][col2] = temp;
    }
}

void Calc(int** z, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (!(z[i][j] % 2 != 0 || z[i][j] % 7 == 0)) {
                S += z[i][j];
                k++;
                z[i][j] = 0;
            }
}
