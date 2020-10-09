#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 9;
	
	int mat[9][9] = { { 100,4,100,100,100,100,100,8,100}, 
                      { 4,100,8,100,100,100,100,11,100}, 
                      {100,8,100,7,100,4,100,100,2}, 
                      {100,100,7,100,9,14,100,100,100}, 
                      {100,100,100,9,100,100,100,100,100}, 
                      {100,100,4,14,10,100,2,100,100}, 
                      {100,100,100,100,100,2,100,1,6}, 
                      {8,11,100,100,100,100,1,100,7}, 
                      {100,100,2,100,100,100,6,7,100}};
	
	int src = 0;
	int count = 1;
	
	int path[n];
	for(int i=0;i<n;i++)
		path[i] = mat[src][i];
	
	int visited[n] = {0};
	visited[src] = 1;
	
	while(count<n)
	{
		int minNode;
		int minVal = 100;
		
		for(int i=0;i<n;i++)
			if(visited[i] == 0 && path[i]<minVal)
			{
				minVal = path[i];
				minNode = i;
			}
		
		visited[minNode] = 1;
		
		for(int i=0;i<n;i++)
			if(visited[i] == 0)
				path[i] = min(path[i],minVal+mat[minNode][i]);
					
		count++;
	}
	
	path[src] = 0;
	for(int i=0;i<n;i++)
		cout<<src<<" -> "<<path[i]<<endl;
	
	return(0);
}