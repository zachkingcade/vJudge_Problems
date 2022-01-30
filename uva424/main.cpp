#include <iostream>
#include <string>
#include <vector>

int main() {
  //varibles
	std::vector<std::string> numberStrings;
	std::vector<unsigned short> result;

	//first lets read in our data, will end up adding ending 0 but thats ok
	std::string dString = "";
	while(dString != "0"){
		getline(std::cin, dString);
		numberStrings.push_back(dString);
	}

	//add all our numbers together
	for(int i = 0; i < numberStrings.size(); i++){
		//we'll use this to carry between numbers
		int carry = 0;
		for(int j = 0; j < numberStrings[i].size(); j++){

			//convert the number from char to int properly.
			int number = numberStrings[i][numberStrings[i].size() - j - 1] - '0';

			/*id our result number is currently smaller then the number we're adding, 
			add the number to our result */
			if((int)result.size() - j - 1 < 0){
				result.insert(result.begin(),number);
			} else {
				int newNum = result[result.size() - j - 1] + number + carry;
				//check if we need to carry one
				if((float)newNum /10 >= 1){
					newNum -= 10;
					carry = 1;
				} else {
					carry = 0;
				}
				//add whatever was left after checking for carry
				result[result.size() - j - 1] = newNum;
			}
		}
		//account for carries past the number we were adding
		if(carry){
			if(result.size() > numberStrings[i].size()){
				result[result.size() - numberStrings[i].size() - 1] += 1;
			} else {
				result.insert(result.begin(),1);
			}
		}
	}

	//read out the whole number stored in result
	for(int i = 0; i < result.size(); i++){
		std::cout << result[i];
	}
	std::cout << std::endl;
}