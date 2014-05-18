#include<fstream>
#include<map>
#include<vector>

using namespace std;

ifstream cin ("bacterii.in");
ofstream cout ("bacterii.out");
const int M = 100003;
unsigned long long K,N;
int T,MA;
int v[200004];
map < int ,int > MAP;
struct Dash
{
    int MSA;
    vector <pair <int , int> > Dash[M];

    inline int Cautare(const int x)
    {
        MSA = x% M;
        for(vector < pair <int, int> > ::iterator it = Dash[M].begin(); it!=Dash[M].end(); ++it)
            if((*it).first==x)
                return (*it).second;
        return 0;
    }
    inline void Insert(int x,const int i)
    {
        Dash[M].push_back(make_pair(x,i));
    }

};
Dash Hulu;
///iteram valoare pana la 100 .

/// schimbam aici asa.
/// k = 97, 100 ;

int main()
{

    cin>>T;

    /*
     {

        cin >> N >> K >> M ;
        N = N % M ;
        //int sum = (2 * K) % M ;
        for(unsigned long long i = 1 ; i <= K ; ++ i)
           N = N * (N - 3) + N + 2 ;
         cout << N % M<< '\n' ;

        -- T ;
    } */
    for (int  i=1 ; i<=T; ++ i)
    {
        MAP.clear();
        cin>>N>>K>>MA;
        int fir = 0;
        int c = 0;
        while(true)
        {
            v[fir] = N;
            ++fir;
            N = ( 1LL * N * ( N - 3 ) + N + 2 ) % MA;
            c=Hulu.Cautare(N);
            if(c)
                break;
            else
                Hulu.Insert(N,fir);
        }
        int per = fir - c;
        if(K<=c)
            cout <<v[K]<<'\n';
        else
        {
            int i = ( K - c ) % per;
            cout << v[c + i ] << '\n';
        }
    }


    cin.close() ;
    cout.close() ;
    return 0;
}
