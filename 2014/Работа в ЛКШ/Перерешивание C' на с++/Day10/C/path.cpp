#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <conio.h>

using namespace std;

const int MAX_vertex_count=100;;

typedef pair <int, int> pa;  

int vertex_count, start, finish, length, ch, i1, i2, m, n, t, vertex, pred;
int matrix[MAX_vertex_count+2][MAX_vertex_count+2], used[MAX_vertex_count+2][MAX_vertex_count+2];
pa path[MAX_vertex_count+2];
int dx[8] = {0, 1, -1, 0, 1, -1, 1, -1}, 
    dy[8] = {1, 0,  0,-1, 1, -1, -1, 1};
    
pair <int, int> pi;
queue < pa > q;   

void bfs()
{
  while(!q.empty())
  {
    vertex = (q.front()).first;
    pred = (q.front()).second;
    if (vertex == finish) {
                           while (!q.empty())
                           {
                           vertex = (q.front()).first;
                           pred = (q.front()).second;
                           pi.first = vertex;
                           pi.second = pred;
                           path[vertex]=pi;
                           length++;
                           }
                          }
    
  }
}

void in()
{
    ifstream cin ("path.in");
     cin >>vertex_count;  
     for (int i=0;i<vertex_count;i++)
     {
          for (int j=0;j<vertex_count; j++)
          {
              cin>>matrix[i][j];
          }
     }  
     cin >>start >>finish;
}

void solution()
{
    start--; finish--; 
    pi.first = start;
    pi.second = -1;
    q.push(pi);
    bfs();
}

void out()
{
     ofstream cout ("path.out");
    /*cout <<vertex_count <<"\n";
     for (int i=0; i<vertex_count;i++)
     {
          for (int j=0; j<vertex_count; j++)
          {
              cout <<matrix[i][j] <<" ";
          }
          cout <<"\n";
     }
    cout << start <<" " <<finish <<"\n";*/
     if (ch==1) {cout <<"-1\n";}
     else  { 
           cout <<length <<"\n";
           for (int i=0; i<length; i++)
            {
             cout <<path[i];  
            }
           } 

}

int main()
{
    in();
    solution();
    out();
return 0;
}
