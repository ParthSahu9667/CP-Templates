vector<double> berlekamp_massey(vector<double> s) {
    int n = s.size();
    vector<double> C(1, 1), B(1, 1);
    int L = 0, m = 1;
    double b = 1;

    for (int i = 0; i < n; i++) {
        double d = 0;
        for (int j = 0; j <= L; j++) {
            d += C[j] * s[i - j];
        }
        
        if (abs(d) < 1e-9) {
            m++;
        } else {
            vector<double> T = C;
            double coef = d / b;
            
            while (C.size() < B.size() + m) C.push_back(0);
            
            for (int j = 0; j < B.size(); j++) {
                C[j + m] -= coef * B[j];
            }
            
            if (2 * L <= i) {
                L = i + 1 - L;
                B = T;
                b = d;
                m = 1;
            } else {
                m++;
            }
        }
    }
    
    vector<double> res;
    for (int i = 1; i < C.size(); i++) {
        res.push_back(-C[i]); 
    }
    return res;
}