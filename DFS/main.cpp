#include <fstream>
#include <vector>
#include <bitset>
#define pb push_back
#define s size
#define MAXN 100005

using namespace std;

bitset <MAXN> viz ;
int N, M,  cnt;
vector <int> A[MAXN];




ifstream cin ("dfs.in");
ofstream cout ("dfs.out");

void citire ()
{

    cin >> N >> M;
    for( int  i = 1; i <= M; ++ i)
    {
        int x, y;
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);

    }
}

void DFS ( int nod)
{
    viz[nod] = 1;
    for ( int  i = 0; i < A[nod].s(); ++ i)
        if(!viz[A[nod][i]])
        DFS(A[nod][i]);

}

int main()
{
    citire();
    for ( int i = 1; i <= N; ++ i)
        if(!viz[i])
        {
            ++ cnt ;
            DFS(i) ; }
            cout << cnt <<'\n';
    cin.close();
    cout.close();

    return 0;
}
