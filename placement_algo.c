#include <stdio.h>

int p[6]={12,20,8,52,60,71};
int f[7]={20,15,18,35,80,70,55};

void firstFit()
{
    int i,j,a[7]={0},waste=0;
    printf("\nFirst Fit:\n");
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            if(!a[j] && f[j]>=p[i])
            {
                a[j]=1;
                printf("Page %d -> Frame %d\n",p[i],f[j]);
                waste+=f[j]-p[i];
                break;
            }
        }
        if(j==7)
            printf("Page %d -> Not Allocated\n",p[i]);
    }
    printf("Unused memory = %d\n",waste);
}

void bestFit()
{
    int i,j,k,a[7]={0},waste=0;
    printf("\nBest Fit:\n");
    for(i=0;i<6;i++)
    {
        k=-1;
        for(j=0;j<7;j++)
            if(!a[j] && f[j]>=p[i] && (k==-1 || f[j]<f[k]))
                k=j;
        if(k!=-1)
        {
            a[k]=1;
            printf("Page %d -> Frame %d\n",p[i],f[k]);
            waste+=f[k]-p[i];
        }
        else
            printf("Page %d -> Not Allocated\n",p[i]);
    }
    printf("Unused memory = %d\n",waste);
}

void worstFit()
{
    int i,j,k,a[7]={0},waste=0;
    printf("\nWorst Fit:\n");
    for(i=0;i<6;i++)
    {
        k=-1;
        for(j=0;j<7;j++)
            if(!a[j] && f[j]>=p[i] && (k==-1 || f[j]>f[k]))
                k=j;
        if(k!=-1)
        {
            a[k]=1;
            printf("Page %d -> Frame %d\n",p[i],f[k]);
            waste+=f[k]-p[i];
        }
        else
            printf("Page %d -> Not Allocated\n",p[i]);
    }
    printf("Unused memory = %d\n",waste);
}

void nextFit()
{
    int i,j,k,a[7]={0},waste=0,last=0,count;
    printf("\nNext Fit:\n");
    for(i=0;i<6;i++)
    {
        k=-1;
        count=0;
        j=last;
        while(count<7)
        {
            if(!a[j] && f[j]>=p[i])
            {
                k=j;
                break;
            }
            j=(j+1)%7;
            count++;
        }
        if(k!=-1)
        {
            a[k]=1;
            printf("Page %d -> Frame %d\n",p[i],f[k]);
            waste+=f[k]-p[i];
            last=(k+1)%7;
        }
        else
            printf("Page %d -> Not Allocated\n",p[i]);
    }
    printf("Unused memory = %d\n",waste);
}

int main()
{
    firstFit();
    bestFit();
    worstFit();
    nextFit();
    return 0;
}