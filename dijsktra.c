
#include <stdio.h>
#define INF 9999

int main()
{
    int n,a[10][10]={0},d[10],v[10];
    int i,j,k,x,y,w,s,min,u;

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

    printf("Enter source vertex: ");
    scanf("%d",&s);

    for(i=0;i<n;i++)
    {
        d[i]=a[s][i];
        v[i]=0;
    }

    d[s]=0;
    v[s]=1;

    for(i=1;i<n;i++)
    {
        min=INF;
        u=-1;

        for(j=0;j<n;j++)
        {
            if(!v[j] && d[j]<min)
            {
                min=d[j];
                u=j;
            }
        }

        if(u==-1)
            break;

        v[u]=1;

        for(j=0;j<n;j++)
        {
            if(!v[j] && a[u][j]!=0 && d[u]+a[u][j]<d[j])
                d[j]=d[u]+a[u][j];
        }
    }

    printf("Shortest distances:\n");
    for(i=0;i<n;i++)
        printf("%d to %d = %d\n",s,i,d[i]);

    return 0;
}
