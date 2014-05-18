#include <fstream>
#include <stack>

using namespace std ;

const int NMAX = 1005 ;


ifstream cin("stiva.in") ;
ofstream cout("stiva.out") ;



int N ;

//stack <int> St ;
int Stack[NMAX] ;
int Vf, B ;

inline bool EmptyStiva(int Stack[], int Vf){
if(Vf == 0)
    return true ;
else return false ;
}

inline bool FullStiva(int Stack[], int Vf)
{
    if(Vf == N) return true ;
    else return false ;
}


int main()
{
    cin >> N ;
    for(int i = 1 ;i <= N ; ++ i)
    {
        int A ;
        cin >> A ;
        Stack[Vf] = A ;
        ++ Vf ;
    }

    if(EmptyStiva(Stack, Vf) == true) cout << "Stiva vida! " << '\n';
    else cout << "Stiva Nu este Vida!" << '\n' ;

    if(FullStiva(Stack, Vf) == true) cout << "Stiva Plina! " << '\n';
    else cout << "Stiva Necomplata" << '\n' ;

    cin.close();
    cout.close();
    return 0 ;
}
