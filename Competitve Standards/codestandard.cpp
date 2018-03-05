#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAX = 1000010;

long long iter, was[MAX];
int pa[MAX], pb[MAX];
vector <int> g[MAX];
int a[MAX][7];

bool dfs(int v) {
  was[v] = iter;
  for (int j : g[v]) {
    if (pb[j] == -1) {
      pa[v] = j;
      pb[j] = v;
      return true;
    }
  }
  for (int j : g[v]) {
    if (was[pb[j]] != iter) {
      if (dfs(pb[j])) {
        pa[v] = j;
        pb[j] = v;
        return true;
      }
    }
  }
  return false;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < MAX; i++) {
      g[i].clear();
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 6; j++) {
        scanf("%d", a[i] + j);
        g[a[i][j]].push_back(i);
      }
    }
    for (int i = 0; i < MAX; i++) {
      random_shuffle(g[i].begin(), g[i].end());
    }
    for (int i = 0; i < MAX; i++) {
      pa[i] = -1;
      was[i] = -1;
    }
    for (int j = 0; j < n; j++) {
      pb[j] = -1;
    }
    int ans = 0;
    int rr = 0;
    iter = 0;
    for (int ll = 1; ll < MAX; ll++) {
      rr = max(rr, ll - 1);
      while (true) {
        iter++;
        if (dfs(rr + 1)) {
          rr++;
        } else {
          break;
        }
      }
      ans = max(ans, rr - ll + 1);
      if (pa[ll] != -1) {
        pb[pa[ll]] = -1;
        pa[ll] = -1;
      }
    }
    printf("%d\n", ans);
    cerr << "test " << qq << "/" << tt << " solved, time = " << clock() << " ms" << endl;
  }
  return 0;
}
