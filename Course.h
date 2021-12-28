#include <iostream>
#include <stdexcept>
#ifndef PROJ1_COURSE_H
#define PROJ1_COURSE_H
using namespace std;
class Course{
private:
    string code;
    string title;
    double grade = 0;
    uint8_t creditHour = 0;
public:
    Course(){
    code = "noCode";
    title="noTitle";
    }
    Course(string code, string title, double grade, uint8_t creditHour){
    this->code=code;
    this->title=title;
    this->grade=grade;
    this->creditHour=creditHour;
    }



    const string &getCode() const {
        return code;
    }

    void setCode(const string &code) {
        Course::code = code;
    }

    const string &getTitle() const {
        return title;
    }

    void setTitle(const string &title) {
        Course::title = title;
    }

    double getGrade() const {
        return grade;
    }

    void setGrade(double grade) {
        Course::grade = grade;
    }

    unsigned char getCreditHour() const {
        return creditHour;
    }

    void setCreditHour(unsigned char creditHour) {
        Course::creditHour = creditHour;
    }


    void printCourse(){

            cout<<"code is :"<< getCode() << endl;
            cout<<"title is :"<< getTitle() << endl;
            cout<<"grade is :"<< getGrade() << endl;
            cout<<"credit Hour is :"<< unsigned(getCreditHour()) << endl;
    }
    friend ostream & operator <<( ostream &output, const Course C ) {
        output<<"Code: "<< C.code<< endl;
        output<<"title: "<< C.title<< endl;
        output<<"Credit Hour: "<< unsigned(C.creditHour)<< "Hour(s)" <<endl;
        output<<"grade: "<< C.grade<< endl;
        return output;
    }


 void setAll(string code, string title, double grade, uint8_t creditHour){
        this->code=code;
        this->title=title;
        this->grade=grade;
        this->creditHour=creditHour;
    };




};


#endif //PROJ1_COURSE_H
