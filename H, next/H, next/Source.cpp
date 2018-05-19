#include<iostream>
#include<set>

class special_set
{
private:
    std::set<int> set_for_next;
    bool last_command_was_add;
    int last_request;
public:
    special_set() 
        : last_command_was_add(true) 
    {
    }
    void add(const int & val)
    {
        if (last_command_was_add)
        {
            set_for_next.insert(val);
        }
        else
        {
            set_for_next.insert((val + last_request) % 1000000000);
        }
        last_command_was_add = true;
    }
    int next(const int & val)
    {
        auto min_after_val_it = set_for_next.upper_bound(val - 1);
        int min_after_val = min_after_val_it == set_for_next.end() ? -1 : *min_after_val_it;
        last_command_was_add = false;
        return last_request = min_after_val;
    }
};

using namespace std;

int main()
{
    special_set sp_set;
    int command_cnt;
    cin >> command_cnt;
    for (int i = 0; i < command_cnt; ++i)
    {
        char command;
        int val;
        cin >> command >> val;
        if (command == '+')
        {
            sp_set.add(val);
        }
        else
        {
            cout << sp_set.next(val) << '\n';
        }
    }
    getchar();
    getchar();
    return 0;
}
// biaka, fu