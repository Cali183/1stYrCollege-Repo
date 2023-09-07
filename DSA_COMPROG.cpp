//libraries used
#include<iostream>//for cout and cin 
#include<string>//for string data type
#include<vector>//for vector
#include<algorithm>//for sorting
#include <iomanip>//for setw

using namespace std;

//declare the variables
struct Student
{
    string firstName;
    string lastName;
    string yearLevel;
    string program;
    string srCode;
};

//to store the students
vector<Student>students;
 

//define a function to enroll student
void enrollStudent(){   
    Student student;

    cout<<"Enter Student First Name: ";
    getline(cin, student.firstName);

    cout<<"Enter Student Last Name: ";
    getline(cin, student.lastName);

// Get the student year level, making sure it's a valid option.
    bool validYearLevel = false;
    while (!validYearLevel) {
        cout<<"Enter Year Level (Freshman, Sophomore, Junior, Senior): ";
        getline(cin, student.yearLevel);

 // If the year level entered is valid, set the flag to true to exit the loop.
        if (student.yearLevel == "Freshman" || student.yearLevel == "Sophomore" || student.yearLevel == "Junior" || student.yearLevel == "Senior") {
            validYearLevel = true;
        } else {
            cout << "Invalid year level. Please enter one of the following options: Freshman, Sophomore, Junior, Senior." << endl;
        }
    }

    bool validProgram = false;
    while (!validProgram) {
        cout << "Enter Student Program (IT or CS): ";
        getline(cin, student.program);
        if (student.program == "IT" || student.program == "CS") {
            validProgram = true;
        } else {
            cout << "Invalid program. Please enter either IT or CS." << endl;
        }
    }


    bool validSrCode = false;
    while (!validSrCode) {
        cout << "Enter Student Sr-Code (ex. 22-12345): ";
        getline(cin, student.srCode);
        if (student.srCode.length() == 8) {
            validSrCode = true;
        } else {
            cout << "Invalid Sr-Code. Please enter exactly 8 characters." << endl;
        }
    }



    students.push_back(student);

    cout<<"New Student Enrolled Succesfully"<<endl;
}


//function to remove student
void removeStudent(){
    string srCode;
    cout<<"Enter the SR code of the student you want to remove: ";
    getline(cin, srCode);
    
    // Search for the student by their SR code
    auto it = find_if(students.begin(), students.end(), [&](const Student& s){
        return s.srCode == srCode;
    });

    if (it != students.end()) {
        // Remove the student from the vector
        students.erase(it);
        cout << "Student with SR code " << srCode << " has been removed.\n";
    } else {
        cout << "Student with SR code " << srCode << " not found.\n";
    }
}


//define a function to display all
void displayAll(){
    if (students.empty()) {
        cout << "There are no enrolled students.\n";
    } else {
        cout << "\nEnrolled Student(s):\n\n";
        cout << left << setw(20) << "Name:" << setw(20) << "Sr-Code:" << setw(15) << "Year Level:" << "Program: \n";
        cout << "---------------------------------------------------------------\n";
        cout << setfill(' ');
        for (const auto& student : students) {
            cout << left << setw(20) << student.firstName + " " + student.lastName << setw(20) << student.srCode << setw(15) << student.yearLevel  << student.program <<endl;
            }
        }
}


//sort students by name
void sortName(){
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.lastName < b.lastName;
    });
    cout << "Students sorted by name.\n";
}

//sort students by year level
void sortYearLevel(){
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.yearLevel < b.yearLevel;
    });
    cout << "Students sorted by year level.\n";
}
 

//function to search a student
void searchStudent(){
    string srCode;
    cout<<"Enter the SR code of the student you want to find: ";
    getline(cin, srCode);
    
    // Search for the student by their SR code
    auto it = find_if(students.begin(), students.end(), [&](const Student& s){
        return s.srCode == srCode;
    });

    if (it != students.end()) {
         const auto& student = *it; // access the searched student using the iterator
            cout<<"Student Found: "<<endl;
            cout << "Name: " << student.firstName << " " << student.lastName << " " <<"(SR code: " << student.srCode << "| Year level: " << student.yearLevel << "| Program: " << student.program<<")"<<endl;
        
        
    } else {
        cout << "Student with SR code " << srCode << " not found.\n";
    }

}

//main function to run the program
int main(){
    int choice;
    do {
        cout << "+---------------------------------------------------+"<< endl;
        cout << "|                 STUDENT ENROLLMENT                |"<< endl;
        cout << "|                      SYSTEM                       |"<< endl; 
        cout << "|                     FOR CICS                      |"<< endl;  
        cout << "+---------------------------------------------------+"<< endl;                   
        cout << "|1. Enroll student      ||  4. Search student       |"<<endl;
        cout << "+---------------------------------------------------+"<< endl; 
        cout << "|2. Remove student      ||  5. Sort Student         |"<< endl;
        cout << "+---------------------------------------------------+"<< endl;  
        cout << "|3. Display student(s)  ||  6. Quit                 |"<< endl;
        cout << "+---------------------------------------------------+"<< endl; 
        cout << " Enter your choice: ";

        cin >> choice;
        cin.clear();
        fflush(stdin);

        switch (choice) {
        case 1:
            enrollStudent();
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            displayAll();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            int sortChoice;
            cout << "Sort by:\n";
            cout << "1. Name\n";
            cout << "2. Year Level\n";
            cout << "Enter your choice: ";

            cin >> sortChoice;
            cin.clear();
            fflush(stdin);

            switch (sortChoice) {
                case 1:
                    sortName();
                    break;
                case 2:
                    sortYearLevel();
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
            break;
        case 6:
            cout<<"GOODBYE, HAVE A NICE DAY!";
            break;
        
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        cout<<endl; 
    } while (choice !=6);
    
    return 0;
}