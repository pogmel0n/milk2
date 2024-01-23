/*
ID: aqua4fan1
PROG: milk2
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool sortcol(int* a, int* b) {
    return a[0] < b[0];
}

int main() {
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");

    int n;
    fin >> n;

    int times[n][2];

    for (int i = 0; i < n; i++) {
        fin >> times[i][0] >> times[i][1];
    }

    sort(times, times + n, [](const int* a, const int* b) {
        return a[0] < b[0];
    });
    
    int milktime = 0;
    int maxmilk = 0;
    int maxidle = 0;
    
    for (int i = 0; i < n; i++) {
        if (milktime == 0) {
            milktime += (times[i][1] - times[i][0]);
        }
        else if (times[i - 1][1] >= times[i][0]) {
            milktime += (times[i][1] - times[i - 1][1]);
        }
        else {
            maxidle = max(maxidle, times[i][0] - times[i - 1][1]);
            milktime = 0;
        }

        maxmilk = max(milktime, maxmilk);
    }

    fout << maxmilk << " " << maxidle << endl;
}
