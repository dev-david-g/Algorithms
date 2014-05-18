#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#define MOD 1000003

char input[] = "div4.in" ;
char output[] = "div4.out" ;
const int INF = 0x3f3f3f3f ;

using namespace std ;

ifstream cin(input) ;
ofstream cout(output) ;
string S ;
int K ;

int cnt ;
int sol ;

int main()
{
    cin >> S ;
    cin >> K ;
    int N = K + 2 ;
    cnt = 0 ;
   for( int i = S.size() - K + 3 ; i <= S.size() - 1 ; ++ i)
      {for(int j = i + 1 ; j < S.size() ; ++ j)
          if(S[i] % 2 != 0 )
          {
              if(S[j] == 2 || S[j] == 6)
             ++ cnt ;
              //cout << cnt << ' ' ;
          }
          else if(S[i] % 2 == 0)
          {
              if(S[j] == 4 || S[j] == 8)
                ++ cnt ;
          }

   sol = sol + K-(S.size()-i+1);
      }
      int rez ;
          rez = sol * cnt ; ;
       cout << rez % MOD<< '\n' ;
    cin.close();
    cout.close();
    return 0;
}
