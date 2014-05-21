#include <iostream>

using namespace std;

void Citire() ;
void Quick_Sort(int, int) ;
void OUT() ;

const int NMAX = 1005 ;
int V[NMAX] ;
int N ;


inline void Citire()
{
	 cin >> N ;
    for(int i = 1 ; i <= N ; ++ i)
         cin >> V[i] ;
}

void  Quick_Sort(int left, int right)
{
int i = left ;
int j = right ;
int aux, pivot ;
pivot = V[(i + j) / 2] ;

do {
while( i  < right &&  V[i] <  pivot)
 ++ i;
 while(j > left && V[j] > pivot)
  -- j ;

  if(i <= j)
    { aux = V[i] ;
     V[i] = V[j] ;
     V[j] = aux ;
     ++ i ;
     -- j ;

}
}while(i <= j);

if(left < j) Quick_Sort(left, j) ;
if(i < right) Quick_Sort(i, right) ;

}

inline void OUT()
{
	for(int i = 1 ; i <= N ; ++ i)
	cout << V[i] << ' ' ;
}

int main() {

    Citire() ;

         Quick_Sort(1, N) ;

      OUT() ;

	return 0;
}
