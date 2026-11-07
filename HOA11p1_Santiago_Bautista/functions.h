#ifndef FUNCTIONS_H
#define FUNCTIONS_H


// ====================================================================
// ILO A: Measure the runtime of algorithms using theoretical analysis
// ====================================================================
template <typename T>
bool search(T x, T y[], int m) {
    for (int i = 0; i < m; i++) {
        if (y[i] == x) {
            return true;
        }
    }

    return false;
}

template <typename T>
bool different(T x[], T y[], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (search(x[i], y, m)) {
            return false;
        }
    }

    return true;
}
// ====================================================================

// ====================================================================
/* ILO B: Analyze the results of runtime performance by comparing 
                    experimental and theoretical analysis*/
// ====================================================================




#endif
