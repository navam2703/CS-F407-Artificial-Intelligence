#include <bits/stdc++.h>
using namespace std;

int heuristic(vector<vector<int>>& src,vector<vector<int>>& dest)
{
    int ans=0;
    
    for(int i=0;i<src.size();i++)
    {
        for(int j=0;j<src[0].size();j++)
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
    
    cout<<"Enter initial state of puzzle :"<<endl;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>src[i][j];
        }
    }
    
    cout<<"\nEnter goal state of puzzle :"<<endl;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>dest[i][j];
        }
    }
    
    int moves=0;
    int ans=heuristic(src,dest);
    cout<<"\nInitial value of heuristic : "<<ans<<endl;
    char s='Z';
    int x;
    
    while(ans!=0 && moves<30)
    {
        moves++;
        
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
            cout<<"\n("<<moves<<") move : C_ROTATE("<<x<<")"<<endl;
            
            cout<<"State of puzzle after above move :"<<endl;
            printMatrix(src);
        }
        
        else if(s=='A')
        {
            rotateAntiClockwise(src,x);
            cout<<"\n("<<moves<<") move : A_ROTATE("<<x<<")"<<endl;
            
            cout<<"State of puzzle after above move :"<<endl;
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
            
            cout<<"\n("<<moves<<") move : JUMP("<<x<<")"<<endl;
            
            cout<<"State of puzzle after above move :"<<endl;
            printMatrix(src);
        }
        
        else if(s=='Z')
            break;
        
        cout<<"Value of heuristic : "<<ans<<endl;
        s='Z';
    }
    
    if(moves<12 && ans!=0)
    {
        cout<<"\nFinal value of heuristic : "<<ans<<endl;
        cout<<"No further better state."<<endl;
        cout<<"Puzzle cannot be solved.";
    }
    
    else if(ans==0)
    {
        cout<<"\nFinal value of heuristic : "<<ans<<endl;
        cout<<"Puzzle solved!";
    }
        
    else if(ans!=0)
    {
        cout<<"\nFinal value of heuristic : "<<ans<<endl;
        cout<<"Puzzle cannot be solved in 12 moves.";
    }

    return 0;
}