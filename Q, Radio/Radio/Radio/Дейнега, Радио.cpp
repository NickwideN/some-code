#include<iostream>
#include<set>
#include<string>
#include<map>
#include<iostream>

typedef int ip_t;
typedef int time_int;
typedef int track_id_t;
typedef int score_t;

inline void std_scanf_ip(ip_t & ip) 
{
    ip_t ip1, ip2, ip3, ip4;
    scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);
    ip = (ip1 << 24) | (ip2 << 16) | (ip3 << 8) | (ip4);
}

using namespace std;
int main() 
{
    int command_cnt = 100001;
    map<ip_t, time_int> time_map;
    map<track_id_t, score_t> track_score;
    set<pair<score_t, track_id_t>> score_track;
    for (int i = 1; i < command_cnt; ++i) 
    {
        track_score.insert(pair<track_id_t, score_t>(i, 0));
        score_track.insert(pair<score_t, track_id_t>(0, i));
    }
    string command;
    for (cin >> command; command != "EXIT"; cin >> command) 
    {
        if (command == "VOTE") 
        {
            ip_t curr_ip;
            track_id_t curr_track_id;
            score_t curr_score;
            time_int curr_time;
            std_scanf_ip(curr_ip);
            cin >> curr_track_id >> curr_score >> curr_time;
            ++curr_time; // need, because if curr_ip doesn't exist in time_map, then time_map[curr_ip] == 0 and curr_time can be 0
            if (curr_time - time_map[curr_ip] >= 600 || time_map[curr_ip] == 0)
            {
                time_map[curr_ip] = curr_time;
                auto track_score_it = track_score.find(curr_track_id);
                if (track_score_it == track_score.end())
                {
                    track_score.insert(pair<track_id_t, score_t>(curr_track_id, -curr_score));
                    score_track.insert(pair<score_t, track_id_t>(-curr_score, curr_track_id));
                }
                else
                {
                    auto score_track_it = score_track.find(pair<score_t, track_id_t>(track_score_it->second, track_score_it->first));
                    score_t curr_track_score = track_score_it->second;
                    track_score.erase(track_score_it);
                    score_track.erase(score_track_it);
                    track_score.insert(pair<track_id_t, score_t>(curr_track_id, curr_track_score - curr_score));
                    score_track.insert(pair<score_t, track_id_t>(curr_track_score - curr_score, curr_track_id));
                }
            }
            auto track_score_it = track_score.find(curr_track_id);
            if (track_score_it == track_score.end())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << -track_score_it->second << '\n';
            }
        }
        else if (command == "GET")
        {
            auto score_track_it = score_track.begin();
            track_id_t track_id = score_track_it->second;
            score_t score = score_track_it->first;
            auto track_score_it = track_score.find(track_id);
            cout << track_id << ' ' << -score << '\n';
            track_score.erase(track_score_it);
            score_track.erase(score_track_it);
            track_score.insert(pair<track_id_t, score_t>(track_id, 1));
            score_track.insert(pair<score_t, track_id_t>(1, track_id));
        }
    }
    cout << "OK";
    getchar();
    getchar();
}