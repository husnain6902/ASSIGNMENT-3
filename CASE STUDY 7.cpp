#include <iostream>
using namespace std;

void inputRatings(int r[5][10]) {
    for (int i = 0; i < 5; i++) {
        cout << "Product " << i + 1 << ":\n";
        for (int j = 0; j < 10; j++) {
            cout << "  User " << j + 1 << ": ";
            cin >> r[i][j];
        }
    }
}

void computeAverages(int r[5][10], float avg[5]) {
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++)
            sum += r[i][j];
        avg[i] = sum / 10.0;
    }
}

void countPerfect(int r[5][10]) {
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++)
            if (r[i][j] == 5) count++;
        cout << "Product " << i + 1 << ": " << count << " perfect ratings.\n";
    }
}

void findWorst(float avg[5]) {
    float min = avg[0];
    for (int i = 1; i < 5; i++)
        if (avg[i] < min) min = avg[i];

    cout << "Lowest rated product(s):\n";
    for (int i = 0; i < 5; i++)
        if (avg[i] == min)
            cout << "Product " << i + 1 << " with avg " << avg[i] << "\n";
}

int main() {
    int ratings[5][10];
    float avg[5];
    inputRatings(ratings);
    computeAverages(ratings, avg);
    countPerfect(ratings);
    findWorst(avg);
    return 0;
}
