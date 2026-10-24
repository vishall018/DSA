
#include <stdio.h>
#define INF 9999

int main()
{
    int n,a[10][10]={0},v[10]={0};
    int i,j,k,x,y,w,min,u,sum=0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter number of edges: ");
    scanf("%d",&k);

    printf("Enter edges and weights:\n");
    for(i=0;i<k;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        a[x][y]=w;
        a[y][x]=w;
    }

    printf("Adjacency Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    v[0]=1;

    printf("Edges in Minimum Spanning Tree:\n");

    for(i=1;i<n;i++)
    {
        min=INF;
        u=-1;
        x=-1;

        for(j=0;j<n;j++)
        {
            if(v[j])
            {
                for(k=0;k<n;k++)
                {
                    if(!v[k] && a[j][k]!=0 && a[j][k]<min)
                    {
                        min=a[j][k];
                        u=j;
                        x=k;
                    }
                }
            }
        }

        if(x==-1)
        {
            printf("Graph is disconnected\n");
            return 0;
        }

        printf("%d - %d : %d\n",u,x,min);
        sum=sum+min;
        v[x]=1;
    }

    printf("Minimum cost = %d\n",sum);

    return 0;
}
