#include <bits/stdc++.h>
using namespace std;

int heuristic(vector<vector<int>>& src,vector<vector<int>>& dest)
{
    int ans=0;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(src[i][j]!=dest[i][j])
                ans--;
        }
    }
    
    return ans;
}

void rotateClockwise(vector<vector<int>>& mat,int row)
{
    int n=mat[0].size(),x=mat[row][n-1];
    
    for(int i=n-1;i>0;i--)
        mat[row][i]=mat[row][i-1];
        
    mat[row][0]=x;
}

void rotateAntiClockwise(vector<vector<int>>& mat,int row)
{
    int n=mat[0].size(),x=mat[row][0];
    
    for(int i=0;i<n-1;i++)
        mat[row][i]=mat[row][i+1];
        
    mat[row][n-1]=x;
}

void jump(vector<vector<int>>& mat,int row,int column)
{
    int temp=mat[row][column];
    mat[row][column]=mat[row+1][column];
    mat[row+1][column]=temp;
}

void printMatrix(vector<vector<int>>& mat)
{
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            cout<<mat[i][j]<<" ";
        }
            
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> src(3,vector<int> (4,0));
    vector<vector<int>> dest(3,vector<int> (4,0));
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>src[i][j];
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>dest[i][j];
        }
    }
    
    int moves=0;
    int ans=heuristic(src,dest);
    cout<<"Initial value of heuristic : "<<ans<<endl;
    
    while(ans!=0 && moves<30)
    {
        char s;
        int x;
        
        for(int i=0;i<src.size()-1;i++)
        {
            for(int j=0;j<src[0].size();j++)
            {
                vector<vector<int>> temp=src;
                jump(temp,i,j);
                
                int a=heuristic(temp,dest);
                
                if(a>ans)
                {
                    ans=a;
                    s='J';
                    x=src[i][j];
                }
            }
        }
        
        for(int i=0;i<src.size();i++)
        {
            vector<vector<int>> temp=src;
            rotateClockwise(temp,i);
            
            int a=heuristic(temp,dest);
            
            if(a>ans)
            {
                ans=a;
                s='C';
                x=i;
            }
        }
        
        for(int i=0;i<src.size();i++)
        {
            vector<vector<int>> temp=src;
            rotateAntiClockwise(temp,i);
            
            int a=heuristic(temp,dest);
            
            if(a>ans)
            {
                ans=a;
                s='A';
                x=i;
            }
        }
        
        if(s=='C')
        {
            rotateClockwise(src,x);
            cout<<s<<" "<<x<<endl;
            
            printMatrix(src);
        }
        
        else if(s=='A')
        {
            rotateAntiClockwise(src,x);
            cout<<s<<" "<<x<<endl;
            
            printMatrix(src);
        }
        
        else if(s=='J')
        {
            int a,b;
            
            for(int i=0;i<src.size()-1;i++)
            {
                for(int j=0;j<src[0].size();j++)
                {
                    if(src[i][j]==x)
                    {
                        a=i;
                        b=j;
                        break;
                    }
                }
            }
            
            jump(src,a,b);
            
            cout<<s<<" "<<a<<" "<<b<<endl;
            
            printMatrix(src);
        }
        
        else if(s=='Z')
            break;
        
        cout<<"Value of heuristic : "<<ans<<endl;
        moves++;
        s='Z';
    }
    
    if(moves<30 && ans!=0)
    {
        cout<<"No further better state.";
    }
    
    else if(ans==0)
    {
        cout<<"Final value of heuristic : "<<ans<<endl;
        cout<<"Puzzle solved!";
    }
        
    else if(ans!=0)
    {
        cout<<"Final value of heuristic : "<<ans<<endl;
        cout<<"Puzzle cannot be solved in 30 moves.";
    }

    return 0;
}