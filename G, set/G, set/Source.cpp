#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> word_set;
    char command;
    cin >> command;
    while (command != '#')
    {
        string word;
        cin >> word;
        switch (command)
        {
        case '+':
            word_set.insert(word);
            break;
        case '-':
            word_set.erase(word);
            break;
        case '?':
            auto it_word = word_set.find(word);
            cout << ((it_word == word_set.end()) ? "NO" : "YES") << '\n';
            break;
        }
        cin >> command;
    }
    getchar();
    getchar();
    return 0;
}