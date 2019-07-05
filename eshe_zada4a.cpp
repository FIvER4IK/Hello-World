#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 100000000;

int n;
int arr[100][100];
int D[100] = { -1 };
int color[100];

void init(int v) {
    for (int i = 0; i < n; i++) {
        D[i] = inf;
        color[i] = 0;
    }
    D[v] = 0;
    color[v] = 1;
}

void relax(int x) {
    for (int i = 0; i < n; i++) {
        if (D[i] > D[x] + arr[x][i]) {
            D[i] = D[x] + arr[x][i];
        }
    }
}

int findMin() {
    int x = -1;
    int dist = inf;
    for (int i = 0; i < n; i++) {
        if (D[i] < dist&&color[i] == 0) {
            x = i;
            dist = D[i];
        }
    }
    return x;
}

void Dijkstra(int v) {
    init(v);
    relax(v);
    for (int x = findMin(); x != -1; x = findMin()) {
        color[x] = 1;
        relax(x);
    }
}

int main() {
    cin >> n;
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                arr[i][j] = inf;
            }
        }
    }
    Dijkstra(a);

    if (D[b] == inf) cout << -1;
    else cout << D[b];
    system("pause");
    return 0;
}