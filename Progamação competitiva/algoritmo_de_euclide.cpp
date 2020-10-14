#include <bits/stdc++.h>
#define ll long long

using namespace std;

/*

    mdc(x, y, z) = mdc(mdc(x, y), z), isso vale para N numeros inteiros

*/

int mdc(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return mdc(y, x % y);
    }
}

int main(int argc, char *argv[])
{
    cout << mdc(1000, 550);

    return 0;
}