#include <iostream>
#include <stdexcept>

#ifndef PROJ1_RECORDS_H
#define PROJ1_RECORDS_H
#include "DoubleLinkedList.h"
#include "Student.h"
class Record{
    uint32_t numberOfStudents = 0;
    double averageGpa = 0;
    DoublyLinkedList  *students = new DoublyLinkedList ;
public:
    Record(){
        numberOfStudents=0;
        averageGpa = 0;
    }
    void addStudent(Student *T){
        students->pushBack(T);
        setNumberOfStudents(getNumberOfStudents()+1);
        calcAverageGpa();
    }
    void addStudent(string name1, uint8_t age1, uint32_t uid,uint32_t totalCreditHours, uint32_t numberOfCourses, double gpa){
        Student *a = new Student;
        a->setUid(uid);
        a->setName(name1);
        a->setAge(age1);
        a->setTotalCreditHours(totalCreditHours);
        a->setNumberOfCourses(numberOfCourses);
        a->setGpa(gpa);
        students->pushBack(a);
        setNumberOfStudents(getNumberOfStudents()+1);
        calcAverageGpa();
    }
    void addStudent(){
        Student *a = new Student;
        setNumberOfStudents(getNumberOfStudents()+1);
        students->pushBack(a);
        calcAverageGpa();
    }
    void deleteStudent(dnode *student){
        students->deleteNode(student);
        setNumberOfStudents(getNumberOfStudents()-1);
        calcAverageGpa();

    }

    void deleteStudent(int n){
        students->deleteNode(students->at(n));
        setNumberOfStudents(getNumberOfStudents()-1);
        calcAverageGpa();
    }


    /*
   void getStudent(int index){

        if (students->at(index)== nullptr || index <= numberOfStudents){
            cout<<"Student does not exist"<<endl;

        }else {
            cout<< students->at(index);
        }

    }
    */
    dnode *getStudent(int index){
        return students->at(index);
    }

    DoublyLinkedList *getStudents(){
        return students;
    }

    void printOutRecord(){
        cout<<endl;
        cout<<"The number of Students: "<< getNumberOfStudents() << endl;
        cout<<"The average GPA: "<< getAverageGpa() << endl;
        cout<<"Students:"<< endl;
        cout<<endl;
        for (int i = 0; i < students->getLength(); i++){
            students->at(i)->getData()->PrintStudent();
            cout<<endl;
        }

    }

    friend ostream & operator <<(ostream &cou, const Record R ) {
        cou << "The number of Students: " << unsigned(R.getNumberOfStudents()) << endl;
        cou << "The average GPA: " << R.getAverageGpa() << endl;
        cou << "Students:" << endl;
        for (int i = 0; i < R.students->getLength(); i++){
            cou<<"Student Number ["<< i  <<"]"<<endl;
           cou<< R.students->at(i)->getData();
            cou << endl;
        }
        return cou;
    }


    uint32_t getNumberOfStudents() const {
        return numberOfStudents;
    }

    void setNumberOfStudents(uint32_t numberOfStudents) {
        Record::numberOfStudents = numberOfStudents;
    }

    double getAverageGpa() const {
        return averageGpa;
    }

    void calcAverageGpa() {
        double a = 0;
        double c = 0;


        for(int i = 0; i < students->getLength(); i++){
            c = c + students->at(i)->getData()->getGpa();
        }
        a = c / students->getLength();
        Record::averageGpa = a;
    }




};
#endif //PROJ1_RECORDS_H
