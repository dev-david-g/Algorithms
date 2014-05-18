#include <iostream>
#include <bitset>

using namespace std ;

const int NMAX = 1000 ;

int N;
bitset <NMAX> C ;


int main()
{
    cin >> N ;
    for(int i = 2; i <= N; ++ i)
    if(C[i] == 0)
    {C[i]=i;
    cout << C[i] ;

    for(int j = i + i ; j <= N ; j = j + i)
        C[j] == 1 ;

    }


    return 0;
}
