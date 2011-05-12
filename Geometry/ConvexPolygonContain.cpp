enum { OUT, ON, IN };
int convex_contains(const polygon &P, const point &p) {
  const int n = P.size();
  point g = (P[0] + P[n/3] + P[2*n/3]) / 3.0; // inner-point
  int a = 0, b = n;
  while (a+1 < b) { // invariant: c is in fan g-P[a]-P[b]
    int c = (a + b) / 2;
    if (cross(P[a]-g, P[c]-g) > 0) { // angle < 180 deg
      if (cross(P[a]-g, p-g) > 0 && cross(P[c]-g, p-g) < 0) b = c;
      else                                                  a = c;
    } else {
      if (cross(P[a]-g, p-g) < 0 && cross(P[c]-g, p-g) > 0) a = c;
      else                                                  b = c;
    }
  }
  b %= n;
  if (cross(P[a] - p, P[b] - p) < 0) return 0;
  if (cross(P[a] - p, P[b] - p) > 0) return 2;
  return 1;
}
