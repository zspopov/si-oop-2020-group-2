#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Standard Template Library
//1.Containers
//2.Algorithms
//3.Iterator

//print function
template <typename T>
void print(vector<T> & v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
} 

//Going to use this for examples with user defined data types
class Student {
    string name;
public:
    Student(){
        name = "gosho";
    }
    friend ostream& operator<<(ostream& out, const Student& rhs){
        out << rhs.name;
        return out;
    }
};

int main(){
    //User defined classes should used int vectot should have implemented operators == and < in order to work properly with algorithms

    //Initialization
    vector<int> iv; //empty int vector

    vector<int> iv1(5); //int vector with size 5 and every variable has its default value
    print(iv1); //output: 0 0 0 0 0 

    vector<char> cv(5); //char vector with size 5 and every variable has its default value
    print(cv); //output: 

    vector<Student> sv(5); //Student vector with size 5 and every object is created with its default constructor
    print(sv); //output: gosho gosho gosho gosho gosho

    vector<char> cv2(6, 'x'); //char vector with size 6 and evey variable has value 'x'
    print(cv2); //output: x x x x x x

    vector<int> iv2(iv); //initialize vector through copy constructor
    print(iv2); //output: 

    vector<int> iv3 = {1,5,2,6,3,435}; //other way of initialization
    print(iv3); //output: 1 5 2 6 3 435

    vector<int> iv4 {5,2,77,4,5,6}; //other way of initialization
    print(iv4); //output: 5 2 77 4 5 6 

    //Comparison operators
    //Vectors are being compared lexicographically
    //==,<,<=,!=,>,>= 
    cout << (iv == iv2) << "\n"; //output: 1
    cout << (iv3 < iv4) << "\n"; //output: 1

    //Accessing vector elements
    //1. Subscripting operator []
    //2. T& at(size_t index) function - throws exception if error
    cout << iv3.at(2) << " " << iv3[2] << "\n";

    //Size vs Capacity
    cout << cv2.capacity() << " " << cv2.size() << "\n"; //output: 6 6
    cv2.push_back('t');
    cout << cv2.capacity() << " " << cv2.size() << "\n"; //output: 12 7

    //Add elements (push_back)
    for(int i = 0; i < 10; i++){
        iv.push_back(i);
    }
    print(iv); //output: 0 1 2 3 4 5 6 7 8 9

    //Assign elements
    for(int i = 0; i < iv.size(); i++){
        iv[i] = iv.size() - i;
    }
    print(iv); //output: 10 9 8 7 6 5 4 3 2 1

    //Compare iterators and pointers

    //Pointers
    int arr[] = {7,35,7,9,5,6};
    int * p = arr; //p points to the first element of the array
    for(int i = 0; i < 6; i++){
        cout << *(p + i) << " "; //derefererencing (call the value that is present on that address)
    }
    cout << "\n";
    
    //Iterators
    //You can assume that iterator are very similar to pointers, so we can increment them and dereference them

    vector<int> v(10); //declare empty vector
    vector<int>::iterator iter; // take notice on the declaration

    //Assign through iterator
    iter = v.begin(); //v.begin() (returns iterator "pointing" at the first element of the vector) (just like pointers)
    int value = 0;
    while(iter != v.end()){ //v.end() (returns iterator "pointing" at the first of the vector) (just like pointers)
        *iter = value; //dereferencing the iterator and assignig it value
        iter++; //increment the iterator so that it points to the next element of the vector
        value++;
    } 
    print(v);

    //Print through iterator
    iter = v.begin();
    while(iter != v.end()){
        cout << *iter << " ";
        iter++;
    }
    cout << "\n";

    //Insert elements in vector

    //Definitions of the overloaded insertion functions
    /*
        iterator insert(iterator i, const T &val);
        void insert(iterator i, size_type num, const T & val);
        template <class InIter> void insert(iterator i, InIter start, InIter end);
    */

    vector<int> vec = {1,3,4,5,6,7,8,9,10};
    print(vec); // 1 3 4 5 6 7 8 9 10 

    vec.insert(vec.begin() + 1, 2); // vec.begin() + 1 (1st position) (using iterator to point the position at which we want to insert an element)
    print(vec); // 1 2 3 4 5 6 7 8 9 10 // don't forget we start counting positions from 0
    
    vec.insert(vec.begin() + 5, 5, 0); // vec.begin() + 5 (insert 5 zeros at 5th position)
    print(vec); // 1 2 3 4 5 0 0 0 0 0 6 7 8 9 10

    vector<int> vec2 {111,222,333,444,555}; 
    vec.insert(vec.begin() + 5, vec2.begin() + 1, vec2.end() - 1); // insert elements of other fector at 5th position in the first one
    print(vec); // 1 2 3 4 5 222 333 444 0 0 0 0 0 6 7 8 9 10

    //Erase elements from vector

    //Definitions of the overloaded erasion functions
    /*
        iterator erase(iterator i);
        iterator erase(iterator start, iterator end);
    */
    
    vec.erase(vec.begin() + 5, vec.begin() + 13); // erase every element between positions 5 and 13th
    print(vec); // 1 2 3 4 5 6 7 8 9 10

    vec.erase(vec.begin() + 5); // erase the element at position 5
    print(vec);  // 1 2 3 4 5 7 8 9 10

    //Clear vector

    vec.clear(); 
    print(vec); //
  
    return 0;
}