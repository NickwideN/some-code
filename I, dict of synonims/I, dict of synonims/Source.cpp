#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    map<string, string> dict;
    int line_cnt;
    cin >> line_cnt;
    for (int i = 0; i < line_cnt; ++i)
    {
        string word_1, word_2;
        cin >> word_1 >> word_2;
        dict[word_1] = word_2;
        dict[word_2] = word_1;
    }
    string word;
    cin >> word;
    cout << dict[word];
    
    getchar();
    getchar();
    return 0;
}