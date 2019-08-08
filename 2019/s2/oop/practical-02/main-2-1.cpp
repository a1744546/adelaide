#include <iostream>
#include <string> 
using namespace std;
extern void print_as_binary(std::string decimal_number);
int main(){

std::string decimal_number = "73";
print_as_binary(decimal_number);
return 0;
}