#include <iostream>
#include <string>
#include <fstream> //import .csv files
#include <algorithm> //remove commas
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    //locate and import .csv files
    ifstream icsA("C:/Users/Amani/Documents/CodeBlocks/csv/csvinput/ICSA.csv");
    ifstream icsB("C:/Users/Amani/Documents/CodeBlocks/csv/csvinput/ICSB.csv");
    ifstream icsC("C:/Users/Amani/Documents/CodeBlocks/csv/csvinput/ICSC.csv");

    //check if files were imported
    if (!icsA.is_open() || !icsB.is_open() || !icsC.is_open()) {
    cout << "Error! File not imported.\n";
    } else {
        string admNo, name, gender;
        string students[113][3];

        //fetch student details from files
        if (icsA.good()) {
            for (int x = 0; x < 30; x++) {
                getline(icsA, admNo, '"');
                getline(icsA, name, '"');
                getline(icsA, gender, '\n');

            //remove commas
            admNo.erase(std::remove(admNo.begin(), admNo.end(), ','), admNo.end());
            name.erase(std::remove(name.begin(), name.end(), ','), name.end());
            gender.erase(std::remove(gender.begin(), gender.end(), ','), gender.end());

            //populate array
            students[x][0] = admNo;
            students[x][1] = name;
            students[x][2] = gender;
            }
        }

        if (icsB.good()) {
            for (int x = 30; x < 58; x++) {
                getline(icsB, admNo, '"');
                getline(icsB, name, '"');
                getline(icsB, gender, '\n');

            //remove commas
            admNo.erase(std::remove(admNo.begin(), admNo.end(), ','), admNo.end());
            name.erase(std::remove(name.begin(), name.end(), ','), name.end());
            gender.erase(std::remove(gender.begin(), gender.end(), ','), gender.end());

            //populate array
            students[x][0] = admNo;
            students[x][1] = name;
            students[x][2] = gender;
            }
        }

        if (icsC.good()) {
            for (int x = 58; x < 113; x++) {
                getline(icsC, admNo, '"');
                getline(icsC, name, '"');
                getline(icsC, gender, '\n');

            //remove commas
            admNo.erase(std::remove(admNo.begin(), admNo.end(), ','), admNo.end());
            name.erase(std::remove(name.begin(), name.end(), ','), name.end());
            gender.erase(std::remove(gender.begin(), gender.end(), ','), gender.end());

            //populate array
            students[x][0] = admNo;
            students[x][1] = name;
            students[x][2] = gender;
            }
        }

    //randomize the students details to get mixture
    srand(time(0)); //seed random number

    for (int i = 0; i < 113; i++) {
        int index = rand() % 113; // random index
        //swap elements in array
        string tempAdmNo = students[i][0];
        string tempName = students[i][1];
        string tempGender = students[i][2];

        students[i][0] = students[index][0];
        students[i][1] = students[index][1];
        students[i][2] = students[index][2];

        students[index][0] = tempAdmNo;
        students[index][1] = tempName;
        students[index][2] = tempGender;
    }

    // assign students to groups
    string icsA[57][3];
    string icsB[56][3];
    int males = 0;
    int females = 0;
    int i = 0;
    int j = 0;

    for (int x = 0; x < 113; x++) {
        if (students[x][2] == "M" && males < 36 && i < 57) {
        icsA[i][0] = students[x][0];
        icsA[i][1] = students[x][1];
        icsA[i][2] = students[x][2];
        males++;
        i++;
    } else if (students[x][2] == "M" && males < 71 && j < 56) {
        icsB[j][0] = students[x][0];
        icsB[j][1] = students[x][1];
        icsB[j][2] = students[x][2];
        males++;
        j++;
    } else if (students[x][2] == "F" && females < 21 && i < 57) {
        icsA[i][0] = students[x][0];
        icsA[i][1] = students[x][1];
        icsA[i][2] = students[x][2];
        females++;
        i++;
    } else if (students[x][2] == "F" && females < 42 && j < 56) {
        icsB[j][0] = students[x][0];
        icsB[j][1] = students[x][1];
        icsB[j][2] = students[x][2];
        females++;
        j++;
    } else {
        cout << "Error occured while reading files!";
    }
}

    //Print out assorted lists
    ofstream NewIcsA("C:/Users/Amani/Documents/CodeBlocks/csv/csvoutput/ICSA.csv");
    ofstream NewIcsB("C:/Users/Amani/Documents/CodeBlocks/csv/csvoutput/ICSB.csv");

    cout << "NEW ICS A MEMBERS\n";
    for (int y = 0; y < 57; y++) {
        NewIcsA << icsA[y][0] << "," << icsA[y][1] << "," << icsA[y][2] << endl;
        cout << icsA[y][0] << "\t" << icsA[y][1] << "\t\t" << icsA[y][2] << endl;
    }

    cout << "\n NEW ICS B MEMBERS\n";
    for (int y = 0; y < 56; y++) {
        NewIcsB << icsB[y][0] << "," << icsB[y][1] << "," << icsB[y][2] << endl;
        cout << icsB[y][0] << "\t" << icsB[y][1] << "\t\t" << icsB[y][2] << endl;
    }
}

    icsA.close();
    icsB.close();
    icsC.close();
    return 0;
}
