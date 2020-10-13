//-----PreCompiler Directives-----
#include <iostream>
#include <string>
#include <math.h>

//-----main-----
int main(){
    //---varibles---
    int numSet;
    int square;
    std::string sentence;
    bool failed;
    char trash;

    //grab our datasetSize
    std::cin >> numSet;
    //clear remaining '\n' out of buffer
    std::cin.get(trash);

    //our testing loop
    for (int i = 0; i < numSet; i++){
        failed = false;
        std::string modSentence = "";

        //read in our string to process
        getline(std::cin, sentence);
        //remove all non alphabet characters
        for (int i = 0; i < sentence.length(); i++){
            if (int(sentence[i]) > 96 && int(sentence[i]) < 123){
                modSentence += sentence[i];
            }
        }

        //check to make sure it is a square
        if (fmod(std::sqrt(modSentence.length()),1) != 0){
            failed = true;
            } else {
            square = std::sqrt(modSentence.length());
        }

        //check to make sure it is a Palindrome
        //check left to right (all other checks are equivalent!)
        if (failed == false){
            //right to left
            for (int i = 0; i < modSentence.length() / 2; i++){
                if(modSentence[i] != modSentence[modSentence.length() - i -1]){
                    failed = true;
                }
            }
        }
        
        //final print
        //print case number
        std::cout << "Case #" << i + 1 << ':' << std::endl; 
        //if we failed print no magic otherwsie print the square
        if (failed == true){
            std::cout << "No magic :(\n";
        } else {
            std::cout << square << std::endl;
        }

    }
    std::cout << std::endl;
}