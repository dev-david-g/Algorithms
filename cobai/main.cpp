#include <fstream>
#include <map>
#include <queue>
#include <algorithm>
#include <iomanip>


using namespace std ;

const short NMAX = 55 ;


const short dx[] = {-1,0, 1, 0};
const short dy[] = {0 ,1, 0,-1};

ifstream cin("cobai.in") ;
ofstream cout("cobai.out") ;

void Read() ;
void Solve() ;
void Completeaza() ;
void OUTMAP() ;
void OUT() ;

struct cel
{
    int linie ;
    int coloana ;
};

struct trU
{
    cel QQ ;
    int trI ;

};

//queue <pair < int, int > > Q ;
short N, M ;
short H[NMAX][NMAX] ;
short trs[1005] ;
int cnt = 0;
double nrPB = 0 ;
cel st ;
int liber = 0 ;
inline void Read()
{
    cin >> N >> M ;

    Completeaza() ;




    for(int i = 1 ; i <= N; ++i)
        for(int j = 1 ; j <= M ; ++ j)
        {
            char c ;
            cin >> c ;


            if(c == '*')
            {
                st=(cel)
                {
                    i,j
                };
                H[i][j] = -1 ;

            }
            else if(c == '+')
                H[i][j] = -1;
            else if(c == '.')
                ++ liber ;
        }

    //int cnt = 0;

    cin.ignore() ;

    while(cin.peek() != '\n')
    {
        char c ;
        cin >> c ;
        if(c == 'N')
            trs[++ cnt] = 0 ;
        else if(c == 'E')
            trs[++ cnt] = 1 ;
        else if(c == 'S')
            trs[++ cnt] = 2 ;
        else if(c == 'V')
            trs[++ cnt] = 3 ;

    }
}


inline void Solve()
{
    if(cnt == 0)
    {
        //cout.precision(3) ;
        cout << fixed << setprecision(3) ;
        cout << 0.00 ;
        return  ;
    }


    queue <trU> Q ;
    Q.push((trU)
    {
        st, 0
    }) ;
    for(; !Q.empty() ; Q.pop())
    {

        trU cr = Q.front() ;
        int cC = cr.QQ.coloana;
        int lL = cr.QQ.linie ;
        lL = lL   + dx[trs[cr.trI]] ;
        cC = cC  + dy[trs[cr.trI]] ;
        if(cr.trI == cnt - 1)
        {
            while(H[lL][cC] != -1)
            {
                if(H[lL][cC] != -2)
                {
                    ++ nrPB ;
                    H[lL][cC] = -2 ;
                }
                lL = lL   + dx[trs[cr.trI]] ;
                cC = cC    + dy[trs[cr.trI]] ;
            }




        }


        else
        {
            while(H[lL][cC] != -1)
            {
                if(cr.trI + 1 > H[lL][cC])
                {
                    Q.push((trU)
                    {
                        (cel) {lL, cC}, cr.trI + 1
                    }) ;
                    H[lL][cC] = cr.trI + 1 ;

                }
                lL = lL  + dx[trs[cr.trI]] ;
                cC = cC  + dy[trs[cr.trI]] ;
            }
        }
    }
}


inline void OUT()
{
    cout << fixed << setprecision(2) ;
    cout << nrPB / liber * 100 << '\n' ;
    OUTMAP() ;
}


inline void Completeaza()
{
    for(int i = 0 ; i <= N + 1; ++ i)
        H[i][0] = H[i][M + 1] = -1 ;
    for(int i = 0 ; i <= M + 1 ; ++ i)
        H[0][i] = H[N + 1][i] = -1 ;
}


inline void OUTMAP()
{
    for(int i = 0 ; i <= N + 1 ; ++ i)
    {
        for(int j = 0 ; j <= M + 1 ; ++ j)
        {
            cout.width(5) ;
            cout << H[i][j] << ' ' ;
        }
        cout << '\n' ;
    }
}

int main()
{
    Read() ;
    Solve() ;
    OUT() ;


    cin.close() ;
    cout.close() ;
    return 0 ;
}
