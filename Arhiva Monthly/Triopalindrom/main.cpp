#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

const char input[] = "triopalindrom.in" ;
const char output[] = "triopalindrom.out" ;
const int NMAX = 005 ;
const int INF = 0x3f3f3f3f ;

using namespace std ;

ifstream cin(input) ;
ofstream cout(output) ;

char s[5005];
int N;
int cnt, znt = 0;

inline int max(int a, int b) {if(a > b ) return a ; else return b ; }
inline int min(int a, int b) {if(a < b ) return a ; else return b ; }


int main()
{
    cin >> s ;
    //int N = s.size() - 1 ;
    int N = strlen(s) ;
    int K ;
     //K = N / 3 ;
     for(int i = 0 ; i < N ; ++ i)
       { K = 3 ;
           int j = 0 ;
           while(K) {
                ++ j ;
                if(s[i -1 + j] == s[i + K])
                {
                    ++ cnt ;
                }


                -- K ;
                if(cnt % 3 == 0) ++ znt ;


       }
       }



cout << znt << '\n' ;

    cin.close();
    cout.close();
    return 0;
}
