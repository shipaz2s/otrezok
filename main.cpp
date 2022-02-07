#include <iostream>
#include <cmath>
#include <valarray>

using namespace std;


template <typename T>
T coords_sum(valarray<T> vec)
{
    T sum = 0;
    for(auto v: vec) {
        sum += v;
    }
    return sum;
}

template<typename T>
T distance(valarray<T> v1, valarray<T> v2)
{
    if (v1.size() != v2.size()) throw std::length_error{"distance: vectors must have the same size"};

    T dist = 0;
    for (int i = 0; i != v1.size(); ++i) {
        dist += pow(v1[i] - v2[i], 2);
    }

    dist = sqrt(dist);

    return dist;
}

int main()
{

    /*
    valarray<double> A[3] = {9, 7, 0};
    valarray<double> B[3] = {11, 4, 0};
    valarray<double> C[3] = {3, 0, 5};
    valarray<double> D[3] = {6, 0, 1};
    */

    /*
    valarray<double> A[3] = {9, 7, 0};
    valarray<double> B[3] = {13, 1, 0};
    valarray<double> C[3] = {3, 0, 5};
    valarray<double> D[3] = {9, 0, -3};
    */

    /*
    valarray<double> A = {6, 4, 0};
    valarray<double> B = {11, 4, 0};
    valarray<double> C = {3, -1, 5};
    valarray<double> D = {7, -1, 0};
    */

    valarray<double> A = {6, 4, 0};
    valarray<double> B = {11, 4, 0};
    valarray<double> C = {3, -1, 0};
    valarray<double> D = {7, -1, 0};

    char res;

    do {
        cout << "Использовать тестовые данные(y/n)?\n";
        res = getchar();
    } while ( (res != 'y') and (res != 'Y') and (res != 'n') and (res != 'N') );

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


    auto a_ar = ( (A-B) * (A-B) );
    auto b_ar = ( (B-D) * (C-D) );
    auto g_ar = ( (A-B) * (C-D) );
    auto d_ar = ( (C-D) * (C-D) );
    auto e_ar = ( (D-C) * (A-B) );
    auto z_ar = ( (B-D) * (A-B) );

    a = coords_sum(valarray<double>( (A-B) * (A-B) ));
    b = coords_sum(valarray<double>( (B-D) * (C-D) ));
    g = coords_sum(valarray<double>( (A-B) * (C-D) ));
    d = coords_sum(valarray<double>( (C-D) * (C-D) ));
    e = coords_sum(valarray<double>( (D-C) * (A-B) ));
    z = coords_sum(valarray<double>( (B-D) * (A-B) ));

    double r {0};

    if ( (a*d + g*e) == 0) {
        cout << "Параллельные отрезки\n";
        //Дописать код

        double rs[4] = {0, 0, 0, 0}; //ac ad bc bd
        rs[0] = distance(A,C);
        rs[1] = distance(A,D);
        rs[2] = distance(B,C);
        rs[3] = distance(B,D);

        for ( int i = 0; i < 4; ++i) {
            if (r > rs[i]) {
                r = rs[i];
            }
        }

    } else {

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

        r = coords_sum(valarray<double>(t*A + (1-t)*B - s*C -(1-s)*D));

    }


    cout << "Расстояние мжду отрезками r = " << r << endl;

    return 0;
}
