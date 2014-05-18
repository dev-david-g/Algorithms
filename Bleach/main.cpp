#include<fstream>
#include <vector>
#include <algorithm>

using namespace std ;

ifstream cin("bleach.in") ;
ofstream cout("bleach.out") ;

int N, P, K , A, B;
vector <int> Q;

int main()
{

    cin >> N >> K ;

    for(int i = 1 ; i <= N ; ++ i)
    {  int act ;
        cin >> act ;
        Q.push_back(act) ;
    }

    sort(Q.begin(), Q.end()) ;


       A = Q[0] ;
       B = A + Q[1] ;

   for(int i  = 2 ;  i < Q.size() ; ++ i )
   {
       if(B >= Q[i])
       B  = B + Q[i];


   else A = Q[i] - B;
   }


   cout << A << '\n';
    cin.close () ;
    cout.close ();
    return 0 ;
}
