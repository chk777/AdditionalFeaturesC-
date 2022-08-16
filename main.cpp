#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
used namespace std

/*

Имеется база сотрудников и номеров их телефонов. Требуется написать соответствующие структуры для хранения данных,
 и заполнить контейнер записями из базы. Затем необходимо реализовать методы обработки данных,
  а также вывести на экран всю необходимую информацию.
 Важно! Имена переменным, классам и функциям давайте осознанные, состоящие из слов на английском языке.
 */
 /*
 1.Создайте структуру Person с 3 полями: фамилия, имя, отчество. Поле отчество должно быть опционального типа, т.к.
 не у всех людей есть отчество. Перегрузите оператор вывода данных для этой структуры.
 Также перегрузите операторы < и == (используйте tie).
 */
/*
Создайте структуру PhoneNumber с 4 полями:
· код страны (целое число)
· код города (целое число)
· номер (строка)
· добавочный номер (целое число, опциональный тип)
Для этой структуры перегрузите оператор вывода. Необходимо, чтобы номер телефона выводился в формате: +7(911)1234567 12,
 где 7 – это номер страны, 911 – номер города, 1234567 – номер, 12 – добавочный номер. Если добавочного номера нет,
то его выводить не надо. Также перегрузите операторы < и == (используйте tie)
*/
/* 3. Создайте класс PhoneBook, который будет в контейнере хранить пары: Человек – Номер телефона. Конструктор этого
класса должен принимать параметр типа ifstream – поток данных, полученных из файла. В теле конструктора происходит
считывание данных из файла и заполнение контейнера. Класс PhoneBook должен содержать перегруженный оператор вывода,
для вывода всех данных из контейнера в консоль.
В классе PhoneBook реализуйте метод SortByName, который должен сортировать элементы контейнера по фамилии людей в
алфавитном порядке. Если фамилии будут одинаковыми, то сортировка должна выполняться по именам, если имена будут
одинаковы, то сортировка производится по отчествам. Используйте алгоритмическую функцию sort.
Реализуйте метод SortByPhone, который должен сортировать элементы контейнера по номерам телефонов. Используйте
алгоритмическую функцию sort.
Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает кортеж из строки и PhoneNumber.
Строка должна быть пустой, если найден ровно один человек с заданном фамилией в списке. Если не найден ни один человек
 с заданной фамилией, то в строке должна быть запись «not found», если было найдено больше одного человека, то в строке
должно быть «found more than 1».
Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и, если находит заданного
человека в контейнере, то меняет его номер телефона на новый, иначе ничего не делает.
Функция main будет выглядеть так:
int main() {
этого
ifstream file("ХХХ"); // путь к файлу PhoneBook.txt PhoneBook book(file);
cout << book;
cout << "------SortByPhone-------" << endl;
book.SortByPhone();
cout << book;
cout << "------SortByName--------" << endl;
book.SortByName();
cout << book;
cout << "-----GetPhoneNumber-----" << endl;
// лямбда функция, которая принимает фамилию и выводит номер телефона
человека, либо строку с ошибкой
auto print_phone_number = [&book](const string& surname) {
cout << surname << "\t";
auto answer = book.GetPhoneNumber(surname);
if (get<0>(answer).empty())
cout << get<1>(answer);
else
cout << get<0>(answer);
cout << endl;
};
// вызовы лямбды
print_phone_number("Ivanov");
print_phone_number("Petrov");
cout << "----ChangePhoneNumber----" << endl;
book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
PhoneNumber{7, 123, "15344458", nullopt});
book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
PhoneNumber{ 16, 465, "9155448", 13 });
cout << book;
}
У вас должен получиться следующий вывод: (см. Методичка урока 1, стр. 28-29)
*/
struct Person
{
    string Firstname;
    string Surname;
    optional <string> Patronymic;

};

optional <string> getNullPatr(string &fam)
{
    if (fam == "")
    {
        return nullopt;
    }

    return fam;
}

ostream& operator<<(ostream &out, const Person &p)
{
    out << setw(15) << p.Firstname << setw(12) << p.Lastname;

    if (p.Patronymic.has_value())
    {
        out << setw(17) << p.Patronymic.value();
    }
    else
    {
        out << setw(18);
    }

    return out;
}

bool operator<(const Person &p1, const Person &p2)
{
    return tie(p1.Firstname, p1.Lastname, p1.Patronymic) < tie(p2.Firstname, p2.Lastname, p2.Patronymic);
}

