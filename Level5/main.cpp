#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <list>

using namespace std;

const char infile[] = "input.in";
const char outfile[] = "outputcorect.out";

ifstream fin(infile);
ofstream fout(outfile);

const int MAXN = 1010;
const int oo = 0x3f3f3f3f;

int N, M, numberOfPositions, maxCol;
vector <pair<int, int> > Colors[100005];
int paths;
int ans[100005];
int Used[MAXN][MAXN];

inline pair<int, int> getPositions(int x) {
    int nrX = (x / M) + (x % M != 0);
    return make_pair(nrX, x - (nrX - 1) * M);
}

const int dx[] = {-1, 0,  1, 0};
const int dy[] = {0,  1,  0,-1};

inline int getWhere(char x) {
    if(x == 'N')
        return 0;
    if(x == 'E')
        return 1;
    if(x == 'S')
        return 2;
    if(x == 'W')
        return 3;
}

inline bool inside(pair<int, int> a) {
    return 1 <= a.first && a.first <= N && 1 <= a.second && a.second <= M;
}

vector <pair<int, int> > moves;

inline void validatePath(int i) {
    int colour, stX, length;

    fin >> colour >> stX >> length;

    ans[colour] = 1;

    pair<int, int> stPoint = getPositions(stX);

    moves.clear();

    for(int j = 1 ; j <= length ; ++ j) {
        char ch;
        fin >> ch;

        moves.push_back(stPoint);
        int dir = getWhere(ch);

        stPoint.first += dx[dir];
        stPoint.second += dy[dir];
    }
    pair<int, int> _end;
    if(getPositions(stX) == Colors[colour][0])
        _end = Colors[colour][1];
    else _end = Colors[colour][0];

    moves.push_back(_end);

    for(vector <pair<int, int> > :: iterator it = moves.begin(), fin = moves.end() ; it != fin ; ++ it)
        Used[it->first][it->second] = 0;
}


int aux[MAXN][MAXN];

inline void Fill(int x, int y) {
    aux[x][y] = 1;
    for(int i = 0 ; i < 4 ; ++ i) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(-1 == aux[newx][newy] && inside(make_pair(newx, newy)))
            Fill(newx, newy);
    }
}

inline void DFs(pair<int, int> a, pair<int, int> b) {
    memset(aux, 0, sizeof(aux));
    for(int i = 1 ; i <= N ; ++ i)
        for(int j = 1 ; j <= M ; ++ j)
            aux[i][j] = Used[i][j];
    aux[a.first][a.second] = -1;
    aux[b.first][b.second] = -1;
    Fill(a.first, a.second);
}

int main() {
    int TEST;
    fin >> TEST;
    for(int test = 1 ; test <= TEST ; ++ test) {

        for(int i = 1 ; i <= maxCol ; ++ i)
            Colors[i].clear();

        memset(Used, -1, sizeof(Used));
        memset(ans, 0, sizeof(ans));

        maxCol = 0;

        fin >> N >> M >> numberOfPositions;
        for(int i = 1 ; i <= numberOfPositions ; ++ i) {
            int x, col;
            fin >> x >> col;
            Colors[col].push_back(getPositions(x));

            Used[getPositions(x).first][getPositions(x).second] = -2;

            maxCol = max(maxCol, col);
        }
        fin >> paths;
        for(int i = 1 ; i <= paths; ++ i)
            validatePath(i);
        for(int i = 1 ; i <= numberOfPositions / 2 ; ++ i) {
            pair<int, int> a = Colors[i][0];
            pair<int, int> b = Colors[i][1];
            DFs(a, b);
            if(ans[i] != 1) {
                if(aux[b.first][b.second] == 1)
                    ans[i] = 2;
                else ans[i] = 3;
            }
            fout << ans[i];
            if(!(i == numberOfPositions / 2 && test == TEST))
                fout << ' ';
        }
    }
    fin.close();
    fout.close();
    return 0;
}
