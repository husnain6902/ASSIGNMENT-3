#include <iostream>
using namespace std;

void inputScores(int s[6][4]) {
    for (int i = 0; i < 6; i++) {
        cout << "Team " << i + 1 << ":\n";
        for (int j = 0; j < 4; j++) {
            cout << "  Round " << j + 1 << ": ";
            cin >> s[i][j];
        }
    }
}

void teamTotals(int s[6][4], int t[6]) {
    for (int i = 0; i < 6; i++) {
        t[i] = 0;
        for (int j = 0; j < 4; j++)
            t[i] += s[i][j];
    }
}

void findWinners(int t[6]) {
    int max = 0, runner = -1;
    for (int i = 1; i < 6; i++)
        if (t[i] > t[max]) max = i;

    for (int i = 0; i < 6; i++) {
        if (i != max && (runner == -1 || t[i] > t[runner])) runner = i;
    }

    cout << "Winner: Team " << max + 1 << "\n";
    cout << "Runner-Up: Team " << runner + 1 << "\n";
}

void checkFailures(int s[6][4]) {
    for (int i = 0; i < 6; i++) {
        bool failed = false;
        for (int j = 0; j < 4; j++) {
            if (s[i][j] <= 10)
                failed = true;
        }
        if (failed)
            cout << "Team " << i + 1 << " scored 10 or less in a round.\n";
    }
}

int main() {
    int score[6][4], total[6];
    inputScores(score);
    teamTotals(score, total);
    findWinners(total);
    checkFailures(score);
    return 0;
}
