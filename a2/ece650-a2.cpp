#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int V(string line)
{
    // vertex: int type
    // vertice: string type
    int vertex;
    string vertice;
    for(int i = 2; i <= line.length(); i++)
        vertice[i - 2] = line[i];
    vertex = atoi(vertice.c_str());
    return vertex;
}


vector <vector <int>> E(string line)
{
    /*  Return is edge
        Type of edge is vector <vector <int>>
        One edge consists of two points
        edge[a][b]
        a in [0, 1]
        b in [0, numberOfEdges - 1]
        E.g. points: <1,6>,<2,8>,<3,5>,<6,5>
        edge[0][0] = 1; edge[1][0] = 6;
        edge[0][1] = 2; edge[1][1] = 8;
        edge[0][2] = 3; edge[1][2] = 5;
        edge[0][3] = 6; edge[1][3] = 5;
    */
    vector <vector <int>> edge;
    vector <int> first;
    vector <int> second;
    for(int i = 3; i <= line.length(); i++)
    {
        if(line[i] == '<')
        {
            char number[5] = {0};
            for(int j = 0; line[i + j + 1] != ','; j++)
                number[j] = line[i + j + 1];
            int number_int = atoi(number);
            first.push_back(number_int);
            continue;
        }

        if(line[i] == '>')
        {
            int j;
            char number[5] = {0};
            char number_inv[5] = {0};
            for(j = 0; line[i - j - 1] != ','; j++)
                number[j] = line[i - j - 1];
            for(int k = 0; k <= j; k++)
                number_inv[k] = number[j - k - 1];
            int number_int = atoi(number_inv);
            second.push_back(number_int);
            continue;
        }
    }
    edge.push_back(first);
    edge.push_back(second);
    return edge;
}


int s(int doS, string line)
{
    int doFind = 1;
    if(doS)
    {
        return 0;
    }
    else
    {
        doFind = 0;
        return doFind;
    }
}


int checkE(int vertex, vector <vector <int>> edge)
{
    int doS = 1;
    for(int i = 0; i <= 1; i++)
    {
        for(int j = 0; j <= edge[i].size() - 1; j++)
        {
            if(edge[i][j] > vertex)
            {
                cout << "Error: Point in E is out of the range of point in V!" << endl;
                doS = 0;
                return doS;
            }
            else
                return doS;
        }
    }
}


int main()
{
    while (!cin.eof())
    {
        string line;
        getline(cin, line);
        int vertex;
        vector <vector <int>> edge;
        int doS = 1;
        switch(line[0])
        {
            case 'V':
                vertex = V(line);
                continue;
            case 'E':
                edge = E(line);
                doS = checkE(vertex, edge);
                continue;
            case 's':
                s(doS, line);
                continue;
            default:
                cout << "Error: No such command!" << endl;
        }
    }
}

// V 15
// E {<2,6>,<2,8>,<2,5>,<6,5>,<5,8>,<6,10>,<10,8>}
// s 2 10