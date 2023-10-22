#include <iostream>

using namespace std;

bool isPass(int x, int y, int **area, int size) {
  return (x >= 0 && x < size && y >= 0 && y < size && area[x][y] == 0);
}

bool findPath(int x, int y, int **area, int size) {
  if (x == size - 1 && y == size - 1) {
    return true;
  }

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  for (int i = 0; i < size - 1; ++i) {
    int newX = x + dx[i];
    int newY = y + dy[i];

    if (isPass(newX, newY, area, size)) {
      area[newX][newY] = 2;

      if (findPath(newX, newY, area, size)) {
        return true;
      }

      area[newX][newY] = 0;
    }
  }
  return false;
}

int main() {
  int n, i, j;

  cin >> n;
  int **forest = new int *[n];

  for (i = 0; i < n; i++) {
    forest[i] = new int[n];
    for (j = 0; j < n; j++) {
      cin >> forest[i][j];
    }
  }

  if (findPath(0, 0, forest, n)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}