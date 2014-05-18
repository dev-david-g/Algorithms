#include <fstream>
#include <bitset>

using namespace std ;

ifstream cin("ciur.in") ;
ofstream cout("ciur.out") ;

bitset <2000005> ciur ;
int N, cnt  ;

int main()
{
    int i, j ;
    cin >> N ;
    for(i = 2 ; i <= N ; ++ i)

          if(ciur[i] == 0)
    {
        ++ cnt ;
        for(j = i + i ; j <= N ; j = j + i)
            ciur[j] = 1 ;
    }







    cout << cnt ;

    cin.close() ;
    cout.close() ;
    return 0;
}
