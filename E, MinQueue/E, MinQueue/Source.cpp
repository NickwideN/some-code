#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring> // strcmp

using namespace std;

template<typename value_type> class MinQueue
{
private:
    typedef value_type & reference;
    typedef int size_type;
    typedef value_type min_value_type;
    stack<pair<value_type, min_value_type>> stack_1, stack_2;
    void check()
    {
        if (stack_1.empty() && stack_2.empty())
        {
            throw MinQueueEmptyException();
        }
    }
    void trans()
    {
        while (!this->stack_1.empty())
        {
            value_type value = stack_1.top().first;
            this->stack_1.pop();
            int minima = this->stack_2.empty() ? value : std::min(value, this->stack_2.top().second);
            this->stack_2.push(make_pair(value, minima));
        }
    }
public:
    class MinQueueEmptyException{};

    void enqueue(const value_type& val)
    {
        min_value_type minima = this->stack_1.empty() ? val : std::min(val, this->stack_1.top().second);
        this->stack_1.push(make_pair(val, minima));
    }
    value_type dequeue()
    {
        this->check();
        if (this->stack_2.empty())
        {
            this->trans();
        }
        value_type value = this->stack_2.top().first;
        this->stack_2.pop();
        return value;
    }
    value_type min()
    {
        this->check();
        value_type current_minimum;
        if (this->stack_1.empty() || this->stack_2.empty())
        {
            current_minimum = this->stack_1.empty() ? this->stack_2.top().second : this->stack_1.top().second;
        }
        else
        {
            current_minimum = std::min(this->stack_1.top().second, this->stack_2.top().second);
        }
        return current_minimum;
    }
    reference front()
    {
        this->check();
        if (this->stack_2.empty())
        {
            this->trans();
        }
        return this->stack_2.top().first;
    }
    size_type size() noexcept
    {
        return this->stack_1.size() + this->stack_2.size();
    }
    void clear() noexcept
    {
        while (!this->stack_1.empty())
        {
            this->stack_1.pop();
        }
        while (!this->stack_2.empty())
        {
            this->stack_2.pop();
        }
    }
};

void execute_command(char command[11], MinQueue<int> & que)
{
    if (!strcmp(command, "enqueue"))
    {
        int value;
        cin >> value;
        que.enqueue(value);
        cout << "ok\n";
    }
    else if (!strcmp(command, "dequeue"))
    {
        cout << que.dequeue() << '\n';
    }
    else if (!strcmp(command, "front"))
    {
        cout << que.front() << '\n';
    }
    else if (!strcmp(command, "size"))
    {
        cout << que.size() << '\n';
    }
    else if (!strcmp(command, "clear"))
    {
        que.clear();
        cout << "ok\n";
    }
    else if (!strcmp(command, "min"))
    {
        cout << que.min() << '\n';
    }
}

int main()
{
    int command_cnt;
    cin >> command_cnt;
    MinQueue<int> que;
    for (int i = 0; i < command_cnt; ++i)
    {
        try
        {
            char command[11];
            cin >> command;
            execute_command(command, que);
        }
        catch (...)
        {
            cout << "error\n";
        }
    }
    getchar();
    getchar();
    return 0;
}