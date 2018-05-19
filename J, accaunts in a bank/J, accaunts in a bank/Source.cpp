#include <iostream>
#include <map>
#include<string>

using namespace std;

typedef int some_error;

int main()
{
    map<string, int> name_score;
    int command_cnt;
    cin >> command_cnt;
    for (int i = 0; i < command_cnt; ++i)
    {
        int command;
        string name;
        cin >> command >> name;
        if (command == 1)
        {
            int refill;
            cin >> refill;
            name_score[name] += refill;
        }
        else if (command == 2)
        {
            try
            {
                if (name_score.find(name) == name_score.end())
                {
                    throw some_error();
                }
                else
                {
                    cout << name_score[name] << '\n';
                }
            }
            catch (...)
            {
                cout << "ERROR" << '\n';
            }
        }
    }

    getchar();
    getchar();
    return 0;
}






