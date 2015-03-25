// reduce Hessenberg form (inplace). 
// O ( n^3 )
void hessenberg(matrix &A) {
    const int n = A.size();
    for (int k = 1; k <= n-2; ++k) {
        array u(n);
        for (int i = k; i < n; ++i) u[i] = A[i][k-1];

        number ss = 0;
        for (int i = k+1; i < n; ++i) ss += u[i] * u[i];
        if (abs(ss) <= 0.0) continue;
        number s = sqrt( ss + u[k]*u[k] );
        if (u[k] > 0.0) s = -s;

        u[k] -= s;
        number uu = sqrt( ss + u[k]*u[k] );
        for (int i = k; i < n; ++i) u[i] /= uu;

        array f(n), g(n);
        for (int i = 0; i < n; ++i)
            for (int j = k; j < n; ++j)
                f[i] += A[i][j] * u[j],
                    g[i] += A[j][i] * u[j];
        number gamma = inner_product(u, g);
        for (int i = 0; i < n; ++i)
            f[i] -= gamma * u[i],
                g[i] -= gamma * u[i];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                A[i][j] = A[i][j] - 2*u[i]*g[j] - 2*f[i]*u[j];
    }
}

// find all eigenvalues using Hessenberg-QR Method
// O( n^3 + M n^2 ) where M is the number of iterations.
vector<number> eigenvalues(matrix A) {
    const int n = A.size();
    hessenberg(A);
    vector<number> s(n), c(n);
    for (int m = n; m >= 2; ) {
        if (abs(A[m-1][m-2]) < eps) { --m; continue; }
        number shift = A[m-1][m-1];
        for (int i = 0; i < m; ++i) A[i][i] -= shift;
        for (int k = 0; k < m-1; ++k) {
            number a = A[k][k], b = A[k+1][k], r = sqrt(a*a + b*b);
            s[k] = r == 0.0 ? 0.0 : b/r,
                c[k] = r == 0.0 ? 0.0 : a/r;
            for (int j = k; j < m; ++j) {
                number x = A[k][j], y = A[k+1][j];
                A[ k ][j] =  c[k] * x + s[k] * y;
                A[k+1][j] = -s[k] * x + c[k] * y;
            }
        }
        for (int k = 0; k < m-1; ++k) {
            for (int i = 0; i <= k+1; ++i) {
                number x = A[i][k], y = A[i][k+1];
                A[i][ k ] =  c[k] * x + s[k] * y;
                A[i][k+1] = -s[k] * x + c[k] * y;
            }
        }
        for (int i = 0; i < m; ++i) A[i][i] += shift;
    }
    vector<number> lambda;
    for (int i = 0; i < n; ++i)
        lambda.push_back( A[i][i] );
    return lambda;
}

// find the corresponding eigenvector from the eigenvalue.
// O ( n^3 + M n^2 ) where M is the number of iterations.
array eigenvector(matrix A, number lambda) {
    const int n = A.size();
    array y(n); y[0] = 1;
    for (int i = 0; i < n; ++i) A[i][i] -= lambda;
    LUinfo data = LU_decomposition(A);
    number mu, v2, v2s;
    do {
        array v = LU_backsubstitution(data, y); // A v = y 
        mu = inner_product(v, y);
        v2 = inner_product(v, v);
        v2s = sqrt(v2);
        for (int j = 0; j < n; ++j) y[j] = v[j] / v2s;
    } while (abs(1.0-mu*mu/v2) > eps);
    return y;
}

