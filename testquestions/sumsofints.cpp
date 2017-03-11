/*
You have a string of numbers, i.e. 123. You can insert a + or - sign in front of ever number, or you can leave it empty. Find all of the different possibilities, make the calculation and return the sum. 
For example; 
+1+2+3 = 6 
+12+3 = 15 
+123 = 123 
+1+23 = 24 
... 
-1-2-3 = 6 
... 
Return the sum of all the results.
*/

#include<iostream>
#include<vector>
using namespace std;

void printCombination(vector<int> &sumtillnow, int previousNo, int digits[]) {
	if(previousNo < 0) {
	  for( vector<int>::iterator it=sumtillnow.begin();it != sumtillnow.end(); ++it)
		cout<<*it<<"\n";
	  cout<<"print the vector";
	  return;
	}
	vector<int>suminthisIteration;
	vector<int>::iterator it;
	for(it= sumtillnow.begin();it != sumtillnow.end(); ++it) {
	  suminthisIteration.push_back(-digits[previousNo]+ *it);
	  suminthisIteration.push_back(+digits[previousNo]+ *it);
	}
	printCombination(suminthisIteration, --previousNo, digits);
}

int main() {
 int digits[3] ={1,2,3};
 vector<int>sumtillnow;
 sumtillnow.push_back(-digits[2]);
 sumtillnow.push_back(+digits[2]);
 printCombination(sumtillnow, 1, digits);
}
