/** 
 * Written by zachkingcade: 04/06/2020 4:30pm
 * Problem: uva 495 - Graph Connectivity
 * 
 * Notes:
 * I'll be using a vector to represent the graphs componets
 * where every componet is also a vector of the nodes it contains
 * There are 2 main cases that need to be accounted for here:
 * --------------------------------------------------------
 * 1- Nodes are not in the same vector => combine vectors
 * 2- Nodes are in the same vector     => Do Nothing
 * 
 * Note: that the first letter denotes that we have nodes A - that Letter
 */

//-----PreCompiler Directives-----
#include <iostream>
#include <string>
#include <vector>

//-----Prototypes-----
int findNode(std::vector <std::vector <char>>, char);
std::string printDoubleCharVector(std::vector <std::vector <char>>);

//----------Main----------
int main(){
    //Varibles
    int numSets;
    std::string holder;

    //read in the number of data sets
    std::cin >> numSets;

    //take out first blank space and prime loop
    std::getline(std::cin, holder);
    std::getline(std::cin, holder);

    for (int i = 0; i < numSets; i++){
        //create gragh and char to hold the nodes
        char node1;
        char node2;
        int index1;
        int index2;
        //process first node (single node)
        //Note: determines what nodes there are, it is from A to the first Node
        std::getline(std::cin, holder);
        //add all the nodes here we can declare our vector and add our nodes
        std::vector <std::vector <char>>graph(0);
        for (int i = 0; i <= holder[0] - 'A'; i++){
            char temp = 'A' + i;
            std::vector <char>firstNodeVector(0);
            firstNodeVector.push_back(temp);
            graph.push_back(firstNodeVector);
        }
        //prime loop and process using 5 states from starting notes at the top of the page
        std::getline(std::cin, holder);
        while (holder != ""){
            node1 = holder[0];
            node2 = holder[1];
            index1 = findNode(graph,node1);
            index2 = findNode(graph,node2);
            // case 4: Both Nodes found,     Nodes are not in the same vector => combine vectors
            if(index1 > -1 && index2 > -1 && index1 != index2){
                for(int i = 0; i < graph[index1].size(); i++){
                    graph[index2].push_back(graph[index1][i]);
                }
                graph.erase(graph.begin() + index1);
            }
            // case 5: Both Nodes Found,     Nodes are in the same vector     => Do Nothing and
            //move onto process the next node
            std::getline(std::cin, holder);
        }
        //at this point the end of this data set has been found and we just need to calculate the number of components
        std::cout << graph.size() << "\n";
        //format new lines correctly
        if (i + 1 < numSets){
            std::cout << std::endl;
        }
    }
}//end of main

//---------------Functions--------------

/** 
 * returns the vector index of the first instance of a passed in char 
 * found in a double vector
 */
int findNode(std::vector <std::vector <char>> graph, char lookingFor){
    for (int i = 0; i < graph.size(); i++){
        for (int j = 0; j < graph[i].size(); j++){
            if(lookingFor == graph[i][j]){
                return i;
            }
        }
    }
    return -1;
}

std::string printDoubleCharVector(std::vector <std::vector <char>> graph){
    std::string result = "------------------------------------------------------------\n";
    for (int i = 0; i < graph.size(); i++){
        result += "Vector " + std::to_string(i);
        result += ',' + std::to_string(graph[i].size());
        result += ":\t"; 
        for(int j = 0; j < graph[i].size(); j++){
            result += graph[i][j] + "  ";
        }
        result += '\n';
    }
    return result;
}