#include <fstream>
using namespace std ;

string s ;
int cnt =1  ;

ifstream cin("compress.in") ;
ofstream cout("compress.out") ;

int main()
{
    cin >> s ;
    int lungime = s.size() ;
    for(int i = 0 ; i < lungime; ++ i)
        if(s[i] == s[i+1])
            ++ cnt;
        else
        {
            cout << s[i] << cnt ;
            cnt = 1 ;
        }

    cout << '\n' ;
         cin.close() ;
    cout.close() ;
    return 0 ;
}
