#include <iostream>

int main() {
	//varibles
	int matrixSize;

	//prime our loop
	std::cin >> matrixSize;
	
	while(matrixSize > 0){
		//initalize our matrix
		int matrix[matrixSize][matrixSize];
		//fill our matrix with our input data
		for(int i = 0; i < matrixSize; i++){
			for(int j = 0; j < matrixSize; j++){
				std::cin >> matrix[i][j];
			}
		}

		//check for failed rows and how many
		int failedRow = -1;
		int numFailedRow = 0;
		for(int i = 0; i < matrixSize; i++){
			int total = 0;
			for (int j = 0; j < matrixSize; j++){
				total += matrix[i][j];
			}
			if(total % 2){
				failedRow = i;
				numFailedRow++;
			}
		}

		//check for failed columns
		int failedColumn = -1;
		int numFailedColumn = 0;
		for(int i = 0; i < matrixSize; i++){
			int total = 0;
			for (int j = 0; j < matrixSize; j++){
				total += matrix[j][i];
			}
			if(total % 2){
				failedColumn = i;
				numFailedColumn++;
			}
		}

		//print based on given logic
		if(failedRow != -1 && failedColumn != -1 && numFailedRow == 1 && numFailedColumn == 1){
			std::cout << "Change bit (" << (failedRow + 1) << ',' << (failedColumn + 1) << ")\n";
		}else if (failedRow != -1 || failedColumn != -1){
			std::cout << "Corrupt\n";
		} else {
			std::cout << "OK\n";
		}

		//read in our next matrix size, if 0 the loop will end
		std::cin >> matrixSize;
	}
}