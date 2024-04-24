#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Team_data
{
    int team, pnum, time;
    int pwrong[21];
};

struct Runs_data
{
    int team_num, p, ti, r;
};

int C, N;

int cmp(const void *a, const void *b)
{
    const Team_data *t1 = (const Team_data *)a;
    const Team_data *t2 = (const Team_data *)b;
    if (t1->pnum != t2->pnum)
    {
        return t2->pnum - t1->pnum;
    }
    else if (t1->time != t2->time)
    {
        return t1->time - t2->time;
    }
    else
    {
        return t1->team - t2->team;
    }
}

int cmp2(const void *a, const void *b)
{
    const Runs_data *r1 = (const Runs_data *)a;
    const Runs_data *r2 = (const Runs_data *)b;
    return r1->ti - r2->ti;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> C >> N;

    vector<Team_data> teams(C + 1);
    for (int i = 1; i <= C; ++i)
    {
        teams[i].team = i;
    }
    vector<Runs_data> runs(N);
    for (int i = 0; i < N; ++i)
    {
        fin >> runs[i].team_num >> runs[i].p >> runs[i].ti >> runs[i].r;
    }
    qsort(&runs[0], N, sizeof(Runs_data), cmp2);
    for (int i = 0; i < N; ++i)
    {
        int team_num = runs[i].team_num, p = runs[i].p, ti = runs[i].ti, r = runs[i].r;
        if (r == 1)
        {
            if (teams[team_num].pwrong[p] != -1)
            {
                teams[team_num].time += (ti + teams[team_num].pwrong[p] * 20 * 60);
                teams[team_num].pnum++;
            }
            teams[team_num].pwrong[p] = -1;
        }
        else
        {
            if (teams[team_num].pwrong[p] != -1)
            {
                teams[team_num].pwrong[p]++;
            }
        }
    }
    qsort(&teams[1], C, sizeof(Team_data), cmp);
    for (int i = 1; i <= C; ++i)
    {
        fout << (i == 1 ? "" : " ") << teams[i].team;
    }
    return 0;
}