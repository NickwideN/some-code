#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() 
{
    int value_cnt;
    cin >> value_cnt;
    vector<int> values;
    for (int i = 0; i < value_cnt; ++i) 
    {
        int value;
        cin >> value;
        values.push_back(value);
    }
    int value;
    cin >> value;
    cout << count(values.begin(), values.end(), value);
    getchar();
    getchar();
}