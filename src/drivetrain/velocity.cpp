#include "main.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

void processArray(const std::string& word, float* array, int array_size) {
    std::string temp = "";
    int tracker = 0;

    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == ' ') {
            for (int j = i + 1; j < word.length(); ++j) {
                if (word[j] == ' ') break;
                temp.push_back(word[j]);
            }

            if (!temp.empty()) {
                std::istringstream iss(temp);
                iss >> array[tracker];

                ++tracker;
            }

            temp.clear();
        }
    }
}

int main()
{
    //assigns file path to be opened and analyzed
    const std::string filePath = "carrie-test.txt";
    std::ifstream inputFile(filePath);

    //read first line in the file as a string
    std::string firstLine;
    std::getline(inputFile, firstLine);

    //read second line as a string
    std::string secondLine;
    std::getline(inputFile, secondLine);

    //read third line as a string
    std::string thirdLine;
    std::getline(inputFile, thirdLine);

    inputFile.close();

    std::replace(secondLine.begin(), secondLine.end(), ',', ' ');
    std::replace(secondLine.begin(), secondLine.end(), '[', ' ');
    std::replace(secondLine.begin(), secondLine.end(), ']', ' ');

    std::replace(thirdLine.begin(), thirdLine.end(), ',', ' ');
    std::replace(thirdLine.begin(), thirdLine.end(), '[', ' ');
    std::replace(thirdLine.begin(), thirdLine.end(), ']', ' ');
   
    //create int variable and cast first line string into an int
    int instances;
    std::istringstream iss(firstLine);
    iss >> instances;
    
    //initialize new arrays for the velocities
    float* linearVelocity = new float[instances];
    float* angularVelocity = new float[instances];
    
    processArray(secondLine, linearVelocity, instances);
    processArray(thirdLine, angularVelocity, instances);

}