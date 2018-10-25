#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Gauss {
    private:
        int count;
        int n;
    public:
        void analysis(int count, int n, const vector<vector<float>>& A, const vector<float>& b, vector<float>& x);
};

vector<vector<float>> set_and_get_matrix(int n) {
    vector<vector<float>> A(n, vector<float>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }
    return A;
}

vector<float> set_and_get_vector(int n) {
    vector<float> b(n);

    for(int i=0; i<n; i++) {
        cout << "b[" << i+1 << "] = ";
        cin >> b[i];
    }
    return b;
}

void Gauss::analysis(int count, int n, const vector<vector<float>>& A, const vector<float>& b, vector<float>& x) {
    double res=0, res_max;
    this->count = count;

    for(int k=0; k<count; k++) {
        res_max = 0;
        for(int i=0; i<n; i++) {
            res = b[i];
            for(int j=0; j<n; j++) {
                res += -A[i][j]*x[j];
            }
            if(res_max<fabs(res)) res_max = fabs(res_max);
            x[i] += res/A[i][i];
        cout << x[i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int n, count;
    cin >> n;

    Gauss gauss;
    vector<vector<float>> A = set_and_get_matrix(n);
    vector<float> b = set_and_get_vector(n);
    vector<float> x = {1.0, 1.0, 1.0};
    cout << "繰り返す回数 >> "; cin >> count;
    gauss.analysis(count, n, A, b, x);

    return 0;
}
