#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void main()
{
    int n;
    scanf("%d",&n);
    sieve_of_eratosthenes(n);
}
void sieve_of_eratosthenes(int n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(int p=i*i;p<=n;p=p+i)
                prime[p]=false;
        }
    }
    for(int p=2;p<=n;p++)
    {
        if(prime[p]==true)
            printf("%d ",p);
    }
}

