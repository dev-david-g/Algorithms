#include <fstream>
#include <vector>
#include <stack>
#include <cstring>


using namespace std ;

int N, K;
char s[10002] ;
stack <char> ST ;


ifstream cin ("alibaba.in") ;
ofstream cout ("alibaba.out") ;


int main()
{
    cin >> N ;
    cin >> K ;
    cin >> s ;
    K = N - K ;
    for(int i = 0 ; i < N ; ++ i)
    {
         while(!ST.empty() && (ST.size()+N-i-1) >=   K && ST.top()< s[i])
            ST.pop() ;
        ST.push(s[i]) ;
    }
    vector <char> maradek ;
    while(!ST.empty())
    {
        maradek.push_back(ST.top()) ;
        ST.pop();
    }

    for(int i  = maradek.size()  ; i > 0 ; -- i)
        cout << s[i] ;

    cin.close();
    cout.close() ;
    return 0 ;
}
