#include<stdio.h>
#include<conio.h>
void DELETE(float LA[], int *N, int K)
{
    int J;
    int ITEM;
    ITEM=LA[K];
    int size=*N;
    for(J=K;J<*N;J++)
    {
        LA[J]=LA[J+1];
    }

    *N=*N-1;
}

int main()
{
    float LA[20]={11.0,22.0,33.0,44.0,55.0,66.0,77.0,88.0,99.0,100.0};
    int i,K,LB,UB,ELE,pos=-1;
    LB=0;   
    UB=9;

    ELE=66;
    for(i=0;i<UB;i++)
    {
        if(LA[i]==ELE)
        {
            pos=i;
        }
    }


    DELETE(LA, &UB, pos);
    K=LB;
    while(K<=UB)
    {
        printf("%f\n",LA[K]);
        K=K+1;
    }
return 0;
}