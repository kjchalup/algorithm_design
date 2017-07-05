// This program is valid.
// Adding a semicolon on Line 10 wouldn't invalidate it.
#include <iostream>
#include <string>

int main(){
    { const std::string s = "a string";
        std::cout << s << std::endl;
    { const std::string s = "another string";
        std::cout << s << std::endl; };}
    return 0;
}
