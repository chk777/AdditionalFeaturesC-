#pragma once

#include <iostream>
#include <numeric>
#include <fstream>
#include "src-gen/exercise_2.pb.h"

used namespace std;

void task1()
{
    exercise_2::FullName fn;
    fn.set_name("Fedor");
    fn.set_surname("Baranov");
    fn.set_patronymic("Petrovich");

    exercise_2::Student s;
    *s.mutable_name() = fn;
    s.add_grades(5);
    s.add_grades(2);
    s.add_grades(4);
    s.add_grades(3);
    s.add_grades(4);
    s.add_grades(3);
    s.add_grades(4);
    s.add_grades(3);
    s.set_avg_score(accumulate(s.grades().begin(), s.grades().end(), 0) / s.grades().size());

    exercise_2::StudentsGroup sg;
    *sg.add_students() = s;

    ofstream out("student.bin", ios_base::binary);
    sg.SerializeToOstream(&out);
    out.close();

    exercise_2::StudentsGroup new_sg;
    ifstream in("student.bin", ios_base::binary);
    if (new_sg.ParseFromIstream(&in))
    {
        cout << new_sg.students(0).name().surname() << endl;
        cout << new_sg.students(0).avg_score() << endl;
    }
    else
    {
        cout << "Error!" << endl;
    }
    in.close();
}
