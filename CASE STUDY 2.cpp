#include <iostream>
using namespace std;

void inputSales(float s[4][7]) {
    for (int i = 0; i < 4; i++) {
        cout << "Item " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> s[i][j];
        }
    }
}

void itemTotals(float s[4][7], float item[4]) {
    for (int i = 0; i < 4; i++) {
        item[i] = 0;
        for (int j = 0; j < 7; j++)
            item[i] += s[i][j];
    }
}

void dayTotals(float s[4][7], float day[7]) {
    for (int j = 0; j < 7; j++) {
        day[j] = 0;
        for (int i = 0; i < 4; i++)
            day[j] += s[i][j];
    }
}

int bestDay(float day[7]) {
    int max = 0;
    for (int i = 1; i < 7; i++)
        if (day[i] > day[max]) max = i;
    return max;
}

int topItem(float item[4]) {
    int max = 0;
    for (int i = 1; i < 4; i++)
        if (item[i] > item[max]) max = i;
    return max;
}

int main() {
    float sales[4][7], item[4], day[7];
    inputSales(sales);
    itemTotals(sales, item);
    dayTotals(sales, day);
    cout << "Top Item: Item " << topItem(item) + 1 << "\n";
    cout << "Highest Sales Day: Day " << bestDay(day) + 1 << "\n";
    return 0;
}
