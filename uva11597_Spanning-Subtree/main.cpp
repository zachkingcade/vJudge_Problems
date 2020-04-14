/** 
 * Written by zachkingcade: 04/14/2020 4:14am
 * Problem: uva 11597 - Spanning Subtree
 * 
 * Important Definitions:
 * A Spanning Tree is defined as: A subtree that contains all vertices
 * with the minimum number of vertices.
 * 
 * Notes:
 * I actually asked someone for help on this one and they sent me this
 * line of logic on how to go about solving this problem:
 * While you have n vertex and n*(n-1) edges, each total number edges of spanngin tree is n-1.
 * then you can have at most n*(n-1)/2/(n-1)=>n/2 numbers of such a tree.
 */

//-----Precompiler Directives-----
#include<iostream>

int main(){
    //varibles
    int input;
    int caseNum = 1;

    //prime the loop using the first input values
    std::cin >> input;

    //while input is larger then 0
    while(input){
        std::cout << "Case " << caseNum << ": " << input/2 << '\n';
        caseNum++;
        std::cin >> input;
    }
}