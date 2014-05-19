#include <fstream>

using namespace std ;

ifstream cin("produs.in") ;
ofstream cout("produs.out") ;

int A, B ;

inline bool functie(int a)
{
    while(a)
    {
      if(a%10 == 0)
        return true ;
      a = a /10 ;
    }
    return false ;

}

int main()
{
    cin >> A >> B ;
    int cnt = 0 ;

    for(int i  = A ; i <= B ; ++ i)
    if(functie(i) == true)
        ++ cnt ;

    cout << cnt << '\n' ;
    cin.close();
    cout.close();
    return 0;
}
