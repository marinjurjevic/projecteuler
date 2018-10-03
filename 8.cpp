/*

Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. 
What is the value of this product?

*/

#include <iostream>
#include <string>

using namespace std;

#define NO_ADJ_DIG 13

typedef unsigned long long int big;

string n;

big getStartSum(int i){
	big startSum = 1;
	
	for(int k = i; k < i + NO_ADJ_DIG; k++){
		
		startSum *= ( (int)(n[k] - '0'));
	}
	
	return startSum;
}

void start(){
	
	big maxProduct = getStartSum(0);
	
	// rest 
	big copyProduct = maxProduct;
	int flag = -1;
	
	for(int i = NO_ADJ_DIG; i< 1000; i++){
		int newDigit =  (int)(n[i] - '0');
		int prevDigit =  (int)(n[i - NO_ADJ_DIG] - '0');
		
		if(newDigit == 0){
			copyProduct = getStartSum(i+1);
			i+= NO_ADJ_DIG;
			continue;
		}else{
			copyProduct *= newDigit;
			if(prevDigit != 0){
				copyProduct /= prevDigit;
			}
		}
		if(copyProduct > maxProduct){
			maxProduct = copyProduct;
		}
	}
	
	cout << maxProduct << endl;
}

int main(void){
	

	string inputString;
	while (getline(cin, inputString))
	{
		n+=inputString;
	}
	
	start();
	
	return 0;
}