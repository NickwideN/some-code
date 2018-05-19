#include<iostream>
#include<set>
#include<cstring> // strcmp

using namespace std;


class Median_set
{
private:
    set<int> m_set;
    set<int>::iterator _mid;
public:
    void add(const int & val)
    {
        m_set.insert(val);
        if (m_set.size() == 1)
        {
            _mid = m_set.begin();
        }
        else
        {
            if (val < *_mid && m_set.size() % 2 == 0)
            {
                --_mid;
            }
            else if (*_mid < val && m_set.size() % 2 == 1)
            {
                ++_mid;
            }
        }

    }
    int min()
    {
        if (m_set.size() % 2 == 0)
        {
            ++_mid;
        }
        int val = *(m_set.begin());
        m_set.erase(m_set.begin());
        return val;
    }
    int max()
    {
        if (m_set.size() % 2 == 1)
        {
            --_mid;
        }
        int val = *(--m_set.end());
        m_set.erase(--m_set.end());
        return val;
    }
    int mid()
    {
        int val = *(_mid);
        set<int>::iterator old_mid = _mid;
        if (m_set.size() % 2 == 0)
        {
            ++_mid;
        }
        else if (m_set.size() % 2 == 1)
        {
            --_mid;
        }
        m_set.erase(old_mid);
        return val;
    }
};

void execute_command(char command[4], Median_set & m_set)
{
    if (!strcmp(command, "add"))
    {
        int value;
        cin >> value;
        m_set.add(value);
    }
    else if (!strcmp(command, "min"))
    {
        cout << m_set.min() << '\n';
    }
    else if (!strcmp(command, "max"))
    {
        cout << m_set.max() << '\n';
    }
    else if (!strcmp(command, "mid"))
    {
        cout << m_set.mid() << '\n';
    }
}

int main()
{
    int command_cnt;
    cin >> command_cnt;
    Median_set m_set;
    for (int i = 0; i < command_cnt; ++i)
    {
        char command[11];
        cin >> command;
        execute_command(command, m_set);
    }
    getchar();
    getchar();
    return 0;
}