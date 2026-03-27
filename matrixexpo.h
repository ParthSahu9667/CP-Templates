vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < n; j++) {
                C[i][j] = (1ll * C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return C;
}       

vector<vector<int>> matrixExpo(vector<vector<int>> &A, int p) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    while(p > 0) {
        if(p % 2 == 1) {
            result = multiply(result, A);
        }
        A = multiply(A, A);
        p /= 2;
    }
    return result;
}