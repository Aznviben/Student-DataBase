#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "Person.h"
#include "Course.h"
#include "Student.h"
#include "Records.h"

using namespace std;

int main() {
    Record r ;

    ifstream ip("/default.csv");

    if(!ip.is_open()) cout<<"Error: file Open";

    string uid;
    string Name;
    string age;
    string TCH;
    string noc;
    string gpa;


    while(ip.good()){
        getline(ip,uid,',');
        getline(ip,Name,',');
        getline(ip, age, ',');
        getline(ip,TCH,',');
        getline(ip,noc,',');
        getline(ip, gpa, '\n');

        r.addStudent(Name, stoi(age), stoi(uid), stoi(TCH), stoi(noc), stod(gpa) );

    }
    ip.close();

    ifstream ip2("/coursesDefaults.csv");

    if(!ip2.is_open()) cout<<"Error: file Open";

    string uid2; //ID
    string CC; //Course Code
    string CT; //Course Title
    string CH; //Course Hours
    string Grade; //Grade


    while(ip2.good()){
        getline(ip2,uid2,',');
        getline(ip2,CC,',');
        getline(ip2, CT, ',');
        getline(ip2,CH,',');
        getline(ip2, Grade, '\n');

        for (int j = 0; j<r.getStudents()->getLength();j++)
            if (r.getStudent(j)->getData()->getUid() == stoi(uid2)) {
                r.getStudent(j)->getData()->addCourse(CC, CT, stod(Grade),stoi(CH));
            }


    }
    ip2.close();




    cout<<"Welcome to FlPoly Simple Student Record System"<<endl;
    cout<<"______________________________________________"<<endl<<endl;
    int select = 0;
while ( select != 7) {
    cout << "Please Choose" << endl;
    cout << "Please select one of the following:" << endl;
    cout << "[1] Print all records" << endl;
    cout << "[2] Print the record for a single student" << endl;
    cout << "[3] Add a student" << endl;
    cout << "[4] Delete a student" << endl;
    cout << "[5] Add a course to a student" << endl;
    cout << "[6] Delete a course from a student." << endl;
    cout << "[7] EXIT" << endl;
    cout << "Enter your selection:" << endl;
    cin >> select;
    string code;
    string title;
    double grade = 0;
    uint32_t creditHour1=0;
    uint32_t numberOfCourses1= 0;
    string name1;
    uint8_t age1=0;
    int studentID1=0;
    double gpa1;
    int n = 0;
    int m = 0;
    switch (select) {
        case 1:
            cout <<r;
            if (r.getStudents()->getLength()==0){
                cout<<"there are no students"<<endl;
            }
            break;
        case 2:
            for(int k = 0; k<r.getStudents()->getLength(); k++){
                cout<<"["<< k<< "]" << " : "<< r.getStudent(k)->getData()->getName()<< endl;
            }

            if (r.getStudents()->getLength()==0){
                cout<<"there are no students"<<endl;
            }else {
                cout << "Enter Student Number to Print:" << endl;
                cin >> n;

                if (n > r.getStudents()->getLength()) {
                    cout << "Student does not exist" << endl;

                } else {
                     r.getStudent(n)->getData()->PrintStudent();
                }
            }
            break;
        case 3:

            cout << "Enter Student Name: " << endl;
            cin>>name1;
            cin.clear();
            cin.ignore();
            cout << "Enter Student Age: " << endl;
            cin>>age1;
            cin.clear();
            cin.ignore();
            cout << "Enter Student ID: " << endl;
            cin>>studentID1;
            cin.clear();
            cin.ignore();
            cout << "Enter Credit Hours: " << endl;
            cin>>creditHour1;
            cin.clear();
            cin.ignore();
            cout << "Enter number of Courses: " << endl;
            cin>>numberOfCourses1;
            cin.clear();
            cin.ignore();
            cout << "Enter GPA :" << endl;
            cin>>gpa1;
            cin.clear();
            cin.ignore();

            r.addStudent(name1 ,age1 ,studentID1 ,creditHour1, numberOfCourses1, gpa1);
            break;
        case 4:
            for(int k = 0; k<r.getStudents()->getLength(); k++){
                cout<<"["<< k<< "]" << " : "<< r.getStudent(k)->getData()->getName()<< endl;
            }
            if (r.getStudents()->getLength()==0){
                cout<<"there are no students"<<endl;
                break;
            }
            cout << "Enter Student Number To Delete:" << endl;
            cin >> n;
            cin.clear();
            cin.ignore();
            r.deleteStudent(n);
            break;
        case 5:
            for(int k = 0; k<r.getStudents()->getLength(); k++){
                cout<<"["<< k<< "]" << " : "<< r.getStudent(k)->getData()->getName()<< endl;
            }
            cout << "Enter Student Number To add Course" << endl;
            cin >> n;
            cin.clear();
            cin.ignore();
            cout << "Enter Course Code: " << endl;
            cin >> code;
            cin.clear();
            cin.ignore();
            cout << "Enter Course Title: " << endl;
            cin >> title;
            cin.clear();
            cin.ignore();
            cout << "Enter Course Grade: " << endl;
            cin >> grade;
            cin.clear();
            cin.ignore();
            cout << "Enter Course Credit Hours: " << endl;
            cin >> creditHour1;
            cin.clear();
            cin.ignore();
            r.getStudent(n)->getData()->addCourse(code, title, grade, creditHour1);
            break;
        case 6:
            for(int k = 0; k<r.getStudents()->getLength(); k++){
                cout<<"["<< k<< "]" << " : "<< r.getStudent(k)->getData()->getName()<< endl;
            }
            if (r.getStudents()->getLength()==0){
                cout<<"there are no students"<<endl;
                break;
            }
            cout << "Enter Student Number: " << endl;
            cin >> n;
            cin.clear();
            cin.ignore();
            for(int l = 0; l<r.getStudent(n)->getData()->getCourses()->getLength(); l++){
                cout<<"["<< l<< "]" << " : "<< r.getStudent(n)->getData()->getCourse(l)->getData()->getTitle()<< endl;
            }
            cout << "Enter Student's Course to Delete: "<<endl;
            cin >> m;
            cin.clear();
            cin.ignore();
            r.getStudents()->at(n)->getData()->deleteCourse(m);
            break;
        case 7:

            break;

        default:
            cout << "Not an Option";
            break;
    }
}
    return 0;
}
