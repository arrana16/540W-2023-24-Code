#include "main.h"
#include <ctime>
#include <iostream> 
#include <fstream>  

using namespace std;

// Function to analyze a file
void analyzeFile(const string& fileName){
    ifstream file(fileName);
    int pathTime = 0; 
    file >> pathTime;

    //int clock = clock() 
}

// Function for simple drive
void simpleDrive(int y, int turn) {
    left_side_motors.move(y + turn);
    right_side_motors.move(y - turn);
}

// Function for PTO drive
void PTODrive(int y, int turn){
    left_PTO.move(y+turn);
    right_PTO.move(y-turn);
}

// Function to process an array
void processArray(const string& word, float* array, int array_size) {
    string temp = "";
    int tracker = 0;

    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == ' ') {
            for (int j = i + 1; j < word.length(); ++j) {
                if (word[j] == ' ') break;
                temp.push_back(word[j]);
            }

            if (!temp.empty()) {
                istringstream iss(temp);
                iss >> array[tracker];

                ++tracker;
            }

            temp.clear();
        }
    }
}

// Function to set velocities
void setVels(float linVel, float angVel) {
    double leftTarget = (linVel + (angVel*WHEELTRACK/2)) * 600/MAXLINVEL;
    double rightTarget = (linVel - (angVel*WHEELTRACK/2)) * 600/MAXLINVEL;

    double leftCurrent = (l1.get_actual_velocity()+l2.get_actual_velocity())/2;
    double rightCurrent = (r1.get_actual_velocity()+r2.get_actual_velocity())/2;

    double leftBase = (linVel + (angVel*WHEELTRACK/2)) * 12000/MAXLINVEL;
    double rightBase = (linVel - (angVel*WHEELTRACK/2)) * 12000/MAXLINVEL;

    double leftSideDrive = leftSideFeedback.calculate(leftTarget, leftCurrent)+leftBase;
    double rightSideDrive = rightSideFeedback.calculate(rightTarget, rightCurrent)+rightBase;

    left_side_motors.move_voltage(leftSideDrive);
    right_side_motors.move_voltage(rightSideDrive);
};

// Function for autonomous movement
void autonMovement(int time, float* array1, float* array2){ 
    int totalRuntime = time*10; 
    int startTime = pros::millis();
    while((pros::millis() - startTime) < totalRuntime){
        setVels(array1[(pros::millis()-startTime)/10], array2[(pros::millis()-startTime)/10]);
    }
    setVels(0, 0);  
}

// Function for a 2D Motion profiled drive
void MPDrive(const string filePath) {
    ifstream inputFile(filePath);

    // Read first line in the file as a string
    string firstLine;
    getline(inputFile, firstLine);

    // Read second line as a string
    string secondLine;
    getline(inputFile, secondLine);

    // Read third line as a string
    string thirdLine;
    getline(inputFile, thirdLine);

    inputFile.close();

    // Replace commas and brackets with spaces in the second line
    replace(secondLine.begin(), secondLine.end(), ',', ' ');
    replace(secondLine.begin(), secondLine.end(), '[', ' ');
    replace(secondLine.begin(), secondLine.end(), ']', ' ');

    // Replace commas and brackets with spaces in the third line
    replace(thirdLine.begin(), thirdLine.end(), ',', ' ');
    replace(thirdLine.begin(), thirdLine.end(), '[', ' ');
    replace(thirdLine.begin(), thirdLine.end(), ']', ' ');
   
    // Create int variable and cast first line string into an int
    int instances;
    istringstream iss(firstLine);
    iss >> instances;
    
    // Initialize new arrays for the velocities
    float* linearVelocity = new float[instances];
    float* angularVelocity = new float[instances];
    
    processArray(secondLine, linearVelocity, instances);
    processArray(thirdLine, angularVelocity, instances);

    autonMovement(instances, linearVelocity, angularVelocity);
}
