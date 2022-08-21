#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
used namespace std;

void countVowels1()
{
	auto start = chrono::high_resolution_clock::now();

	ifstream file("war-and-peace.txt");
	if (!file.is_open())
	{
		cout << "Could not read the file!" << endl;
		return;
	}

	string vowels = "AEIOUYaeiouy";

	size_t count = count_if(istreambuf_iterator<char>(file),istreambuf_iterator<char>(),[=](char x){return vowels.find(x) != string::npos;});
	file.close();

	auto finish = chrono::high_resolution_clock::now();
	auto result = chrono::duration_cast<chrono::milliseconds>(finish - start);
	cout << "(Count_if + find) took " << result.count() << " milliseconds.\n";
	cout << "Number of vowels: " << count << endl;
}


void countVowels2()
{
	auto start = chrono::high_resolution_clock::now();

	ifstream file("war-and-peace.txt");
	if (!file.is_open())
	{
		:cout << "Could not read the file!" << endl;
		return;
	}

	string vowels = "AEIOUYaeiouy";

	size_t count = count_if(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), [=](char x) -> bool {for (auto chr : vowels) { if (chr == x) return true; } return false;});
	file.close();

	auto finish = chrono::high_resolution_clock::now();
	auto result = chrono::duration_cast<chrono::milliseconds>(finish - start);
	cout << "(Count_if + for) took " << result.count() << " milliseconds.\n";
	cout << "Number of vowels: " << count << endl;
}

void countVowels3()
{
	auto start = chrono::high_resolution_clock::now();

	ifstream file("war-and-peace.txt");
	if (!file.is_open())
	{
		cout << "Could not read the file!" << endl;
		return;
	}

	string vowels = "AEIOUYaeiouy";
	size_t count = 0;

	for (auto it = istreambuf_iterator<char>(file); it != istreambuf_iterator<char>(); ++it)
	{
		if (vowels.find(*it) != string::npos) ++count;
	}

	file.close();

	auto finish = chrono::high_resolution_clock::now();
	auto result = chrono::duration_cast<chrono::milliseconds>(finish - start);
	cout << "(For + find) took " << result.count() << " milliseconds.\n";
	cout << "Number of vowels: " << count << endl;
}

void countVowels4()
{
	auto start = chrono::high_resolution_clock::now();

	ifstream file("war-and-peace.txt");
	if (!file.is_open())
	{
		cout << "Could not read the file!" << endl;
		return;
	}

	string vowels = "AEIOUYaeiouy";
	size_t count = 0;

	for (auto it = istreambuf_iterator<char>(file); it != istreambuf_iterator<char>(); ++it)
	{
		for (char chr : vowels)
		{
			if (*it == chr && *it != string::npos) ++count;
		}
	}

	file.close();

	auto finish = chrono::high_resolution_clock::now();
	auto result = chrono::duration_cast<chrono::milliseconds>(finish - start);
	cout << "(For + for) took " << result.count() << " milliseconds.\n";
	cout << "Number of vowels: " << count << endl;
}
