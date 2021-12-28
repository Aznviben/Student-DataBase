#include "Student.h"

int main(){
    Student S("Benajamin", 23, 7988);

    cout<<S;

    S.addCourse("Code", "Title", 23, 23);
    cout<<S;
};
