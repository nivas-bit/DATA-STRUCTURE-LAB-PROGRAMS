#include<stdio.h>
#include<conio.h>
int n,i,j,a[10][10],vis[10];
void dfs(int v)
{
   vis[v]=1;
   printf("%d",v);
   for(j=1;j<=n;j++)
   {
       if(a[v][j]==1 && a[j]==0)
       {
	   dfs(j);
	}
    }
}

void main()
{
   system("cls");
   printf("enter the number of vertices\n");
   scanf("%d",&n);
   printf("enter the adjacency matrix\n");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
     vis[i]=0;
    }
    printf("dfs traversal\n");
    for(i=1;i<=n;i++)
    {
      if(vis[i]==0)
       dfs(i);
    }
    getch();
}

