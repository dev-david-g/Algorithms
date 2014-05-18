#include<fstream>
#include<queue>
#include<string.h>

using namespace std;

const int NMAX=180;
int N, M, d[NMAX][NMAX], a[NMAX][NMAX];
int xst, yst, xfn, yfn;
queue<pair<int, int> > Q;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};


ifstream cin("alee.in");
ofstream cout("alee.out");

void afisare()
{
    for(int i = 1; i <= N; ++ i)
        {for(int j = 1; j<= N; ++ j)

            cout << d[i][j]<<" ";
            cout<<"\n";
        }
}

void lee()
{

    Q.push(make_pair(xst, yst));
    d[xst][yst] = 1;
    while( !Q.empty() )
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; ++ i)
        {

            int xnou = x + dx[i];
            int ynou = y + dy[i];
            if(xnou >=1 && xnou <= N &&  ynou >= 1 && ynou <= N && d[xnou][ynou] != -2)
                if(d[xnou][ynou] > d[x][y] + 1 || d[xnou][ynou] == 0)
                 {
                     d[xnou][ynou] = d[x][y] + 1;
                     Q.push(make_pair(xnou, ynou));
                 }
            }
    }
cout<<d[xfn][yfn];
}

int main()
{
    cin>>N>>M;
    for(int i = 1 ; i <= M ; ++ i)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = d[x][y] = -2;
    }

    cin >> xst >> yst >> xfn >> yfn;
    lee();
   // afisare();
    cin.close();
    cout.close();
    return 0;
}
