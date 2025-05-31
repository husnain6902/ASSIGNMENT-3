#include <iostream>
using namespace std;

void inputVotes(int v[4][6]) {
    for (int i = 0; i < 4; i++) {
        cout << "Candidate " << i + 1 << ":\n";
        for (int j = 0; j < 6; j++) {
            cout << "  Station " << j + 1 << ": ";
            cin >> v[i][j];
        }
    }
}

void totalPerCandidate(int v[4][6]) {
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 6; j++)
            sum += v[i][j];
        cout << "Candidate " << i + 1 << ": " << sum << " votes\n";
    }
}

void totalPerStation(int v[4][6]) {
    for (int j = 0; j < 6; j++) {
        int sum = 0;
        for (int i = 0; i < 4; i++)
            sum += v[i][j];
        cout << "Station " << j + 1 << ": " << sum << " votes\n";
        if (sum < 100)
            cout << "  → Turnout below 100\n";
    }
}

void findWinner(int v[4][6]) {
    int max = 0, winner = 0;
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 6; j++)
            sum += v[i][j];
        if (sum > max) {
            max = sum;
            winner = i;
        }
    }
    cout << "Winner: Candidate " << winner + 1 << "\n";
}

int main() {
    int votes[4][6];
    inputVotes(votes);
    totalPerCandidate(votes);
    totalPerStation(votes);
    findWinner(votes);
    return 0;
}
