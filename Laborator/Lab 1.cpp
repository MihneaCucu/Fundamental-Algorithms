#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

void bfs (int s, vector<vector<int>> &v, vector<int> distanta)
{
queue<int> coada;
coada.push(s);
while(!coada.empty())
{
    int current = coada.front();
    cout << coada.front() << '\n';
    coada.pop();

    for(int i=0; i<v[current].size(); i++)
    {
        if(distanta[v[current][i]] == -1)
        {
            distanta[v[current][i]] = distanta[current] + 1;
            coada.push(v[current][i]);
        }
    }

}

    for(int i=1; i<distanta.size(); i++)
    {
        fout << distanta[i] << " ";
    }

}

int main() {

    int n,m,s;
    fin >> n >> m >> s;
    vector<vector<int>> v;
    v.reserve(n);
    for(int i=0; i<m; i++)
    {
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
    }

    vector<int> distanta;
    distanta.reserve(n);

    for(int i=0; i<=n; i++)
    {
        distanta.push_back(-1);
    }
    distanta[s] = 0;
    bfs(s, v, distanta);

    fin.close();
    fout.close();
    return 0;
}

