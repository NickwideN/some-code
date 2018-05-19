#include<iostream>
#include<string>
#include<list>
#include<vector>

enum class default_special_symbols
{
    Leftward = '<',
    Rightward = '>',
    Delete = '#',
    Backspace = '@',
    Home = '^',
    End = '$'
};

template<class special_symbols = default_special_symbols, class Container = std::list<char>, class iterator = std::list<char>::iterator>
class line_editor
{
private:
    //typedef std::list<char> Container;
    //typedef std::list<char>::iterator iterator;
    //typedef default_special_symbols special_symbols;
    Container line;
    iterator cursor;
public:
    line_editor() :
        line(), cursor(line.begin()) {
    }

    void execute_command(const char & symbol)
    {
        switch (symbol)
        {
        case (char)special_symbols::Leftward:
            if (this->cursor != this->line.begin())
            {
                --this->cursor;
            }
            break;
        case (char)special_symbols::Rightward:
            if (this->cursor != this->line.end())
            {
                ++this->cursor;
            }
            break;
        case (char)special_symbols::Delete:
            if (this->cursor != this->line.end())
            {
                auto char_for_romove = this->cursor;
                this->execute_command((char)special_symbols::Rightward);
                this->line.erase(char_for_romove);
            }
            break;
        case (char)special_symbols::Backspace:
            if (this->cursor != this->line.begin())
            {
                this->execute_command((char)special_symbols::Leftward);
                auto char_for_romove = this->cursor;
                this->execute_command((char)special_symbols::Rightward);
                this->line.erase(char_for_romove);
            }
            break;
        case (char)special_symbols::Home:
            this->cursor = this->line.begin();
            break;
        case (char)special_symbols::End:
            this->cursor = this->line.end();
            break;
        default:
            this->line.insert(this->cursor, symbol);
            break;
        }
    }

    void execute_command(const std::string & line)
    {
        for (auto symbol_it = line.begin(); symbol_it != line.end(); ++symbol_it)
        {
            this->execute_command(*symbol_it);
        }
    }

    std::string get_line() const
    {
        std::string line_string;
        for (auto ch : this->line)
        {
            line_string.push_back(ch);
        }
        return line_string;
    }

    char get_cursor() const
    {
        return this->cursor == this->line.end() ? '0' : *this->cursor;
    }
};

using namespace std;

int main()
{
    line_editor<> header;
    string commands;
    getline(cin, commands);
    header.execute_command(commands);
    cout << header.get_line(); //<< "\nCursor before: " << header.get_cursor() << '\n';
    getchar();
    getchar();
    return 0;
}

