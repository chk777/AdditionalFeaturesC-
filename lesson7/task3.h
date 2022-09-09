#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "src-gen/exercise_2.pb.h"

used namespace std;

namespace SG
{
    class IRepository
    {
    public:
        virtual void Open() = 0;
        virtual void Save() = 0;
        virtual ~IRepository() {};
    };

    class IMethods
    {
    public:
        virtual double GetAverageScore(const exercise_2::FullName &name) = 0;
        virtual string GetAllInfo(const exercise_2::FullName &name) = 0;
        virtual string GetAllInfo() = 0;
        virtual ~IMethods() {};
    };

    class StudentsGroup: public IRepository, public IMethods
    {
    private:
        vector<exercise_2::Student> m_students;
    public:
        void add_student(const exercise_2::Student &s)
        {
            m_students.push_back(s);
        }

        double GetAverageScore(const exercise_2::FullName &name)
        {
            auto it = find_if(m_students.begin(), m_students.end(), [&](const exercise_2::Student &s)
            {
                return tie(s.name().name(), s.name().surname(), s.name().patronymic()) ==
                tie(name.name(), name.surname(), name.patronymic());
            });

            if (it == m_students.end())
            {
                return 0.0;
            }

            return it->avg_score();
        }

        string GetAllInfo(const exercise_2::FullName &name)
        {
            auto it = find_if(m_students.begin(), m_students.end(), [&](const exercise_2::Student &s)
            {
                return tie(s.name().name(), s.name().surname(), s.name().patronymic()) ==
                tie(name.name(), name.surname(), name.patronymic());
            });

            if (it == m_students.end())
            {
                return {};
            }

            string temp = "Name: " + it->name().name() + ' ' + it->name().surname() + ' ' + it->name().patronymic() + '\n';
            temp += "Grade: ";
            for (int i = 0; i < it->grades().size(); ++i)
            {
                temp += to_string(it->grades(i)) + "; ";
            }
            temp += '\n';
            temp += "Avarge mark: " + to_string(it->avg_score()) + "\n\n";

            return temp;
        }

        string GetAllInfo()
        {
            string temp;

            for_each(m_students.begin(), m_students.end(), [&](const exercise_2::Student &s)
            {
                temp += GetAllInfo(s.name());
            });

            return temp;
        }

        void Save()
        {
            ofstream out("data.bin", ios_base::binary);
            auto size = m_students.size();
            out.write(reinterpret_cast<char*>(&size), sizeof(size));
            for_each(m_students.begin(), m_students.end(), [&](const exercise_2::Student &s)
            {
                s.SerializeToOstream(&out);
            });
            out.close();
        }

        void Open()
        {
            ifstream in("data.bin", ios_base::binary);
            size_t size = 0;
            in.read(reinterpret_cast<char*>(&size), sizeof(size));
            while (size--)
            {
                exercise_2::Student s;
                s.ParseFromIstream(&in);
                m_students.push_back(std::move(s));
            }
            in.close();
        }

        virtual ~StudentsGroup() {};
    };
}

void task3();