bool operator==(const Person &p1, const Person &p2)
{
    return tie(p1.Firstname, p1.Lastname, p1.Patronymic) == tie(p2.Firstname, p2.Lastname, p2.Patronymic);
}

struct PhoneNumber
{
    int countryCode;
    int cityCode;
    string number;
    optional<int> additionalNumber;
};

bool operator<(const PhoneNumber &p1, const PhoneNumber &p2)
{
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.additionalNumber) < tie(p2.countryCode, p2.cityCode, p2.number, p2.additionalNumber);
}

optional<int> getOptInt(string &s)
{
    if (s == "")
    {
        return nullopt;
    }

    return stoi(s);
}

ostream& operator<<(ostream &out, const PhoneNumber &p)
{
    out << setw(3) << '+' << p.countryCode << '(' << p.cityCode << ')' << p.number;

    if (p.additionalNumber.has_value())
    {
        out << ' ' << p.additionalNumber.value();
    }

    return out;
}

class PhoneBook
{
private:
    vector<pair<Person, PhoneNumber>> m_data;
public:
    PhoneBook(ifstream &file)
    {
        if (!file)
        {
            cout << "Не удаётся открыть файл!" << endl;
            exit(-1);
        }

        for (string line; getline(file, line);)
        {
            stringstream str(line);
            vector<string> rowData;

            for (string s; getline(str, s, ';');)
            {
                rowData.push_back(s);
            }

            pair<Person, PhoneNumber> entry;

            for (size_t i = 0; i < rowData.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        entry.first.firstname = rowData[i];
                        break;
                    case 1:
                        entry.first.lastname = rowData[i];
                        break;
                    case 2:
                        entry.first.patronymic = getOptStr(rowData[i]);
                        break;
                    case 3:
                        entry.second.country_code = stoi(rowData[i]);
                        break;
                    case 4:
                        entry.second.city_code = stoi(rowData[i]);
                        break;
                    case 5:
                        entry.second.number = rowData[i];
                        break;
                    case 6:
                        entry.second.additional_number = getOptInt(rowData[i]);
                        break;
                }
            }

            m_data.push_back(entry);
        }
    }

    friend ostream& operator<<(ostream &out, const PhoneBook &pb)
    {
        for (const auto& [first, second] : pb.m_data)
        {
            out << first << ' ' << second << endl;
        }

        return out;
    }

    void SortByName()
    {
        sort(m_data.begin(), m_data.end(), [](const pair<Person, PhoneNumber> &lhs, const pair<Person, PhoneNumber> &rhs)
        {
            return lhs.first < rhs.first;
        });
    }

    void SortByPhone()
    {
        sort(m_data.begin(), m_data.end(), [](const pair<Person, PhoneNumber> &lhs, const pair<Person, PhoneNumber> &rhs)
        {
            return lhs.second < rhs.second;
        });
    }

    pair<string, vector<PhoneNumber>> GetPhoneNumber(const string &firstname)
    {
        vector<PhoneNumber> phoneNumbers;
        int count = 0;

        for_each(m_data.begin(), m_data.end(), [&](const auto &entry)
        {
            if (entry.first.firstname == firstname)
            {
                phoneNumbers.push_back(entry.second);
                ++count;
            }
        });

        switch (count)
        {
            case 0:
                return {"not found", phoneNumbers};
            case 1:
                return {"", phoneNumbers};
            default:
                return {"found more than 1", phoneNumbers};
        }
    }

    void ChangePhoneNumber(const Person &p, const PhoneNumber &pn)
    {
        auto entry = find_if(m_data.begin(), m_data.end(), [&](const auto &entry)
        {
            return entry.first == p;
        });

        if (entry != m_data.end())
        {
            entry->second = pn;
        }
    }
};

int main()
{
    ifstream file("PhoneBook.txt");
    PhoneBook book(file);
    cout << book;

    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;

    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;

    cout << "-----GetPhoneNumber-----" << endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона этого человека, либо ошибку
    auto print_phone_number = [&book](const string &surname)
    {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
        {
            for (size_t i = 0; i < get<1>(answer).size(); ++i)
            {
                cout << get<1>(answer)[i];
            }
        }
        else
        {
            cout << get<0>(answer);
        }
        cout << endl;
    };

    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person { "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber { 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person { "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber { 16, 465, "9155448", 13 });
    cout << book;

    return 0;
}
