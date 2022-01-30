#include <iostream>
#include <vector>
#include <algorithm>

//Prototypes
void printTable(std::vector<std::vector <int>>);

int main() {
  //varibles
	int setsNum;

	//read in our datasets
	std::cin >> setsNum;

	for(int i = 0; i < setsNum; i++){
		//create our vector for storing parent relationship
		std::vector<std::vector <int>> parentList;
		//print our case data header
		std::cout << "Case " << i+1 << ":\n";

		//loop varibles
		int nodesWithChildren;
		std::vector<int> queue;
		int nextId = 1;

		//read in the number of nodes with children recorded
		std::cin >> nodesWithChildren;

		//prime our list by adding our root node to the list
		std::vector<int> newList;
		parentList.push_back(newList);
		queue.insert(queue.begin(), 0);

		//first we construct our relation ship list
		for(int j = 0; j < nodesWithChildren; j++){
			//read in how many children the queued node has
			int children;
			std::cin >> children;
			for(int k = 0; k < children; k++){
				//init new list
				std::vector<int> newList;
				parentList.push_back(newList);
				//copy parents list if not empty
				if(!parentList[queue.back()].empty()){
					parentList[nextId] = parentList[queue.back()];
				}
				//add parent to new item
				parentList[nextId].push_back(queue.back());
				queue.insert(queue.begin(), nextId);
				//increment id
				nextId++;
			}
			//remove parent from queue
			queue.pop_back();
		}
		printTable(parentList);
		//Now we have our relationship table and just need to answer the questions
		int questionNums;
		std::cin >> questionNums;
		for(int q = 0; q < questionNums; q++){
			//read in our parent and child for our question
			int parent;
			int child;
			std::cin >> parent >> child;
			//check if the parent is found in the childs parent list, print answer accordingly
			std::vector<int>::iterator check = std::find(parentList[child].begin(), parentList[child].end(), parent);
			if(check != parentList[child].end()){
				std::cout << "Yes\n";
			} else {
				std::cout << "No\n";
			}
		}
		//add a space between data sets
		std::cout << std::endl;
	}

} //end main

//prints our relationship table used as our representation of our data
void printTable(std::vector<std::vector <int>> List){
	for(int i = 0; i < List.size(); i++){
		std::cout << i << '\t';
		for(int j = 0; j < List[i].size(); j++){
			std::cout << List[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}