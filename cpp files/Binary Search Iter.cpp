#include<iostream>
using namespace std;
int binarySearch(int [], int, int, int);

int main() {
    int a[10], i, h, elem, result;
    cout <<"Enter the number of elements in the array\n";
    cin >> h;
    cout <<"Enter the elements one by one\n";
    for(i=0; i<h; i++)
        cin >> a[i];
    cout <<"Enter the element to be found\n";
    cin >> elem;
    result = binarySearch(a, 0, h-1, elem);
    (result == -1) ? cout<<"Not found" : cout <<"Element present at "<<result; 
    return 0;
}

int binarySearch(int a[], int low, int high, int x) {
    while(low <= high) {
        int mid = (low + high)/2;
        if(a[mid] > x)
            high = mid - 1;
        else if(a[mid] < x)
            low = mid + 1; 
        else 
            return mid;
    }
    return -1; 
}