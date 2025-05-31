#include <iostream>
using namespace std;

void inputStatus(char s[5][7]) {
    for (int i = 0; i < 5; i++) {
        cout << "Patient " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> s[i][j];
        }
    }
}

void countStatus(char s[5][7]) {
    int stable = 0, critical = 0, recovered = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++) {
            if (s[i][j] == 'S') stable++;
            else if (s[i][j] == 'C') critical++;
            else if (s[i][j] == 'R') recovered++;
        }
    cout << "Stable: " << stable << ", Critical: " << critical << ", Recovered: " << recovered << "\n";
}

void criticalDays(char s[5][7]) {
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 7; j++)
            if (s[i][j] == 'C') count++;
        cout << "Patient " << i + 1 << " Critical Days: " << count << "\n";
    }
}

int main() {
    char status[5][7];
    inputStatus(status);
    countStatus(status);
    criticalDays(status);
    return 0;
}
