//
// Created by Yang Shuangzhen on 2020/10/12.
//

#include <iostream>
using namespace std;

int partition(int A[], int low, int high){
    int pivot = A[high];
    int i = low-1;
    int j = low;

    while (j<high){
        if (A[j] > pivot){
            int tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;
        }
        j++;
    }

    int tmp = A[i+1];
    A[i+1] = A[high];
    A[high] = tmp;

    return i+1;
}

void quickSort(int A[], int low, int high){
    if (low < high){
        int pi = partition(A, low, high);

        quickSort(A, low, pi-1);
        quickSort(A, pi+1, high);
    }
}


int main(){
    int n, x;
    cin >> n >> x;

    int score[n];
    for (int i=0; i<n; i++){
        cin >> score[i];
    }

    quickSort(score, 0, n-1);

    int min_score = score[x];
    int num_success = 0;
    for (int i=x; i >= 0; i--){
        if (score[i] > min_score && score[i] > 0){
            num_success++;
        }
    }
    cout << num_success << endl;
    return 0;
}