#include <iostream>
using namespace std;

void showSeats(char s[6][4]) {
    cout << "Seat Layout:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++)
            cout << s[i][j] << " ";
        cout << "\n";
    }
}

void bookSeat(char s[6][4], int row, int col) {
    if (s[row][col] == 'E') {
        s[row][col] = 'B';
        cout << "Seat booked.\n";
    }
    else {
        cout << "Already booked.\n";
    }
}

int countEmpty(char s[6][4]) {
    int count = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            if (s[i][j] == 'E') count++;
    return count;
}

int rowMaxEmpty(char s[6][4]) {
    int max = 0, row = 0;
    for (int i = 0; i < 6; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++)
            if (s[i][j] == 'E') count++;
        if (count > max) {
            max = count;
            row = i;
        }
    }
    return row;
}

int main() {
    char seats[6][4];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            seats[i][j] = 'E';

    showSeats(seats);
    bookSeat(seats, 2, 1);
    cout << "Available Seats: " << countEmpty(seats) << "\n";
    cout << "Row with most empty seats: " << rowMaxEmpty(seats) + 1 << "\n";
    return 0;
}
