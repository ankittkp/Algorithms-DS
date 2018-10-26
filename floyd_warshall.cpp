#include<bits/stdc++.h>
using namespace std;
#define v 4
#define INF 99999
void printsolution(int weight[][v])
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if (weight[i][j] == INF) 
                cout<<setw(5)<<"INF";
            else
                cout<<setw(5)<<weight[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
void floydwarshall(int graph[][v])
{
	int weight[v][v],path[v][v];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			weight[i][j]=graph[i][j];
			if (i == j)
				path[i][j] = 0;
			else if (cost[i][u] != INT_MAX)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			for(int k=0;k<v;k++)
			{
				if(weight[i][k]+weight[k][j]<weight[i][j])
				{
					weight[i][j]=weight[i][k]+weight[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
	printsolution(weight);
}
int main()
{
	int graph[v][v]=
	{
		{0,5,INF,10},
		{INF,0,3,INF},
		{INF,INF,0,1},
		{INF,INF,INF,0}
	};
	floydwarshall(graph);

}