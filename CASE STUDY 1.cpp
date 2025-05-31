#include <iostream>
using namespace std;

void inputMarks(int m[10][5]) {
    for (int i = 0; i < 10; i++) {
        cout << "Student " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> m[i][j];
        }
    }
}

void computeTotals(int m[10][5], int total[10], float avg[10]) {
    for (int i = 0; i < 10; i++) {
        total[i] = 0;
        for (int j = 0; j < 5; j++)
            total[i] += m[i][j];
        avg[i] = total[i] / 5.0;
    }
}

int findTopper(int total[10]) {
    int max = 0;
    for (int i = 1; i < 10; i++)
        if (total[i] > total[max])
            max = i;
    return max;
}

void displayGrades(float avg[10]) {
    for (int i = 0; i < 10; i++) {
        char grade;
        if (avg[i] >= 80) grade = 'A';
        else if (avg[i] >= 60) grade = 'B';
        else if (avg[i] >= 40) grade = 'C';
        else grade = 'F';
        cout << "Student " << i + 1 << ": Grade " << grade << "\n";
    }
}

int main() {
    int marks[10][5], total[10];
    float avg[10];
    inputMarks(marks);
    computeTotals(marks, total, avg);
    int top = findTopper(total);
    cout << "Top Scorer: Student " << top + 1 << "\n";
    displayGrades(avg);
    return 0;
}
