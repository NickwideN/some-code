#include<iostream>
#include<map>
#include<string>

using namespace std;

typedef string name_t;
typedef string good_t;
typedef long long good_cnt_t;

int main()
{
    map<name_t, map<good_t, good_cnt_t>> name_map_of_goods_map;
    name_t name;
    good_t good;
    good_cnt_t good_cnt;
    while (cin >> name)
    {
        cin >> good >> good_cnt;
        name_map_of_goods_map[name][good] += good_cnt;
    }
    for (auto name_map_of_goods : name_map_of_goods_map)
    {
        cout << name_map_of_goods.first << ":\n";
        for (auto map_of_goods : name_map_of_goods.second)
        {
            cout << map_of_goods.first << ' ' << map_of_goods.second << '\n';
        }
    }
    getchar();
    getchar();
    return 0;
}