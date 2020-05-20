#include <utility>
#include <string>
#include <iostream>
using namespace std;

int main(){
    //Pair is useful utility (notice you should include <utility> to use it) that can save effort and code 
    //for working with abstractions that should be paired

    pair<string, int> a("lkds", 3);
    cout << a.first << " " << a.second << "\n";
    
    return 0;
}

