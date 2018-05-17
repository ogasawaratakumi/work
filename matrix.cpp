//d=[1 0 0]の転置行列を掛け、x,y,z軸にangle回転したベクトルを表す。
#include <iostream>
#include <cmath>
#include "Eigen/Dense"
int main()
{
    double angle;
    double a; //角度
    char flag; //軸選択

    std::cout << "どの軸に何度回転させますか。" << std::endl;
    std::cout << "軸を入力：";    std::cin >> flag;
    std::cout << "角度を入力：";  std::cin >> a;
    angle = a*M_PI/180.0;

    Eigen::MatrixXd d(3,1);
    d << 1,
         0,
         0;

    //Xの回転行列
    Eigen:: Matrix3d X;
    X << 1,0,0,
         0,cos(angle),-sin(angle),
         0,sin(angle),cos(angle);

    //Yの回転行列
    Eigen:: Matrix3d Y;
    Y << cos(angle),0,sin(angle),
         0,1,0,
         -sin(angle),0,cos(angle);

    //Zの回転行列
    Eigen:: Matrix3d Z;
    Z << cos(angle),-sin(angle),0,
         sin(angle),cos(angle),0,
         0,0,1;

    Eigen::MatrixXd answer(3,1);
    answer << 0,
              0,
              0;

    switch(flag){
        case 'x':
            std::cout << X*d << std::endl;
            break;
        case 'y':
            std::cout << Y*d << std::endl;
            break;
        case 'z':
            std::cout << Z*d << std::endl;
            break;
    }

    return 0;
}
