/*
Merge sort is a stable sorting algorithm (maintains relative order of equal elements)
which uses divide and conquer paradigm.
It's worst, average and best case complexity is O(nlogn)
T(n) = 2T(n/2) + cn
The space complexity when using an auxilary array is O(n)
It can be improved to O(1) using in-place merge sort.
*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int middle, int high, vector<int> &aux){
    int k = low;
    int i = low;
    int j = middle + 1;
    while(i <= middle && j <= high){
        if(arr[i] < arr[j])
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    }
    while(i <= middle){
        aux[k++] = arr[i++];
    }
    // no need to copy from the other part since it is already there
    for(i = low; i <= high; i++){
        arr[i] = aux[i];
    }
}

void mergeSort(vector<int> &arr, int i, int j, vector<int> &aux){
    if(i == j)
        return;
    int middle = i + ((j - i) >> 1);
    mergeSort(arr, i, middle, aux);
    mergeSort(arr, middle + 1, j, aux);
    merge(arr, i, middle, j, aux);
}

void printArr(vector<int> arr){
    cout<<"[";
    for(int i = 0; i < (int)arr.size(); i++){
        cout<<arr[i];
        if(i < (int)arr.size() - 1)
            cout<<",";
    }
    cout<<"]";
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector<int> aux = arr;
    mergeSort(arr, 0, n - 1, aux);
    printArr(arr);
    return 0;
}
