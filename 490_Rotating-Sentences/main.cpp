//-----PreCompiler Directives-----
#include <iostream>
#include <string>
#include <vector>

//---main---
int main (){
	//---varibles---
	std::string line;
	std::vector<std::string> lines;
	int linesNum;
	int longestString = 0;

	//grab all our lines
	while(getline(std::cin, line)){
		if (line.length() > longestString){longestString = line.length();}
		lines.push_back(line);
	}
	//get how many lines we have in total
	//minus one so it can be used as an index
	linesNum = lines.size() - 1;
	
	//loop thru character position between 0 and the longest strings length
	//the loop line by line from bottom of the vector to the top for each
	//character position
	for (int i = 0; i < longestString; i++){
		for (int j = linesNum; j > -1; j--){
			if (lines[j].length() > i){
				std::cout << lines[j][i];
			}else {std::cout << ' ';}
		}
		//new line after every character position
		std::cout << '\n';
	}
	
}