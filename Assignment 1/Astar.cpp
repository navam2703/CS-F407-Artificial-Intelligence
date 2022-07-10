#include <bits/stdc++.h>
using namespace std;

struct cell 
{
	int parent;
	int f,g,h;
};

void tracePath(vector<cell>& cellDetails,int src,int dest)
{
	cout<<endl;
	cout<<"The path is : ";

    int i=dest;
	stack<int> Path;

	while(i!=src)
	{
		Path.push(i);
		i=cellDetails[i].parent;
	}

	Path.push(src);
	
	while(!Path.empty()) 
	{
		int p=Path.top();
		Path.pop();
		cout<<p<<" ";
	}

	return;
}

void aStarSearch(vector<vector<int>>& mat,int src,int dest,int V)
{
    vector<bool> closedList(V,false);
    vector<cell> cellDetails(V);
    
    for(int i=0;i<V;i++) 
    {
		cellDetails[i].f=INT_MAX;
		cellDetails[i].g=INT_MAX;
		cellDetails[i].h=INT_MAX;
		cellDetails[i].parent=-1;
	}
	
	cellDetails[src].f=0;
	cellDetails[src].g=0;
	cellDetails[src].h=0;
	cellDetails[src].parent=src;
	
	set<pair<int,int>> openList;
	openList.insert({0,src});
	
	while(!openList.empty()) 
	{
		pair<int,int> p=*openList.begin();
		openList.erase(openList.begin());
		int i=p.second;
		closedList[i]=true;
		cout<<i<<" ";

        for(int j=0;j<V;j++)
        {
    		int gNew,hNew,fNew;
    		
    		if(mat[i][j]!=0 && closedList[j]!=true)
    		{
        		if(j==dest) 
        		{
        			cellDetails[j].parent=i;
        			tracePath(cellDetails,src,dest);
        			return;
        		}
        		
        		else if(closedList[j]==false) 
        		{
        			gNew=cellDetails[i].g+1;
        			hNew=mat[i][j];
        			fNew=gNew+hNew;

        			if(cellDetails[j].f==INT_MAX || cellDetails[j].f>fNew) 
        			{
        				openList.insert({fNew,j});
        
        				cellDetails[j].f=fNew;
        				cellDetails[j].g=gNew;
        				cellDetails[j].h=hNew;
        				cellDetails[j].parent=i;
        			}
        		}
        	}
        }
	}
	
	return;
}

void addEdge(vector<vector<int>>& mat,int u,int v,int weight)
{
	mat[u][v]=weight;
	mat[v][u]=weight;
}

int main()
{
    int V = 14;
	vector<vector<int>> mat(V,vector<int> (V,0));
	addEdge(mat,0,1,120);
	addEdge(mat,0,7,77);
	addEdge(mat,0,9,142);
	addEdge(mat,1,2,113);
	addEdge(mat,2,3,72);
	addEdge(mat,3,4,77);
	addEdge(mat,4,5,122);
	addEdge(mat,5,6,126);
	addEdge(mat,6,11,140);
	addEdge(mat,6,12,148);
	addEdge(mat,7,8,71);
	addEdge(mat,8,9,122);
	addEdge(mat,9,10,111);
	addEdge(mat,9,12,82);
	addEdge(mat,10,13,213);
	addEdge(mat,11,12,99);
	addEdge(mat,11,13,105);
	
	aStarSearch(mat,0,13,V);

    return 0;
}