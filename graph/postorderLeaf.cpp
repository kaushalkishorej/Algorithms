#include <iostream>
#include <stack>

using namespace std;


void findLeafs(int (&arr)[6]) {

		stack<int> stack; 
                stack.push(arr[0]);
		for(int n = 2, c = 1; n <= sizeof(arr)/sizeof(int); n++, c++) {
			if (arr[c] < arr[n]) {
				stack.push(arr[c]);
			} else {
				int s2ndchild;
				bool found = false;
				while(!stack.empty()) {
					if (arr[n] > stack.top()) {
       					        s2ndchild = stack.top();	
						stack.pop();
						found = true;
					} else 
						break;		
				}
				if (found) 
					cout<<"-"<<s2ndchild<<"-"<<arr[c]<<"-";	
			}

		}
	        //cout<<arr[(sizeof(arr)/sizeof(int))-1];
}
int main()
{
  //int arr1[] = {2,4,3,7,9,8,6};
  int arr1[] = {3,5,4,7,8,6};
  //int arr1[] = {5,3,2,4,8,7,9};
  findLeafs(arr1);

}

