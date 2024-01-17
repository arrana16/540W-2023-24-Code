#include "main.h"
#include <stdio.h>
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

void setVels(float linVel, float angVel) {
    float leftVel = linVel - (angVel*WHEELTRACK/2);
    float rightVel = linVel - (angVel*WHEELTRACK/2);

    left_side_motors.move_velocity(leftVel/MAXLINVEL*600);
    right_side_motors.move_velocity(leftVel/MAXLINVEL*600);
};
void autonMovement(int time, float* array1, float* array2){ 
    double totalRuntime = time*10; 
    double startTime = pros::millis();
    while((pros::millis() - startTime) < totalRuntime){
        setVels(array1[pros::millis()/100], array2[pros::millis()/100]);
    }
    pros::delay(10);
}

void transform(const std::string filePath) {
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

    autonMovement(instances, linearVelocity, angularVelocity);
    }

int main()
{
   transform("filename.txt");
}