#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_LVL = 17;

int n, m, lvl, ln, l_count, answer=-1;

struct vertex
{
    long long val;
    int Left;
    int Right;
};

vertex tree[(1<<MAX_LVL)-1];
vector <int> ans, ds;

int lvl_count(int x)
{
    int level=1, ch=1;
    while(ch<x)
    {
     ch*=2;
     level++;
    }
    return level;
}

void ln_count(int b)
{
  lvl = lvl_count(b);
  ln = (1<<(lvl))-1;
}

int potom(int x, int lr)
{
  return (2*x + lr);
}

void iniz_t()
{
  for (int i = l_count-1; i >=1; --i)
  {
      int l_p = potom(i,0), r_p = potom(i,1);
      tree[i].val = tree[l_p].val + tree[r_p].val;
      tree[i].Left = tree[l_p].Left;
      tree[i].Right = tree[r_p].Right;
  }
}

int Search(int v, int sL, int sR)
{
    //cout << v << " " <<sL << " " <<sR << "\n";
    if( (tree[v].Left != sL) || (tree[v].Right != sR) )
    {
        if (tree[v].Tagged) push(v);
        int l_pot = potom(v,0);
        int M = tree[l_pot].Right;
        if(sR <= M) return Search(l_pot, sL, sR);
        else if(M < sL)return Search(l_pot + 1, sL, sR);
        else return Search(l_pot, sL, M) + Search(l_pot + 1, M + 1, sR);
    }
    else{
        //cout << tree[v].val << "\n\n";
        return tree[v].val;
    }
}

void in()
{
    ifstream cin("numbers.in");
    cin >> n >> m;
    ln_count(n);
    l_count = (ln+1)>>1;
    for (int i = l_count; i < l_count+n; ++i)
    {
        int a;
        cin >> a;
        tree[i].val = a;
        tree[i].Left =  tree[i].Right = i-l_count+1;
    }
    for (int i = l_count+n; i <= ln; ++i)
    {
        tree[i].Left = tree[i].Right = i-l_count+1;
    }
    iniz_t();
    for (int i = 0; i < m; i++)
    {
        int L;
        long long s;
        cin >> L >> s;
        Search(1, s, 1);
        cout << s << ":\n";
        if (tree[1].val < s) ans.push_back(-1);
        else
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " " << tree[ds[i]].Right-tree[ds[i]].Left+1 << " " << L << "\n";
                int v = ds[i];
                if (tree[v].Right-tree[v].Left+1 == L) answer = tree[v].Left;
            }
            cout << "\n";
            ans.push_back(answer);
            answer = -1;
            ds.clear();
        }
    }
}

void solution()
{

}

void out()
{
    ofstream cout("numbers.out");
    /*for (int i = 1; i <= ln; ++i)
    {
        cout << tree[i].val << " " << tree[i].Left << " " << tree[i].Right << "\n";
    }
    cout << "\n";*/
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
