//
// Created by Yang Shuangzhen on 2020/10/12.
//

#include <iostream>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int rest_1,  rest_2;
    cin >> rest_1 >> rest_2;

    int min_cookie = a < b ? a : b;
    int max_cookie = a > b ? a : b;

    if (rest_1 > max_cookie || rest_2 > max_cookie){
        cout << "NO" << endl;
        return 0;
    }

    if (rest_1 < min_cookie || rest_2 < min_cookie){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}