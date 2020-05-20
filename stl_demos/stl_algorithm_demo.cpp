#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//print function
template <typename T>
void print(vector<T> & v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
} 

int main() {
    //Useful algorithms in STL
    //Algorithms can work with every container in STL and they do that throug iterators

    vector<int> vect = {43,63,8677,234,4, 64, 23,42,435,24,2435};
    print(vect); // 43 63 8677 234 4 64 23 42 435 24 2435 
    
    sort(vect.begin(),vect.end());
    print(vect); // 4 23 24 42 43 63 64 234 435 2435 8677 

    reverse(vect.begin(), vect.end());
    print(vect); // 8677 2435 435 234 64 63 43 42 24 23 4

    random_shuffle(vect.begin(), vect.end());
    print(vect); // 64 4 42 24 8677 63 435 2435 43 23 234 

    cout << *min_element(vect.begin(), vect.end()) << "\n"; // 4 
    cout << *max_element(vect.begin(), vect.end()) << "\n"; // 8677
    //notice these algorithms return iterator to the min or max element so they should be dereferenced

    //binary_search algorithm should be used on sorted arrays
    sort(vect.begin(), vect.end());
    cout << binary_search(vect.begin(), vect.end(), 435) << "\n";

    return 0;
}
