#include <stdio.h>
#include <conio.h>

void SORTED_INSERT_ITEM(float LA[], int *N, float ITEM)
{
    int J;
    int i;
    int K;
    for(i=0;i<*N;i++)
    {
        if(LA[i]<ITEM && LA[i+1]>ITEM)
        {
            K=i+1;
        }
    } 
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
    float LA[20]={11.0,22.0,33.0,44.0,55.0,66.0,77.0,88.0,99.0,100.0};
    int K,LB,UB;
    LB=0;
    UB=9;
    SORTED_INSERT_ITEM(LA, &UB, 60.99);
    K=LB;
    while(K<=UB)
    {
        printf("%f\n",LA[K]);
        K=K+1;
    }
    return 0;
}