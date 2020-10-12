//
// Created by Yang Shuangzhen on 2020/10/12.
//

#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int maxSubarraySumCircular(vector<int>& A) {
    int sizz=A.size();
    if(sizz==0){
        return 0;
    }
    int sum=A[0];
    int summ=A[0];
    int maxx=A[0];
    int minn=0;
    int all=A[0];
    for(int i=1;i<sizz;i++){
        sum=max(A[i],sum+A[i]);
        maxx=max(sum,maxx);

        summ=min(A[i],summ+A[i]);
        minn=min(summ,minn);

        all+=A[i];
    }
    return maxx<0 ? maxx:max(maxx,all-minn);
}


int main(){
    int n_grp, n;
    cin >> n_grp >> n;
    while (n_grp--){
        vector<int> A(n, 0);
        int res = 0;
        for (int i=0; i<n; i++){
            cin >> A[i];
        }
        res = maxSubarraySumCircular(A);
        cout << res << endl;
    }
    return 0;
}