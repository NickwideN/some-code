#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

typedef int vertex_t;
class Graph {
private:
    vector<vector<int>> vertexes;
public:
    Graph()
    {
        for (int i = 0; i < 1000000; ++i)
        {
            vertexes.push_back(vector<int>());
        }
    }
    void AddEdge(const vertex_t & vertex_1, const vertex_t & vertex_2) 
    {
        vertexes[vertex_1].push_back(vertex_2);
        vertexes[vertex_2].push_back(vertex_1);
    }
    void Vertex_to_std_stream(const vertex_t & vertex_in)
    {
        for (auto vertex_out : vertexes[vertex_in]) 
        {
            cout << vertex_out << ' ';
        }
        cout << '\n';
    }
};
int main()
{
    Graph graph;
    int vertex_cnt, command_cnt;
    cin >> vertex_cnt >> command_cnt;
    for (int i = 0; i < command_cnt; ++i)
    {
        int command;
        cin >> command;
        if (command == 1)
        {
            vertex_t vertex_1, vertex_2;
            cin >> vertex_1 >> vertex_2;
            graph.AddEdge(vertex_1, vertex_2);
        }
        else if (command == 2)
        {
            vertex_t vertex;
            cin >> vertex;
            graph.Vertex_to_std_stream(vertex);
        }
    }
    getchar();
    getchar();
    return 0;
}