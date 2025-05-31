#include <iostream>
using namespace std;

void inputStatus(char b[5][5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cout << "  Book " << j + 1 << ": ";
            cin >> b[i][j];
        }
    }
}

void countBooks(char b[5][5]) {
    int a = 0, i = 0, m = 0;
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 5; y++) {
            if (b[x][y] == 'A') a++;
            else if (b[x][y] == 'I') i++;
            else if (b[x][y] == 'M') m++;
        }
    cout << "Available: " << a << ", Issued: " << i << ", Missing: " << m << "\n";
}

void findMostMissing(char b[5][5]) {
    int max = 0, row = 0;
    for (int i = 0; i < 5; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++)
            if (b[i][j] == 'M') cnt++;
        if (cnt > max) {
            max = cnt;
            row = i;
        }
    }
    cout << "Shelf with most missing books: " << row + 1 << "\n";
}

int main() {
    char books[5][5];
    inputStatus(books);
    countBooks(books);
    findMostMissing(books);
    return 0;
}
