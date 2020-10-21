//
// Created by Yang Shuangzhen on 2020/10/18.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;


long factorial(long number)
{
    if(number <= 1)
        return 1;
    else
        return number * factorial(number-1);
}

int combinator(int n, int m) {
    int temp;
    if (n < m) {
        temp = n;
        n = m;
        m = temp;
    }
    return factorial(n) / (factorial(m) * factorial(n - m));
}

int main(){
    int nGrp;
    int ni, ki;
    double xi;
    std::vector<int> n,  k;
    std::vector<double> x;

    cin >> nGrp;
    for (int i=nGrp; i>0; i--){
        cin >> ni >> ki >> xi;
        n.push_back(ni);
        k.push_back(ki);
        x.push_back(xi);
    }
    cout<<setiosflags(ios::fixed)<<setprecision(6);

    double res = 0.0f;
    for (int j=0; j<nGrp; j++) {
        for (int i = k[j]; i<=n[j]; i++){
            res += combinator(n[j], i) * pow(x[j], i) * pow(1-x[j], n[j]-i);
        }
        cout << res << " ";
        res = 0.0f;
    }

    return 0;
}
