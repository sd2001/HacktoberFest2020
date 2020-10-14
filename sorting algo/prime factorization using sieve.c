#include<stdio.h>
#define MAXN 100001

int spf[MAXN];
void sieve()
{
    int i;
    for(i=2;i<MAXN;i++)
    {
        spf[i]=i;
    }
    for(i=4;i<MAXN;i=i+2)
        spf[i]=2;
    for(i=3;i*i<MAXN;i++)
    {
        if(spf[i]==i)
        {
            for(int p=i*i;p<MAXN;p=p+i)
            {
                if(spf[p]==p)
                    spf[p]=i;
            }
        }
    }
}
void getfactorization(int n)
{
    printf("The prime factorization of %d are:",n);
    while(n!=1)
    {
        printf("%d ",spf[n]);
        n=n/spf[n];
    }

}
void main()
{
    int n;
    scanf("%d",&n);
    sieve();
    getfactorization(n);
}
