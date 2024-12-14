#include<iostream>
#include<fstream>
#include<vector>

int main()
{
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int numOfEdges(0);
    int numOfNodes(0);

    in>>numOfNodes>>numOfEdges;

    std::vector<std::vector<int>> matrix(numOfNodes,std::vector<int>(numOfNodes,0));

    for(int i(0);i<numOfEdges;++i)
    {
        int nodeBegin(0);
        int nodeEnd(0);
        in>>nodeBegin>>nodeEnd;   
        matrix[nodeBegin-1][nodeEnd-1]=1;
        matrix[nodeEnd-1][nodeBegin-1]=1;
    }

    for(int i(0);i<matrix.size();++i)    
    {
        for(int j(0);j<matrix.size();++j)
        {
            out<<matrix[i][j]<<" ";
        }
        out<<'\n';
    }

    in.close();
    out.close();

}
