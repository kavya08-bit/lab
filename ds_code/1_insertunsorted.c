#include <stdio.h>
#include <conio.h>

void INSERT_ITEM(float LA[], int *N, int K, float ITEM)
{
    int J;
    J=*N ;
    while(J>=K)
    {
        LA[J+1]=LA[J];
        J=J-1;
    }
    LA[K]=ITEM;
    *N=*N+1;
}

int main()
{
    float LA[20]={11.0,45.0,33.0,44.0,35.0,66.0,90.0,88.0,99.0,100.0};
    int K,LB,UB;
    LB=0;
    UB=9;
    INSERT_ITEM(LA, &UB, 6, 999.9);
    K=LB;
    while(K<=UB)
    {
        printf("%f\n",LA[K]);
        K=K+1;
    }
    return 0;
}