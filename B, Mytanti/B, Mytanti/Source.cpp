#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
typedef int color_t, color_cnt_t;
using namespace std;

int main ()
{
    vector<color_t> color_vector;
    int mutant_cnt;
    cin >> mutant_cnt;
    for (int i = 0; i < mutant_cnt; ++i) 
    {
        color_t color;
        cin >> color;
        color_vector.push_back(color);
    }
    vector<color_cnt_t> color_cnt_vector;
    int query_cnt;
    cin >> query_cnt;
    for (int i = 0; i < query_cnt; ++i)
    {
        int query;
        cin >> query;
        cout << upper_bound(color_vector.begin(), color_vector.end(), query) - 
            lower_bound(color_vector.begin(), color_vector.end(), query) << '\n';
    }
    getchar();
    getchar();
    return 0;
}