/
// Created by nobodyn0se on 15-08-2019.
//

#include<iostream>
using namespace std;
void read(int [][10], int, int);
void printm(int [][10], int, int);
void multiply(int [][10], int [][10], int, int);

void read(int a[][10], int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    }
}

void printm(int a[][10], int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cout << a[i][j] <<" ";
        cout << endl;
    }

}

void multiply(int a[][10], int b[][10], int m, int n)
{
    int c[m][n];
    for(int i=0; i<m; i++)  //for rows
    {
        for(int j=0; j<n; j++)  //for columns
        {
            c[i][j] = 0;
            for(int k=0; k<n; k++)  //for final multiplcation
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns\n";
    cin >> m >> n;
    int a[10][10], b[10][10];
    cout << "Enter the elements of matrix 1\n";
    read(a, m, n);
    cout << "Enter the elements of matrix 2\n";
    read(b, m, n);
    int c[10][10];
    cout << "Here is the matrix multiplication result\n";
    multiply(a, b, m, n);
    return 0;
}
