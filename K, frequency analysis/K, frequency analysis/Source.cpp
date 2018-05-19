#include<iostream>
#include<set>
#include<string>
#include<map>

using namespace std;

typedef string word_t;
typedef int frequency_t;

class comparator {
public:
    bool operator()(const pair<frequency_t, word_t> & pair_1, const pair<frequency_t, word_t> & pair_2)
    {
        return  tie(pair_2.first, pair_1.second) < tie(pair_1.first, pair_2.second);
    }
};
int main()
{
    map<word_t, frequency_t> word_map;
    word_t word;
    while (cin >> word)
    {
        ++word_map[word];
    }
    set<pair<frequency_t, word_t>, comparator> frequency_word_set;
    for (auto pair : word_map)
    {
        frequency_word_set.insert(make_pair(pair.second, pair.first));
    }
    for (auto pair : frequency_word_set)
    {
        cout << pair.second << '\n';
    }

    getchar();
    getchar();
    return 0;
}