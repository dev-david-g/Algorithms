#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;

ifstream cin("dir.in");
ofstream cout("dir.out");
struct charul{
char st[260];
}  v[105];
char s[1605], sol[105][260];
char aux[200];
int main()
{
    int k=-1;
    int vf=0;
    int t=0;
    cin.getline(s, 1605);
    for(int i=0;s[i];)
    {
        if(isupper(s[i]))
        {
            while(isupper(s[i]) || isdigit(s[i]))
                aux[++k]=s[i++];
            aux[++k]='\0';
            strcpy(v[++vf].st, aux);
            if(s[i]=='(')
                strcat(v[vf].st, "\\");
            aux[0]='\0';
            k=-1;
        }
        if(islower(s[i]))
            {
                while(islower(s[i])||isdigit(s[i]))
                    aux[++k]=s[i++];
                aux[++k]='\0';
                ++t;
                for(int j=1;j<=vf;++j)
                        strcat(sol[t], v[j].st);
                strcat(sol[t], aux);
                aux[0]='\0';
                k=-1;

            }
        if(s[i]==')')
                    --vf, ++i;
        else ++i;
    }
    for(int i=1;i<t;++i)
        for(int j=i+1;j<=t;++j)
            if(strcmp(sol[i], sol[j])>0)
                swap(sol[i], sol[j]);
    cout<<t<<"\n";
    for(int j=1;j<=t;++j)
        cout<<sol[j]<<"\n";
    cin.close();
    cout.close();
    return 0;
}
