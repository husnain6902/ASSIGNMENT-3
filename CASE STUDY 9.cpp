#include <iostream>
using namespace std;

void inputDefects(float d[3][7]) {
    for (int i = 0; i < 3; i++) {
        cout << "Shift " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> d[i][j];
        }
    }
}

void avgPerShift(float d[3][7]) {
    for (int i = 0; i < 3; i++) {
        float sum = 0;
        for (int j = 0; j < 7; j++)
            sum += d[i][j];
        float avg = sum / 7;
        cout << "Shift " << i + 1 << " Avg Defects: " << avg << "\n";
        if (avg > 10)
            cout << "  → Critical Shift\n";
    }
}

void avgPerDay(float d[3][7]) {
    for (int j = 0; j < 7; j++) {
        float sum = 0;
        for (int i = 0; i < 3; i++)
            sum += d[i][j];
        cout << "Day " << j + 1 << " Avg Defects: " << sum / 3 << "\n";
    }
}

int main() {
    float defects[3][7];
    inputDefects(defects);
    avgPerShift(defects);
    avgPerDay(defects);
    return 0;
}
