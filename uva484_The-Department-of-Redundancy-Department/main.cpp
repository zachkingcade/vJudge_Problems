/** 
 * Written by zachkingcade: 04/07/2020 5:46pm
 * Problem: uva 484 - The Department of Redundancy Department
 * 
 * Notes:
 * This one is real simple, we just need a list of key - value pairs and
 * to track how many times the keys appear in a given data set and then
 * set the value for that key to that
 */

//-----PreCompiler Directives-----
#include <iostream>
#include <string>
#include <vector>

//-----Prototypes-----
int findInIndex(int key, std::vector <int>listOfKeys);

//----------Main----------
int main(){
    //varibles
    int currentKey;
    int currentIndex;
    std::vector <int>keys;
    std::vector <int>values;

    while(std::cin >> currentKey){
        currentIndex = findInIndex(currentKey,keys);
        if (currentIndex < 0){
            keys.push_back(currentKey);
            values.push_back(1);
        } else {
            values[currentIndex]++;
        }
    }

    //after everything is processed print the results
    for(int i = 0; i < keys.size(); i++){
        std::cout << keys[i] << " " << values[i] << std::endl;
    }
}//end of main

//---------------Functions--------------

/** 
 * Finds a given key in a primitive vector based type of key value pair
 * and returns the index. If the key is not found then it return -1.
 * Assumes there is only 1 instance of any given key in the vector. otherwise it
 * returns the first.
 */
int findInIndex(int key, std::vector <int>listOfKeys){
    for (int i = 0; i < listOfKeys.size(); i++){
        if(listOfKeys[i] == key){
            return i;
        }
    }
    return -1;
}