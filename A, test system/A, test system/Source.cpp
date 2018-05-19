#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;
typedef tuple<int, int, int> team_t;

struct compare 
{
    bool operator()(team_t l_team, team_t r_team) const \
    {
        return std::tie(get<0>(r_team), get<1>(l_team), get<2>(l_team)) < std::tie(get<0>(l_team), get<1>(r_team), get<2>(r_team));
    };
};

int main()
{
    vector<team_t> teams;
    int team_cnt;
    cin >> team_cnt;
    for (int team_number = 1; team_number <= team_cnt; ++team_number) 
    {
        int task_cnt;
        int penalty_time;
        cin >> task_cnt >> penalty_time;
        teams.push_back(team_t(task_cnt, penalty_time, team_number));
    }
    sort(teams.begin(), teams.end(), compare{});
    for(int i = 0; i < team_cnt; ++i)
    {
        cout << get<2>(teams[i]) << ' ';
    }
    getchar();
    getchar();
}