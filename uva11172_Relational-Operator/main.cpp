//Team Test that everyone can compile, redirect io and submit to vjudge
//-----PreCompiler Directives-----
#include<iostream>

//-----main-----
int main (){
    int numSet;     //tracks the size of our dataset
    int numOne;     //stores our first number to compare
    int numTwo;     //stores our second number to compare

    //grab size of our dataset
    std::cin >> numSet;

    for (int i = 0; i < numSet; i++){
        //grab our numbers
        std::cin >> numOne >> numTwo;
        //compare our numbers
        if (numOne < numTwo){
            std::cout << '<' << '\n';
        } else if (numOne > numTwo){
            std::cout << '>' << '\n';
        } else {
            std::cout << '=' << '\n';
        }
    }
}//end of main