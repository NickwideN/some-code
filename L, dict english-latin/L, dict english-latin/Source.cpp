#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

typedef string word_t;

int main()
{
    map<word_t, set<word_t>> latin_english_dict;
    string english_word;
    while (cin >> english_word)
    {
        char ignore_char;
        cin >> ignore_char;
        while (cin.peek() != '\n')
        {
            string latin_word;
            cin >> latin_word;
            if (latin_word[latin_word.size() - 1] == ',')
            {
                latin_word = latin_word.substr(0, latin_word.size() - 1);
            }
            latin_english_dict[latin_word].insert(english_word);
        }
    }
    cout << latin_english_dict.size() << '\n';
    for (auto pair : latin_english_dict)
    {
        cout << pair.first << " - ";
        for (auto english_word : pair.second)
        {
            cout << english_word;
            if (english_word != *(--pair.second.end()))
            {
                cout << ", ";
            }
        }
        cout << '\n';
    }

    getchar();
    getchar();
    return 0;
}