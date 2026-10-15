#include <stdio.h>

int a[20][20], adj[20][20], count[20];
int visited[20], n;

void createList() {
    int i, j;
    for(i=0;i<n;i++) {
        count[i]=0;
        for(j=0;j<n;j++)
            if(a[i][j])
                adj[i][count[i]++]=j;
    }
}

void printMatrix() {
    int i,j;
    printf("\nAdjacency Matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

void printList() {
    int i,j;
    printf("\nAdjacency List:\n");
    for(i=0;i<n;i++) {
        printf("%d -> ",i);
        for(j=0;j<count[i];j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}

void degreeCount() {
    int i,j,in,out;
    printf("\nVertex\tDegree\tIndegree\tOutdegree\n");
    for(i=0;i<n;i++) {
        in=out=0;
        for(j=0;j<n;j++) {
            out+=a[i][j];
            in+=a[j][i];
        }
        printf("%d\t%d\t%d\t\t%d\n",i,in+out,in,out);
    }
}

void printEdges() {
    int i,j;
    printf("\nVertex Set: { ");
    for(i=0;i<n;i++)
        printf("%d ",i);
    printf("}\nEdge Set: { ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j])
                printf("(%d,%d) ",i,j);
    printf("}\n");
}

void bfs(int start) {
    int q[20],front=0,rear=0,i,v;
    for(i=0;i<n;i++)
        visited[i]=0;

    printf("BFS: ");
    q[rear++]=start;
    visited[start]=1;

    while(front<rear) {
        v=q[front++];
        printf("%d ",v);
        for(i=0;i<count[v];i++) {
            int u=adj[v][i];
            if(!visited[u]) {
                visited[u]=1;
                q[rear++]=u;
            }
        }
    }

    for(i=0;i<n;i++)
        if(!visited[i]) {
            visited[i]=1;
            q[rear++]=i;
            while(front<rear) {
                v=q[front++];
                printf("%d ",v);
                for(int j=0;j<count[v];j++) {
                    int u=adj[v][j];
                    if(!visited[u]) {
                        visited[u]=1;
                        q[rear++]=u;
                    }
                }
            }
        }
    printf("\n");
}

void dfs(int v) {
    int i;
    visited[v]=1;
    printf("%d ",v);
    for(i=0;i<count[v];i++)
        if(!visited[adj[v][i]])
            dfs(adj[v][i]);
}

void completeGraph() {
    int i,j,flag=1;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i!=j && a[i][j]==0)
                flag=0;

    if(flag)
        printf("\nThe graph is complete.\n");
    else
        printf("\nThe graph is not complete.\n");
}

int main() {
    int i,u,v,m,start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter number of edges: ");
    scanf("%d",&m);

    printf("Enter edges (u v):\n");
    for(i=0;i<m;i++) {
        scanf("%d%d",&u,&v);
        a[u][v]=1;
        a[v][u]=1;
    }

    createList();
    printMatrix();
    printList();
    degreeCount();
    printEdges();

    printf("\nEnter starting vertex: ");
    scanf("%d",&start);

    bfs(start);

    for(i=0;i<n;i++)
        visited[i]=0;

    printf("DFS: ");
    dfs(start);
    for(i=0;i<n;i++)
        if(!visited[i])
            dfs(i);
    printf("\n");

    completeGraph();

    return 0;
}