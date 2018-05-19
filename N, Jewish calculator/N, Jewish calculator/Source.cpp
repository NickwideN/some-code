#include<iostream>
#include<queue>
#include<functional> // greater<int>
#include <iomanip>   // setprecision

using namespace std;

int main()
{ 
    priority_queue<int, vector<int>, greater<int>> value_queue;
    int values_cnt;
    cin >> values_cnt;
    for (int i = 0; i < values_cnt; ++i)
    {
        int value;
        cin >> value;
        value_queue.push(value);
    }
    double percentage = 0.05, cost = 0;
    while (value_queue.size() != 1)
    {
        int value_1 = value_queue.top();
        value_queue.pop();
        int value_2 = value_queue.top();
        value_queue.pop();
        int sum = value_1 + value_2;
        cost += sum * percentage;
        value_queue.push(sum);
    }
    cout << setprecision(2) << fixed << cost;


    getchar();
    getchar();
    return 0;
}