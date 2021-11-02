//a1744546
#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <cstdio>
using namespace std;
int n;
int ct=0;
int f[501];
struct edge{
    int u,v;
    int d;
}e[125001];

bool compare(edge a,edge b)
{
    return a.d<b.d;
}

int find(int x)
{
  if(x!=f[x])
    x=find(f[x]);
  return x;
}

int kruskal()
{
    int sum=0;
    for(int i=1;i<=n;i++)
        f[i]=i;
    sort(e,e+ct,compare);
    for(int i=0;i<ct;i++){
        int f1=find(e[i].u);
        int f2=find(e[i].v);
        if(f1!=f2)
        {
            f[f1]=f2;
            sum+= e[i].d;
        }
    }
    return sum;
}
int number_of_city(string line)
{
    int rank = 0;
    for (int i = 0; i < (int)line.length(); i++)
    {
        if (line[i] != ',' )
        {
            rank++;
        }else
        {
            return rank;
        }
    }
    return 0;
}
int* input(int array[], int n)
{
    for (int i = 0; i<(int)n; i++)
    {
        if (array[i]==48 || array[i]==49)// ASSCII '1' is 49 '0'is 48
        {
            array[i] -= 48;
        }else if (array[i]>=65 && array[i]<=90)// ASSCII 'A' ~ 'Z' is 65 ~ 90
        {
            array[i] -= 65;
        }else if (array[i]>=97 && array[i]<=122)// ASSCII 'a' ~ 'z' is 97 ~ 122
        {
            array[i] -= 71;//97-71=26
        }
    
    }
    return array;
}
int main()
{
    string line;
    getline(cin, line);
    n = number_of_city(line);

    line.erase( remove ( line.begin(), line.end(),' '), line.end());
    line.erase( remove ( line.begin(), line.end(),','), line.end());

    int array[line.length()];
    for (int i=0; i<(int)line.length() ;i++ )
    {
        array[i] = line[i];
    }
    int leng = (int)line.length();
    int* arr = input(array,leng);

    int order = 0;

    int N[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {

            N[i][j] = arr[order];
            order++;
        }
    }
    
    int B[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            B[i][j]=arr[order];
            order++;
        }
    }

    int D[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            D[i][j]=arr[order];
            order++;
        }
    }

    int C[n][n];//store current cost
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (N[i][j]==1)
            {
                C[i][j] = -D[i][j];
            }else
            {
                C[i][j] = B[i][j];
            }
        }
    }
    
    int init_cost=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if (N[i][j]==1)
            {
                init_cost += -D[i][j];
            }
            
        }
    }

    ct=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++,ct++)
        {
            e[ct].u=i;
            e[ct].v=j;
            e[ct].d=C[i][j];
        }
    }
    cout<<kruskal()-init_cost<<endl;
}
