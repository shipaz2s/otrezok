#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    /*
    double A[3] = {9, 7, 0};
    double B[3] = {11, 4, 0};
    double C[3] = {3, 0, 5};
    double D[3] = {6, 0, 1};
    */

    /*
    double A[3] = {9, 7, 0};
    double B[3] = {13, 1, 0};
    double C[3] = {3, 0, 5};
    double D[3] = {9, 0, -3};
    */


    double A[3] = {6, 4, 0};
    double B[3] = {11, 4, 0};
    double C[3] = {3, -1, 5};
    double D[3] = {7, -1, 0};



    char res;

    while ( (res != 'y') and (res != 'Y') and (res != 'n') and (res != 'N') ) {
        cout << "Использовать тестовые данные(y/n)?\n";
        res = getchar();
    }

    if ( (res == 'n') or (res == 'N') ) {

        cout << "Введите координаты концов отрезков AB и CD" << endl;
        cout << "в формате x y z" << endl;

        cout << "A: ";
        cin >> A[0] >> A[1] >> A[2];
        cout << "B: ";
        cin >> B[0] >> B[1] >> B[2];
        cout << "C: ";
        cin >> C[0] >> C[1] >> C[2];
        cout << "D: ";
        cin >> D[0] >> D[1] >> D[2];
    }


    cout << "A (" << A[0] << "; " << A[1] << "; " << A[2] << ")" << endl;
    cout << "B (" << B[0] << "; " << B[1] << "; " << B[2] << ")" << endl;
    cout << "C (" << C[0] << "; " << C[1] << "; " << C[2] << ")" << endl;
    cout << "D (" << D[0] << "; " << D[1] << "; " << D[2] << ")" << endl;

    double a = 0, b = 0, g = 0, d = 0, e = 0, z = 0;
    for (int i = 0; i < 3; ++i) {
        a += pow(A[i] - B[i], 2);
        b += (B[i] - D[i]) * (C[i] - D[i]);
        g += (A[i] - B[i]) * (C[i] - D[i]);
        d += pow(C[i] - D[i], 2);
        e += (D[i] - C[i]) * (A[i] - B[i]);
        z += (B[i] - D[i]) * (A[i] - B[i]);
    }

    double t = -(z*d + b*e)/(a*d + g*e);
    double s = (b + t*g)/d;

    if (t > 1) {
        t = 1;
    } else if (t < 0) {
        t = 0;
    }

    if (s > 1) {
        s = 1;
    } else if (s < 0) {
        s = 0;
    }

    double r2 = 0;
    double r;

    for (int i = 0; i < 3; ++i) {
        r2 += pow(t * A[i] + (1-t)*B[i] - s*C[i] - (1-s)*D[i], 2);
    }
    r = sqrt(r2);

    if ( (a*d + g*e) == 0) {
        double rs[4] = {0, 0, 0, 0}; //ac ad bc bd
        for ( int i = 0; i < 3; ++i) {
            rs[0] += pow(A[i] - C[i],2);
            rs[1] += pow(A[i] - D[i],2);
            rs[2] += pow(B[i] - C[i],2);
            rs[3] += pow(B[i] - D[i],2);
        }
        for ( int i = 0; i < 4; ++i) {
            rs[i] = sqrt(rs[i]);
        }
        r = rs[0];
        for ( int i = 0; i < 4; ++i) {
            if (r > rs[i]) {
                r = rs[i];
            }
        }
    }

    cout << "Расстояние мжду отрезками r = " << r << endl;

    return 0;
}
