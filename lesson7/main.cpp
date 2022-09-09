#include "students.h"
#include "task2.h"
#include "task3.h"
#include <numeric>

void task3()
{
    exercise_2::fullName fn;
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

    SG::StudentsGroup sg;
    sg.add_student(s);
    sg.Save();

    SG::StudentsGroup new_sg;
    new_sg.Open();
    cout << new_sg.GetAllInfo(fn) << endl;
}

int main()
{
    task1();
    task3();

    return 0;
}
