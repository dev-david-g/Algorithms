#include <fstream>
#include <cmath>

using namespace std;

struct numere
{
    float L ;
    float l ;
} x, y;
int a ;
int p ;
float c;



ifstream cin("input.in") ;
ofstream cout("output.out") ;

int main()
{
    cin >> x.L  >> x.l ;
    cin >> y.L >> y.l ;
    a =  x.L * x.l;
    cout << "1) " << a << '\n' ;
    p = (x.L + x.l) * 2 ;
    cout << "2) " << p << '\n' ;
    c = sqrt(pow(x.L, 2) + pow(x.l, 2)) ;
    cout << "3) " << c << '\n' ;
    if(x.L == x.l)
        cout << "Este patrat !" << '\n' ;
    else cout << "Nu este patrat!" << '\n' ;

    if(x.L * x.l == y.l * y.L)
        cout << "Au aceeasi arie!" << '\n' ;
    else cout << "Nu au aceeasi arie!" << '\n' ;

    if((x.L + x.l) * 2 == (y.L + y.l) * 2)
        cout << "Au aceeasi perimetru !" << '\n' ;
    else cout << "Nu aceeasi perimetru" << '\n' ;


    cin.close() ;
    cout.close() ;
    return 0;
}
