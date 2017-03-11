#include <iostream>
#include <stack>

using namespace std;


void findLeafs(int (&arr)[7]) {

		stack<int> stack; 
		for(int n = 1, c = 0; n < (sizeof(arr)/sizeof(int)); n++, c++) {
			if (arr[c] > arr[n]) {
				stack.push(arr[c]);
			} else {
				bool found = false;
				while(!stack.empty()) {
					
					if (arr[n] > stack.top()) {
						stack.pop();
						found = true;
					} else 
						break;		
				}
				if (found) 
					cout<<"-"<<arr[c]<<"-";	
			}

		}
		cout<<arr[(sizeof(arr)/sizeof(int))-1];
}
int main()
{
  //int arr1[] = {6,3,2,4,5,8,7,9};
  int arr1[] = {6,2,1,3,8,7,9};
  //int arr1[] = {5,3,2,4,8,7,9};
  findLeafs(arr1);

}

