#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);

    std::ifstream myfile;
    myfile.open("test.txt");
    std::string myline;
    if ( myfile.is_open() ) {
    while ( myfile )
    std::getline (myfile, myline);
    std::cout << myline << '\n';
    }
    
    else {
    std::cout << "Couldn't open file\n";
    }
    return 0; 
}