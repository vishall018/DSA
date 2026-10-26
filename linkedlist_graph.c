#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
struct node *list[20];
int a[20][20],n,visited[20];
void insert(int u,int v)
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->vertex=v;
    newnode->next=NULL;
    if(list[u]==NULL)
    {
        list[u]=newnode;
    }
    else
    {
        temp=list[u];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void create()
{
    int i,j,e,u,v;
    for(i=0;i<20;i++)
    {
        list[i]=NULL;
    }
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    if(n<1||n>20)
    {
        printf("Invalid number of vertices\n");
        exit(0);
    }
    printf("Enter number of edges: ");
    scanf("%d",&e);
    printf("Enter edges (u v), vertices numbered 0 to %d:\n",n-1);
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        if(u>=0&&u<n&&v>=0&&v<n&&a[u][v]==0)
        {
            a[u][v]=1;
            insert(u,v);
        }
        else
        {
            printf("Invalid or duplicate edge\n");
        }
    }
    printf("\nAdjacency Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
	{
            printf("%d ",a[i][j]);
	}
        printf("\n");
    }
    printf("\nAdjacency List:\n");
    for(i=0;i<n;i++)
    {
        struct node *temp=list[i];
        printf("%d -> ",i);
        while(temp!=NULL)
        {
            printf("%d -> ",temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
void details()
{
    int i,j,in,out;
    struct node *temp;
    printf("\nVertex Set: {");
    for(i=0;i<n;i++)
    {
        printf("%d",i);
        if(i<n-1)
	{
            printf(", ");
	}
    }
    printf("}\n");
    printf("Edge Set: {");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j])
                printf("(%d,%d)",i,j);
        }
    }
    printf("}\n");
    printf("\nAdjacent Vertices and Degrees:\n");
    for(i=0;i<n;i++)
    {
        in=0;
        out=0;
        printf("Vertex %d: ",i);
        temp=list[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->vertex);
            temp=temp->next;
        }
        for(j=0;j<n;j++)
        {
            out+=a[i][j];
            in+=a[j][i];
        }
        printf("\nIndegree = %d",in);
        printf(", Outdegree = %d",out);
        printf(", Degree = %d\n",in+out);
    }
}
void bfs(int start)
{
    int q[20],front=0,rear=0;
    int i,v;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    q[rear++]=start;
    visited[start]=1;
    printf("BFS: ");
    while(front<rear)
    {
        v=q[front++];
        printf("%d ",v);
        for(i=0;i<n;i++)
        {
            if(a[v][i]&&!visited[i])
            {
                q[rear++]=i;
                visited[i]=1;
            }
        }
    }
    printf("\n");
}
void dfs(int v)
{
    int i;
    visited[v]=1;
    printf("%d ",v);
    for(i=0;i<n;i++)
    {
        if(a[v][i]&&!visited[i])
	{
            dfs(i);
	}
    }
}
void complete()
{
    int i,j,flag=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j&&!a[i][j])
	    {
                flag=0;
	    }
        }
    }
    if(flag)
    {
        printf("\nThe graph is complete.\n");
    }
    else
    {
        printf("\nThe graph is not complete.\n");
    }
}
int main()
{
    int start,i,choice;
    create();
    do
    {
        printf("\n1. Display Graph Details");
        printf("\n2. BFS Traversal");
        printf("\n3. DFS Traversal");
        printf("\n4. Check Complete Graph");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                details();
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d",&start);
                if(start>=0&&start<n)
		{
                    bfs(start);
		}
                else
		{
                    printf("Invalid vertex\n");
		}
                break;
            case 3:
                printf("Enter starting vertex: ");
                scanf("%d",&start);
                if(start>=0&&start<n)
                {
                    for(i=0;i<n;i++)
		    {
                        visited[i]=0;
		    }
                    printf("DFS: ");
                    dfs(start);
                    printf("\n");
                }
                else
		{
                    printf("Invalid vertex\n");
		}
                break;
            case 4:
                complete();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=5);
    for(i=0;i<n;i++)
    {
        struct node *temp=list[i];
        while(temp!=NULL)
        {
            struct node *next=temp->next;
            free(temp);
            temp=next;
        }
    }
    return 0;
}
