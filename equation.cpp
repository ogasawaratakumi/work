/*        3x3の連立１次方程式を解く
 *
 *               Ax = b
 *      
 *      | 5 1 1 |      | x1 |      | 10 |
 *      |       |      |    |      |    |
 *  A = | 1 4 1 |  x = | x2 |  b = | 12 |
 *      |       |      |    |      |    |
 *      | 2 1 3 |      | x3 |      | 13 |
 */
#include <iostream>
#include <vector>
#include "Eigen/Dense"
#include "matplotlibcpp.h"

using namespace std;
using namespace Eigen;
namespace plt = matplotlibcpp;

class Calculation {
    private:
        double x1, x2, x3;
        int count;
    public:
        vector<Vector3d> A;
        vector<Vector3d> b;
        vector<double> x1_list, x2_list, x3_list;
        vector<double> round;
        Calculation(double x1, double x2, double x3);
        void set_matrix();
        void set_vector();
        void analysis(int count);
        void graph_show();


};

double get_x1(double x2, double x3, double A1 , double A2, double A3, double b1) {
    return ((b1 - A2 * x2 -A3 * x3) / A1);
}

double get_x2(double x1, double x3, double A4, double A5, double A6, double b2) {
    return ((b2 - A4 * x1- A6 * x3) / A5);
}

double get_x3(double x1, double x2, double A7, double A8, double A9, double b3) {
    return ((b3 - A7 * x1 - A8 * x2) / A9);
}

Calculation::Calculation(double x1, double x2, double x3) {
    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
}

void Calculation::set_matrix() {
    this->A.push_back(Vector3d(5.0, 1.0, 1.0));
    this->A.push_back(Vector3d(1.0, 4.0, 1.0));
    this->A.push_back(Vector3d(2.0, 1.0, 3.0));
}

void Calculation::set_vector() {
    this->b.push_back(Vector3d(10.0, 12.0, 13.0));
}

void Calculation::analysis(int count) {
    this->count = count;

    for(int i=1; i<=count; i++) {
        x1 = get_x1(x2, x3, A[0][0], A[0][1], A[0][2], b[0][0]);
        x2 = get_x2(x1, x3, A[1][0], A[1][1], A[1][2], b[0][1]);
        x3 = get_x3(x1, x2, A[2][0], A[2][1], A[2][2], b[0][2]);
        x1_list.push_back(x1);
        x2_list.push_back(x2);
        x3_list.push_back(x3);
        round.push_back(i);
        cout << i << "round : " << x1 << ' ' << x2 << ' ' << x3 << endl;
    }

}

void Calculation::graph_show() {
    plt::xlabel("round");
    plt::named_plot("x1", round, x1_list);
    plt::named_plot("x2", round, x2_list);
    plt::named_plot("x3", round, x3_list);
    plt::legend();
    plt::show();
}

int main() {
    double x1, x2, x3;
    int n;

    cout << "x1~x3の初期値設定してください." << endl;
    cout << "x1 = "; cin >> x1;
    cout << "x2 = "; cin >> x2;
    cout << "x3 = "; cin >> x3;

    Calculation obj(x1, x2, x3);

    obj.set_matrix();
    obj.set_vector();

    cout << "何回繰り返しますか？"; cin >> n;
    obj.analysis(n);

    obj.graph_show();

    return 0;
}
