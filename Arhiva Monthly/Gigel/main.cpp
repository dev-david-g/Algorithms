#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <limits.h>

char input[] = "gsr.in" ;
char output[] = "gsr.out" ;
//const int NMAX = 005 ;
//const int INF = 0x3f3f3f3f ;



using namespace std ;

ifstream cin(input) ;
ofstream cout(output) ;




/*inline int max(int a, int b)
{
    if(a > b ) return a ;
    else return b ;
}
inline int min(int a, int b)
{
    if(a < b ) return a ;
    else return b ;
}
*/
char S ;
int B, K ;
int rest = 0 ;

int conversie(char c)
{
    if(c >= '0' && c <= '9')

        return c - '0' ;
    return 10 + c - 'A' ;

}

int main()
{

    cin >> B >> K ;
    while(cin >> S)
        rest = (1LL * rest * B + conversie(S)) % K ;

    //cout << INT_MAX << '\n' ;


    cout << rest << '\n' ;
    cin.close();
    cout.close();
    return 0;
}
