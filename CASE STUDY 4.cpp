#include <iostream>
using namespace std;

void inputTemps(float t[5][5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Zone " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cout << "  Point " << j + 1 << ": ";
            cin >> t[i][j];
        }
    }
}

void rowAverages(float t[5][5]) {
    for (int i = 0; i < 5; i++) {
        float sum = 0;
        for (int j = 0; j < 5; j++)
            sum += t[i][j];
        cout << "Zone " << i + 1 << " Avg Temp: " << sum / 5 << "\n";
    }
}

void detectExtremes(float t[5][5]) {
    float maxT = t[0][0], minT = t[0][0];
    int maxRow = 0, maxCol = 0, minRow = 0, minCol = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (t[i][j] > maxT) {
                maxT = t[i][j]; maxRow = i; maxCol = j;
            }
            if (t[i][j] < minT) {
                minT = t[i][j]; minRow = i; minCol = j;
            }
        }

    cout << "Hottest Point: " << maxT << " at (" << maxRow + 1 << "," << maxCol + 1 << ")\n";
    cout << "Coldest Point: " << minT << " at (" << minRow + 1 << "," << minCol + 1 << ")\n";
}

int main() {
    float temp[5][5];
    inputTemps(temp);
    rowAverages(temp);
    detectExtremes(temp);
    return 0;
}
