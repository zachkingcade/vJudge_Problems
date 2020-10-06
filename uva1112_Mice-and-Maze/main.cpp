/** 
 * Written by zachkingcade: 05/26/2020 4:04am
 * Problem: uva 1112 - Mice and Maze
 * 
 * Notes:
 * I will be using a 2d array to represent the relationship between
 * nodes or cells in this case. After which I will run a simple version
 * of dijkstras shortest path that returns the shorest path from a single
 * cell to another cell.
 */

//----------Precompiler Directives----------
#include<iostream>
#include<vector>
#include<algorithm>

#include<thread>
#include<chrono>

//-----Prototypes-----
int shortestPathTo(std::vector <std::vector <int>>gragh, int start, int end);

//----------Main----------
int main (){
    //varibles
    int dataSets;
    int numCells;
    int exitCell;
    int timer;
    int numConnections;

    //read in the number of data sets
    std::cin >> dataSets;
    
    for(int i = 0; i < dataSets; i++){
        int miceNum = 0;
        //read in number of cells, which is the exit cell, how many moves the timer has
        //and the number of connections between cells (mono-directional)
        std::cin >> numCells;
        std::cin >> exitCell;
        std::cin >> timer;
        std::cin >> numConnections;
        //create 2d array and fill it with connections
        std::vector <std::vector <int>>gragh(numCells+1);
        //set all values to 0
        for (int i = 0; i < numCells+1; i++){
            for (int j = 0; j < numCells+1; j++){
                gragh[i].push_back(-1);
            }
        }
        //add connections
        for (int i = 0; i < numConnections; i++){
            int A;  //starting node
            int B;  //ending node
            int T;  //time to tranverse connection
            //read in varibles values
            std::cin >> A;
            std::cin >> B;
            std::cin >> T;
            //draw the connection in the 2d array
            gragh[A][B] = T;
        }
        //check if each mouse can make it in time
        //std::cout << "timer: " << timer << std::endl;
        for (int i = 1; i < numCells+1; i++){
            if(shortestPathTo(gragh,i,exitCell) <= timer && shortestPathTo(gragh,i,exitCell) != -1){
                miceNum++;
            }
        }
        //print the results
        std::cout << miceNum << "\n";
        if(i < dataSets - 1){
            std::cout << "\n";
        }
    }
}

int shortestPathTo(std::vector <std::vector <int>>gragh, int start, int end){
    //create a vector to check which have been visted
    std::vector <bool>visted(gragh.size());
    //create a vector to store the results of the shortest path
    std::vector <int>results(gragh.size());
    //queue to track nodes to vist
    std::vector <int>checkList;
    //add starting node to queue
    checkList.push_back(start);
    //set both vectors starting values
    for (int i = 0; i < gragh.size(); i++){
        visted[i] = false;
        results[i]= -1;
    }
    //set the starting node to have inital values
    results[start] = 0;
    //run through all connected nodes
    while(checkList.size()){
        int currentNode = checkList[checkList.size() - 1];
        checkList.pop_back();
        visted[currentNode] = true;
        //evaluate all the adjacent nodes
        for (int i = 0; i < gragh.size(); i++){
            if (gragh[currentNode][i] != -1){
                if (!visted[i] && std::find(checkList.begin(), checkList.end(), i) == checkList.end()){
                    checkList.push_back(i);
                }
                if (results[i] == -1 || results[i] > gragh[currentNode][i] + results[currentNode]){
                    results[i] = gragh[currentNode][i] + results[currentNode];
                }
            }
        }
        //sort checklist
        std::sort(checkList.begin(),checkList.end(),[results](int num1, int num2){
            // std::cout << "sort\n";
            return results[num1] > results[num2];
        });
        
    }
    // std::cout << "----------------------------------------\n";
    // std::cout << "From: " << start << " To: " << end << std::endl;
    // for (int i = 0; i < results.size(); i++){
    //     std::cout << results[i] << std::endl;
    // }
    // std::cout << "----------------------------------------\n";
    return results[end];
}