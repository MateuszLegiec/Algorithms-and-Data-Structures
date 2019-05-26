#include <iostream>
#include <valarray>
#include <limits>
#include <iomanip>
#include <cassert>

using namespace std;

using matrix = valarray< valarray< double > >;
double const zero = 0;

matrix emptyMatrix(int n){
    valarray< double > temp(zero,n);
    return matrix(temp,n);
}

matrix qMatrix(matrix qr){
    int n = qr.size();
    int m = qr.size();

    matrix q = emptyMatrix(n);
    for(int i = 0;i<n;i++)
        q[i][i]=1;
    for (int i = 0; i < n; ++i) {
        for(int j=n;j > 0;j--){
            double sum = 0;
            for (int k = j; k < m; ++k)
                sum += qr[j][k] * q[i][k];
            for (int k = j; k < m; ++k)
                q[i][k] += qr[j][k] * sum;
        }
    }
    cout<<"MACIERZ Q"<<endl;
    displayMatrix(q);
    cout<<endl;
    return q;
}
matrix rMatrix(matrix qr,valarray< double > results){
    int n = qr.size();
    matrix r = emptyMatrix(n);
    for (int i = 0; i < n; ++i) {
        r[i][i] = results[i];
        for (int j = i + 1; j < n; ++j) {
            r[i][j] = qr[j][i];
        }
    }
    cout<<"MACIERZ R"<<endl;
    displayMatrix(r);
    cout<<endl;
    return r;
}
matrix qrMatrix(matrix q,matrix r,int n){
    matrix a = emptyMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] += q[i][j] * r[i][j];
        }
    }
    cout<<"MACIERZ QR"<<endl;
    displayMatrix(a);
    cout<<endl;
    return a;
}
void householder(matrix qr,int n){
    valarray< double > results(zero, qr.size());
    for (int j = 0; j < n; ++j) {
            double norm = 0;
            for (int i = j; i < n; ++i)
                norm += pow(qr[i][j],2);
            norm = sqrt(norm);
            results[j] = (0 < qr[j][j]) ? -norm : norm;
            double f = norm * (norm + abs(qr[j][j]));
            assert(numeric_limits< double >::epsilon() < f);
            f = 1 / sqrt(norm * (norm + abs(qr[j][j])));
            qr[j][j] -= results[j];
            for (int k = j; k < n; ++k) {
                qr[j][k] *= f;
            }
            for (int i = j + 1; i < n; ++i) {
                double dot_product = 0;
                for (int k = j; k < n; ++k)
                    dot_product += qr[j][k] * qr[i][k];
                for (int k = j; k < n; ++k)
                    qr[i][k] -= qr[j][k] * dot_product;
            }
        }
        cout<<"PIERWIASTKI ROWNANIA"<<endl;
        for(int i=0;i<n;i++){
            cout<<"X["<<i<<"] = "<<results[i]<<endl;
        }
        cout<<endl;
        qrMatrix(qMatrix(qr),rMatrix(qr,results),n);
}

