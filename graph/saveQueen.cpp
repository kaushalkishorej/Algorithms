#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    int leftright=0,updown=0;
    //determine up/down and left/right
        string line = grid[0];
        if( line[0] == 'p') {
            updown = 1;
            leftright = -1;
        }
        if( line[line.length()-1] == 'p') {
            updown =1;
            leftright =1;
        }
        line = grid[n-1];
        if( line[0] == 'p') {
            updown = -1;
            leftright = -1;
        }
        if( line[line.length()-1] == 'p') {
            updown =-1;
            leftright =1;
        }
    
    //steps to take
    for(int i=0;i<n/2; i++) {
        if(updown == 1)
            cout<<"UP"<<"\n";
        else
            cout<<"DOWN"<<"\n";
        if(leftright == 1)
            cout<<"RIGHT"<<"\n";
        else
            cout<<"LEFT"<<"\n";
    }
       
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}

