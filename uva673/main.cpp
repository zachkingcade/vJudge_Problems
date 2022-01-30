#include <iostream>
#include <string>
#include<vector>

int main() {
  //varibles
	int dataSet;
	std::string data;

  //read in our number of strings
	std::cin >> dataSet;

	//get rid of /n still in file and prime loop
	std::getline(std::cin, data);

	//run our loop across all strings
	for (int i = 0; i < dataSet; i++){
		/*grab our string, this program could be modded to run character by character but here we
		are going to read in the whole string and process across that */
		std::getline(std::cin, data);
		//create our stack for this string
		std::vector <char>stack;
		bool failed = false;
		//run across our string checking each character
		for (int j = 0; j < data.size() && !failed; j++){
			if (data == "" || data[j] == ' '){
				/*do nothing, either this is true and will fall thru since failed is already false or 
				this is a space and we ignore is has it has no bearing on the truth of our string*/
				//if our char is an opening type add it to the stack
			} else if (data[j] == '(' || data[j] == '['){
				stack.push_back(data[j]);
				/*if our char is an ending type and the top of the stack is an opening type of the kind <[] or ()>
				then pull from the stack, if the stack is empty this fails by default, also doing .back on an empty
				vector causes a seg fault*/ 
			} else if (stack.size() && ((data[j] == ')' && stack.back() == '(') || (data[j] == ']' && stack.back() == '[')) ){
				stack.pop_back();
				//if none of the above were true then this string fails
			} else {
				failed = true;
			}
		}
	
		/*print the results of our tests, if we failed at anypoint or we still have open brackets or
		open parentheses on the stack then it is not true otherwise it is */
		if(failed || stack.size() > 0){
			std::cout << "No\n";
		} else {
			std::cout << "Yes\n";
		}
	}
}