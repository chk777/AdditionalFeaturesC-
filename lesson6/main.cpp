#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <random>
#include "timer.h"

used namespace std;

static mutex mtx_cout;

class pcout
{
private:
    lock_guard<mutex> secp;
public:
    pcout() : secp(lock_guard<mutex>(mtx_cout))
    {
    }

    template<typename T>
    pcout& operator<<(const T &data)
    {
        cout << data;
        return *this;
    }

    pcout& operator<<(ostream& (*fp)(ostream&))
    {
        cout << fp;
        return *this;
    }
};

void doSomething(int number)
{
    pcout() << "start thread " << number << endl;
    pcout() << "stop thread " << number << endl;
}

void task1()
{
    thread th1(doSomething, 1);
    thread th2(doSomething, 2);
    thread th3(doSomething, 3);
    th1.join();
    th2.join();
    th3.join();
}
///////////////////////////////task2//////////////////////////////////////////////////////////////

bool isPrime(size_t num)
{
    size_t limit = num / 2;

    if (num > 2)
    {
        for (size_t i = 2; i <= limit; ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
    }

    return true;
}

void task2()
{

    size_t maxValue = 900000;
    size_t counThreads = 30;
    vector<size_t> answers;
    mutex m;

    Timer timer("With threads");

    for (size_t i = 0; i < maxValue;)
    {
        vector<thread> v;

        for (size_t j = i + counThreads; i <= j; ++i)
        {
            v.push_back(thread([=, &m, &answers]()
            {
                if (isPrime(i))
                {
                    lock_guard lg(m);
                    answers.push_back(i);
                }
            }));
        }

        for (auto &t : v)
        {
            t.join();
        }
    }


    timer.print();

    answers.clear();
    answers.shrink_to_fit();

    timer.start("Without threads");

    for (size_t i = 0; i < maxValue; ++i)
    {
        if (isPrime(i))
        {
            answers.push_back(i);
        }
    }

    timer.print();
}
///////////////////task3/////////////////////////////////////////////////////////////////////

mutex m;

void generate_things(vector<int> &v)
{
    random_device rd;
    mt19937 mersenne(rd());
    uniform_int_distribution<int> urd(0, 1000);

    lock_guard lg(m);

    generate(v.begin(), v.end(), [&]()
    {
        return urd(mersenne);
    });
}

void pop_thing(:vector<int> &v)
{
    lock_guard lg(m);

    cout << *max_element(v.begin(), v.end()) << endl;
}

void task3()
{
    vector<int> v(100);
    size_t count = 100;

    while (count--)
    {
        thread owner([&]()
        {
            generate_things(v);
        });
        thread thief([&]()
        {
            pop_thing(v);
        });

        owner.join();
        thief.join();
    }
}


int main()
{
    task1();
    task2();
    task3();

    return 0;
}
