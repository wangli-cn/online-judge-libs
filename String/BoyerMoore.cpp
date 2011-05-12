int *buildSkip(char *p) {
  int m = strlen(p);
  int *skip = new int[0x100];
  for (int i = 0; i < m; ++i)
    skip[p[i]] = m-i-1;
  return skip;
}
int *buildNext(char *p) {
  int m = strlen(p);
  int g[m]; fill(g, g+m, m);
  int *next = new int[m];
  for (int i = 0; i < m; ++i)
    next[i] = 2*m-i-1;
  int j = m;
  for (int i = m-1; i >= 0; --i, --j) {
    g[i] = j;
    while (j < m && p[j] != p[i]) {
      next[j] = min(next[j], m-i-1);
      j = g[j];
    }
  }
  for (int i = 0; i < m; ++i) {
    next[i] = min(next[i], j+m-i);
    if (i >= j) j = g[j];
  }
  return next;
}
int match(char *t, char *p, int *skip, int *next) {
  int n = strlen(t), m = strlen(p);
  int count = 0;
  for (int i = m-1; i < n; ) {
    int j = m-1;
    while (j >= 0 && t[i] == p[j]) --i, --j;
    if (j < 0) {
      ++count; // match at text[i+1, ..., i+m]
      i += m + 1;
    } else i += max(skip[t[i]], next[j]);
  }
  return count;
}

