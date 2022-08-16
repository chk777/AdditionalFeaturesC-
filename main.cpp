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

������� ���� ����������� � ������� �� ���������. ��������� �������� ��������������� ��������� ��� �������� ������,
 � ��������� ��������� �������� �� ����. ����� ���������� ����������� ������ ��������� ������,
  � ����� ������� �� ����� ��� ����������� ����������.
 �����! ����� ����������, ������� � �������� ������� ����������, ��������� �� ���� �� ���������� �����.
 */
 /*
 1.�������� ��������� Person � 3 ������: �������, ���, ��������. ���� �������� ������ ���� ������������� ����, �.�.
 �� � ���� ����� ���� ��������. ����������� �������� ������ ������ ��� ���� ���������.
 ����� ����������� ��������� < � == (����������� tie).
 */
/*
�������� ��������� PhoneNumber � 4 ������:
� ��� ������ (����� �����)
� ��� ������ (����� �����)
� ����� (������)
� ���������� ����� (����� �����, ������������ ���)
��� ���� ��������� ����������� �������� ������. ����������, ����� ����� �������� ��������� � �������: +7(911)1234567 12,
 ��� 7 � ��� ����� ������, 911 � ����� ������, 1234567 � �����, 12 � ���������� �����. ���� ����������� ������ ���,
�� ��� �������� �� ����. ����� ����������� ��������� < � == (����������� tie)
*/
/* 3. �������� ����� PhoneBook, ������� ����� � ���������� ������� ����: ������� � ����� ��������. ����������� �����
������ ������ ��������� �������� ���� ifstream � ����� ������, ���������� �� �����. � ���� ������������ ����������
���������� ������ �� ����� � ���������� ����������. ����� PhoneBook ������ ��������� ������������� �������� ������,
��� ������ ���� ������ �� ���������� � �������.
� ������ PhoneBook ���������� ����� SortByName, ������� ������ ����������� �������� ���������� �� ������� ����� �
���������� �������. ���� ������� ����� �����������, �� ���������� ������ ����������� �� ������, ���� ����� �����
���������, �� ���������� ������������ �� ���������. ����������� ��������������� ������� sort.
���������� ����� SortByPhone, ������� ������ ����������� �������� ���������� �� ������� ���������. �����������
��������������� ������� sort.
���������� ����� GetPhoneNumber, ������� ��������� ������� ��������, � ���������� ������ �� ������ � PhoneNumber.
������ ������ ���� ������, ���� ������ ����� ���� ������� � �������� �������� � ������. ���� �� ������ �� ���� �������
 � �������� ��������, �� � ������ ������ ���� ������ �not found�, ���� ���� ������� ������ ������ ��������, �� � ������
������ ���� �found more than 1�.
���������� ����� ChangePhoneNumber, ������� ��������� �������� � ����� ����� �������� �, ���� ������� ���������
�������� � ����������, �� ������ ��� ����� �������� �� �����, ����� ������ �� ������.
������� main ����� ��������� ���:
int main() {
�����
ifstream file("���"); // ���� � ����� PhoneBook.txt PhoneBook book(file);
cout << book;
cout << "------SortByPhone-------" << endl;
book.SortByPhone();
cout << book;
cout << "------SortByName--------" << endl;
book.SortByName();
cout << book;
cout << "-----GetPhoneNumber-----" << endl;
// ������ �������, ������� ��������� ������� � ������� ����� ��������
��������, ���� ������ � �������
auto print_phone_number = [&book](const string& surname) {
cout << surname << "\t";
auto answer = book.GetPhoneNumber(surname);
if (get<0>(answer).empty())
cout << get<1>(answer);
else
cout << get<0>(answer);
cout << endl;
};
// ������ ������
print_phone_number("Ivanov");
print_phone_number("Petrov");
cout << "----ChangePhoneNumber----" << endl;
book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
PhoneNumber{7, 123, "15344458", nullopt});
book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
PhoneNumber{ 16, 465, "9155448", 13 });
cout << book;
}
� ��� ������ ���������� ��������� �����: (��. ��������� ����� 1, ���. 28-29)
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
            cout << "�� ������ ������� ����!" << endl;
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
    // ������ �������, ������� ��������� ������� � ������� ����� �������� ����� ��������, ���� ������
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

    // ������ ������
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person { "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber { 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person { "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber { 16, 465, "9155448", 13 });
    cout << book;

    return 0;
}
