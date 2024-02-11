#include<iostream>
#define INFINITY 9999
#define V 10
using namespace std;
void dijkstra(int G[V][V],int n,int source);
int main()
{
int G[V][V],i,j,n,u;
cout<<"Enter no. of nodes:";
cin>>n;
cout<<"\nEnter the node matrix:\n";
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cin>>G[i][j];
cout<<"\nEnter the source node:";
cin>>u;
dijkstra(G,n,u);
return 0;
}
void dijkstra(int G[V][V],int n,int source)
{
int cost[V][V],dist[V],pred[V];
int visi[V],c,mindist,nextnode,i,j;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(G[i][j]==0)
cost[i][j]=INFINITY;
else
cost[i][j]=G[i][j];
for(i=0;i<n;i++)
{
dist[i]=cost[source][i];
pred[i]=source;
visi[i]=0;
}
dist[source]=0;
visi[source]=1;
c=1;
while(c<n-1)
{
mindist=INFINITY;
for(i=0;i<n;i++)
if(dist[i]<mindist&&!visi[i])
{
mindist=dist[i];
nextnode=i;
}
visi[nextnode]=1;
for(i=0;i<n;i++)
if(!visi[i])
if(mindist+cost[nextnode][i]<dist[i])
{
dist[i]=mindist+cost[nextnode][i];
pred[i]=nextnode;
}
c++;
}
for(i=0;i<n;i++)
if(i!=source)
{
cout<<"\nCost of node"<<i<<"="<<dist[i];
cout<<"\nPath= "<<i;
j=i;
do
{
j=pred[j];
cout<<"<-"<<j;
}while(j!=source);
}
}