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
			else if (weight[i][j] != INT_MAX)
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
	cout<<"Floyd Warshall Algorithm output : "<<endl;
	int graph[v][v]=
	{
		{INF,-1,-2,INF},
		{4,INF,2,4},
		{5,1,INF,2},
		{3,-1,1,INF}
	};
	floydwarshall(graph);

}
