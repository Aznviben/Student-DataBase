#include <iostream>
#include <stdexcept>
#ifndef PROJ1_STUDENT_H
#define PROJ1_STUDENT_H
#include "LinkedList.h"
#include "Course.h"
#include "Person.h"
class Student: public Person{
    uint32_t totalCreditHours = 0;
    uint32_t numberOfCourses = 0;
    uint32_t uid = 0;
    double gpa = 0;
    LinkedList *courses = new LinkedList;
public:
    Student(){

    }

    Student(string name1, uint8_t age1, uint32_t uid) : Person(name1, age1) {

        this->uid=uid;

        setName(name1);

        setAge(age1);

    }

    void PrintStudent(){
        cout<<"ID: "<< getUid()<< endl;
        cout<<"Name: "<< getName()<< endl;
        cout<<"Age: "<< unsigned(getAge())<< endl;
        cout<<"Credit Hours: "<< unsigned(getTotalCreditHours())<< endl;
        cout<<"GPA: "<< unsigned(getGpa())<<endl;
        cout<<"Number of Courses: "<< unsigned(getNumberOfCourses())<<endl;
        for(int i = 0; i<courses->getLength(); i++){
           cout<<courses->at(i)->getData()->getCode()
           <<" :"<<courses->at(i)->getData()->getTitle()
           << " ( Grade:"<<courses->at(i)->getData()->getGrade()
           << ") "<< unsigned(courses->at(i)->getData()->getCreditHour())
           <<" Credit Hour(s)"<<endl;
        }
    }

    friend ostream & operator <<( ostream &output, const Student *S ) {
        output<<"ID: "<< S->getUid()<< endl;
        output<<"Name: "<< S->getName()<< endl;
        output<<"Age: "<< unsigned(S->getAge())<< endl;
        output<<"Credit Hours: "<< unsigned(S->totalCreditHours)<< endl;
        output<<"GPA: "<< unsigned(S->gpa)<<endl;
        output<<"Number of Courses: "<< unsigned(S->numberOfCourses)<<endl;
        for(int i = 0; i<S->courses->getLength(); i++){
            output<<"Course Number ["<< i <<"]"<<endl;
            output<<S->courses->at(i)->getData()->getCode()
                <<" :"<<S->courses->at(i)->getData()->getTitle()
                << " ( Grade:"<<S->courses->at(i)->getData()->getGrade()
                << ") "<< unsigned(S->courses->at(i)->getData()->getCreditHour())
                <<" Credit Hour(s)"<<endl;
        }

        return output;
    }

    void addCourse(string code, string title, double grade, uint8_t creditHour){
        Course *a = new Course;
        a->setAll(code, title, grade, creditHour);
        courses->pushBack(a);
        setNumberOfCourses(getNumberOfCourses() + 1);
    }
    void addCourse(){
        Course *a = new Course;
        courses->pushBack(a);
        setNumberOfCourses(getNumberOfCourses() + 1);
    }

    void addCourse(Course *node){

        courses->pushBack(node);
        setNumberOfCourses(getNumberOfCourses() + 1);
        CalGpa();
    }

    void deleteCourse(int n){
        courses->deleteNode(courses->at(n));
        setNumberOfCourses(getNumberOfCourses() - 1);
        CalGpa();
        }

     node* getCourse(int index){
        return courses->at(index);
    }

    uint32_t getTotalCreditHours() const {
        return totalCreditHours;
    }

    void setTotalCreditHours(uint32_t totalCreditHours) {
        Student::totalCreditHours = totalCreditHours;
    }
    void CalTotalCreditHours(){
        double a = 0;
        double c = 0;

        for(int i = 0; i < getNumberOfCourses(); i++){
            c = c +courses->at(i)->getData()->getCreditHour();
        }
        a = c / getNumberOfCourses();
        Student::totalCreditHours = a;
    }

    uint32_t getNumberOfCourses() const {
        return numberOfCourses;
    }

    void setNumberOfCourses(uint32_t numberOfCourses) {
        Student::numberOfCourses = numberOfCourses;
    }

    uint32_t getUid() const {
        return uid;
    }

    void setUid(uint32_t uid) {
        Student::uid = uid;
    }

    double getGpa() const {
        return gpa;
    }
    void setGpa(double gpa) {
        Student::gpa = gpa;
    }
    void CalGpa() {
        double a = 0;
        double c = 0;

        for(int i = 0; i < courses->getLength(); i++){
            c = c +courses->at(i)->getData()->getGrade();
        }
        a = c / getNumberOfCourses();
        Student::gpa = a;
    }
    LinkedList *getCourses(){
        return courses;
    }



};
#endif //PROJ1_STUDENT_H
