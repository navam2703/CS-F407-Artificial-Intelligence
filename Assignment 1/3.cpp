#include <bits/stdc++.h>
using namespace std;

struct node 
{
	int parent;
	int f,g,h;
};

bool sortBySecondIfFirstEqual(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first==b.first)
        return a.second>b.second;
        
    else 
        return a.first<b.first;
}

void tracePath(vector<node>& nodeDetails,int src,int dest)
{
	cout<<endl;
	cout<<"The path is : ";

    int i=dest;
	stack<int> route;

	while(i!=src)
	{
		route.push(i);
		i=nodeDetails[i].parent;
	}

	route.push(src);
	
	while(!route.empty()) 
	{
		int p=route.top();
		route.pop();
		cout<<p<<" ";
	}

	return;
}

void printList(vector<pair<int,int>>& list)
{
    int i=0;
    
    for(i=0;i<list.size()-1;i++)
    {
        cout<<list[i].second<<"("<<list[i].first<<"),";
    }
    
    cout<<list[i].second<<"("<<list[i].first<<")"<<endl;
}

void aStarSearch(vector<vector<int>>& gVal,vector<int>& hVal,int src,int dest,int V)
{
    vector<bool> closedList(V,false);
    vector<node> nodeDetails(V);
    
    for(int i=0;i<V;i++) 
    {
		nodeDetails[i].f=INT_MAX;
		nodeDetails[i].g=INT_MAX;
		nodeDetails[i].h=INT_MAX;
		nodeDetails[i].parent=-1;
	}
	
	nodeDetails[src].f=0;
	nodeDetails[src].g=0;
	nodeDetails[src].h=0;
	nodeDetails[src].parent=src;
	
	vector<pair<int,int>> openList;
	openList.push_back({hVal[0],src});
	
	cout<<"Open list"<<endl;
	
	while(!openList.empty()) 
	{
	    sort(openList.begin(),openList.end(),sortBySecondIfFirstEqual);
	    printList(openList);
	    
		pair<int,int> p=*openList.begin();
		openList.erase(openList.begin());
		int i=p.second;
		int cost=p.first;
		closedList[i]=true;
		
		if(i==dest)
		{
		    tracePath(nodeDetails,src,dest);
		    cout<<"\nCost of this path is : "<<cost;
            return;
		}

        for(int j=0;j<V;j++)
        {
    		int gNew,hNew,fNew;
    		
    		if(gVal[i][j]!=0 && closedList[j]!=true)
    		{
        		if(closedList[j]==false) 
        		{
        			gNew=nodeDetails[i].g+gVal[i][j];
        			hNew=hVal[j];
        			fNew=gNew+hNew;

        			if(nodeDetails[j].f==INT_MAX || nodeDetails[j].f>fNew) 
        			{
        				openList.push_back({fNew,j});
        
        				nodeDetails[j].f=fNew;
        				nodeDetails[j].g=gNew;
        				nodeDetails[j].h=hNew;
        				nodeDetails[j].parent=i;
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

void addVal(vector<int>& h,int x,int dist)
{
    h[x]=dist;
}

int main()
{
    int V = 14;
    
	vector<vector<int>> gVal(V,vector<int> (V,0));
	addEdge(gVal,0,1,120);
	addEdge(gVal,0,7,77);
	addEdge(gVal,0,9,142);
	addEdge(gVal,1,2,113);
	addEdge(gVal,2,3,72);
	addEdge(gVal,3,4,77);
	addEdge(gVal,4,5,122);
	addEdge(gVal,5,6,126);
	addEdge(gVal,6,11,140);
	addEdge(gVal,6,12,148);
	addEdge(gVal,7,8,71);
	addEdge(gVal,8,9,122);
	addEdge(gVal,9,10,111);
	addEdge(gVal,9,12,82);
	addEdge(gVal,10,13,213);
	addEdge(gVal,11,12,99);
	addEdge(gVal,11,13,105);
	
	vector<int> hVal(V,0);
	addVal(hVal,0,550);
	addVal(hVal,1,550);
	addVal(hVal,2,450);
	addVal(hVal,3,510);
	addVal(hVal,4,325);
	addVal(hVal,5,415);
	addVal(hVal,6,235);
	addVal(hVal,7,455);
	addVal(hVal,8,400);
	addVal(hVal,9,325);
	addVal(hVal,10,240);
	addVal(hVal,11,170);
	addVal(hVal,12,205);
	addVal(hVal,13,0);
	
	aStarSearch(gVal,hVal,0,13,V);

    return 0;
}