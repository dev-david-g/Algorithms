#include <fstream>
#include <cmath>

using namespace std ;


ifstream cin("veverite.in") ;
ofstream cout("veverite.out") ;

int A, B;
int sum;
 int a;

int main()
{
    cin >> A >> B ;
       sum = A + B ;
         a = sum/3 ;
        int rest;
         rest = sum % 3 ;
         cout << a << ' ' << rest<< '\n' ;

    cin.close();
    cout.close();
    return 0 ;
}
