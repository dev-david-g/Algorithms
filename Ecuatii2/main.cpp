#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>


using namespace std;

ifstream cin ("ecuatii2.in") ;
ofstream cout ("ecuatii2.out") ;

const int NMAX = 259 ;

int N;
char s1[NMAX], s2[NMAX];
long nr1, nr2, nrx1, nrx2 ;


 void rezolva(char *s, long &nr, long &nrx)
{char *p, cpy[NMAX];
 long v;
 int semn=1, lungime;
strcpy(cpy,s);
p=strtok(cpy,"+-");
nr=0; nrx=0;
while (p)
      {

      lungime=strlen(p);
      if (p[0]=='x') nrx+=semn;
      else
      if (p[lungime-1]=='x')
         {p[lungime-1]=NULL;
          v=atol(p);
          nrx=nrx+semn*v;
         }
         else
         {v=atol(p);
         nr=nr+semn*v;}
      if (s[p+lungime-cpy]=='+')
         semn=1;
         else
         semn=-1;
      p=strtok(NULL, "+-");
      }
}

int main()
{    int i ;
    char *p ;
    cin >> N ;
   cin.getline(s1, 20) ;
     for( i = 0 ; i < N ; ++ i)
         {
        cin.getline(s1, 259) ;
        p = strchr(s1, '=') ;
        strcpy(s2, p+1) ;
        *p = NULL ;


        rezolva(s1, nr1, nrx1) ;
        rezolva(s2, nr2, nrx2) ;
        if(nrx1 == nrx2)

            if(nr1 == nr2)
                cout << "infinit\n" ;
            else cout << "imposibil\n" ;
        else cout<<fixed<<setprecision(4)<<(double)(nr2 - nr1)/(nrx1 - nrx2)<<"\n";


    }

    cin.close();
    cout.close();
    return 0;
}
