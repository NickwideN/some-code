#include<iostream>
#include<map>
#include<queue>
#include<functional>
using namespace std;

typedef int version_t;
typedef int value_t;
typedef pair<version_t, value_t> version_value_pair_t;

int main()
{
    map<value_t, version_t> cash_map;
    priority_queue<version_value_pair_t, vector<version_value_pair_t>, greater<version_value_pair_t>> cash_queue;
    int size_of_cash;
    version_t version_of_request = 0;
    cin >> size_of_cash;
    int val;
    while (cin >> val)
    {
        ++version_of_request;
        if (cash_map.find(val) == cash_map.end())
        {
            cout << 1 << ' ';
            if (cash_map.size() < size_of_cash)
            {
                cash_map[val] = version_of_request;
                cash_queue.push(make_pair(version_of_request, val));
            }
            else
            {
                while (cash_map[cash_queue.top().second] != cash_queue.top().first)
                {
                    cash_queue.pop();
                }
                auto value_to_remove = cash_queue.top();
                cash_map.erase(value_to_remove.second);
                cash_queue.pop();
                cash_map[val] = version_of_request;
                cash_queue.push(make_pair(version_of_request, val));
            }
        }
        else
        {
            cout << 0 << ' ';
            cash_queue.push(make_pair(version_of_request, val));
            cash_map[val] = version_of_request;
        }
    }

    getchar();
    getchar();
    return 0;
}