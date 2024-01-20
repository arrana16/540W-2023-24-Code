#include "main.h"
#include <ctime>
#include <iostream> 
#include <fstream>  

using namespace std;


void analyzeFile(const string& fileName){
    ifstream file(fileName);
    int pathTime = 0; 
    file >> pathTime;

    //int clock = clock() 
}

void simpleDrive(int y, int turn) {
    left_side_motors.move(y + turn);
    right_side_motors.move(y - turn);
}


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

void setVels(float linVel, float angVel) {
    double leftTarget = (linVel - (angVel*WHEELTRACK/2)) * 600/MAXLINVEL;
    double rightTarget = (linVel - (angVel*WHEELTRACK/2)) * 600/MAXLINVEL;

    double leftCurrent = (l1.get_actual_velocity()+l2.get_actual_velocity())/2;
    double rightCurrent = (r1.get_actual_velocity()+r2.get_actual_velocity())/2;

    double leftSideDrive = leftSideFeedback.calculate(leftTarget, leftCurrent);
    double rightSideDrive = rightSideFeedback.calculate(rightTarget, rightCurrent);

    left_side_motors.move_velocity(leftTarget/MAXLINVEL*600);
    right_side_motors.move_velocity(rightTarget/MAXLINVEL*600);
};

void autonMovement(int time, float* array1, float* array2){ 
    double totalRuntime = time*10; 
    double startTime = pros::millis();
    while((pros::millis() - startTime) < totalRuntime){
        setVels(array1[pros::millis()/100], array2[pros::millis()/100]);
    }
}

void MPDrive(const string filePath) {
    ifstream inputFile(filePath);

    //read first line in the file as a string
    string firstLine;
    getline(inputFile, firstLine);

    //read second line as a string
    string secondLine;
    getline(inputFile, secondLine);

    //read third line as a string
    string thirdLine;
    getline(inputFile, thirdLine);

    inputFile.close();

    replace(secondLine.begin(), secondLine.end(), ',', ' ');
    replace(secondLine.begin(), secondLine.end(), '[', ' ');
    replace(secondLine.begin(), secondLine.end(), ']', ' ');

    replace(thirdLine.begin(), thirdLine.end(), ',', ' ');
    replace(thirdLine.begin(), thirdLine.end(), '[', ' ');
    replace(thirdLine.begin(), thirdLine.end(), ']', ' ');
   
    //create int variable and cast first line string into an int
    int instances;
    istringstream iss(firstLine);
    iss >> instances;
    
    //initialize new arrays for the velocities
    float* linearVelocity = new float[instances];
    float* angularVelocity = new float[instances];
    
    processArray(secondLine, linearVelocity, instances);
    processArray(thirdLine, angularVelocity, instances);

    autonMovement(instances, linearVelocity, angularVelocity);
}
