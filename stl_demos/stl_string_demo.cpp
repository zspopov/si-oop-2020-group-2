#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

// What gives you STL string:
// 1. Consistency - a string now defines a data type, not a char array
// 2. Convenience - may use standard C++ operators
// 3. Safety - array boundaries cannot be overrun

// Although not traditionally thought of as part of the STL, string is another container
// class defined by C++. This means that it supports the algorithms described in the
// previous section. However, strings have additional capabilities. To have access to
// the string class, you must include <string> in your program.


int main(){
    //Cons of char arrays

    //With char arrays (usually called C-style strings) you cannot use typycal operations likewise primitive data types
    char s1[80], s2[80], s3[80];
    //s1 = "Alpha"; //can't do
    //s2 = "Beta"; //can't do
    //s3 = s1 + s2;

    //In order to do these operations functions from <cstring> library should be used
    strcpy(s1,"Alpha");
    strcpy(s2,"Beta");
    strcpy(s3,s1);
    strcat(s3,s2);

    cout << s1 << " " << s2 << " " << s3 << "\n"; 

    //Last but not least, very fond of boundary overruns

    
    
    
    //Let's see how the string makes things better

    //Use of C++ operators
    // =  - assignment
    // +  - concatenation
    // += - concatenation assignment
    // == - equality
    // != - inequality
    // <  - less than
    // <= - less than or equal
    // >  - bigger than
    // >= - bigger than or equal
    // [] - subscripting
    // << - output
    // >> - input

    //Assignment
    string str1 = "alpha";
    string str2 = "beta";

    //Assigning a partial string
    string str3;
    str3.assign(str2,0,2); // assign the value of the string between 0 and 2nd position 
    cout << str3 << "\n"; // be

    //Concatenation
    string str4 = str1 + str2;
    cout << str4 << "\n"; // alphabeta

    const char * c = "lll";
    str4 = str1 + c;
    cout << str4 << "\n"; // alphalll

    //Append
    str4.append(str2.begin(), str2.begin() + 4); // append using iterators
    cout << str4 << "\n"; // alphalllbeta

    str4.append("gama"); // append the whole string
    cout << str4 << "\n"; // alphalllbetagama

    str4.append("delta", 3); // append the first 3 symbols of "delta"
    cout << str4 << "\n"; // alphalllbetagamadel

    //Insert
    string str5 = "abef";
    str5.insert(2, "cd"); // inserts at 2nd position "cd"
    cout << str5 << "\n";  // abcdef

    //Replace
    string str6 = str4;
    str6.replace(5, 3, "nnn"); // replaces 3 char at position 5 with "nnn"
    cout << str6 << "\n"; // alphannnbetagamadel

    //Erase 
    str6.erase(5, 3); // erases 3 chars starting at position 5
    cout << str6 << "\n"; // alphabetagamadel
    
    //Find
    cout << str5.find('d') << "\n"; // 3 (returns the position of the char 'd')

    //Comparisson operators
    // ==,<,<=,!=,>,>=
    cout << (str1 != str2) << " " <<  (str1 > str2) << "\n";

    //Useful methods
    cout << str5.front() << "\n"; // returns the first symbol

    cout << str5.c_str() << "\n"; // returns a const char * 

    cout << str5.length() << " " << str5.size() << "\n"; // the same

    cout << str5.substr(0, 4) << "\n"; // returns a string that is a substring

    //Algorithms can be applied to string
    sort(str5.begin(), str5.end());
    cout << str5 << "\n";

    return 0;
}