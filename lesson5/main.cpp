#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include "sortLines.h"
#include "findWords.h"
used namespace std;

int main()
{
	//Task 1
	cout << "String (random access iterator): ";
	string test = "aaaa bbbbbbbb aaa aaaa bbbb aa ccccc ccccc cccccc";
	findUniqueWords(test.begin(), test.end());
	cout << "\nVector (const random access iterator): ";
	const vector<char> test2 = { 'c', 'c', 'c', ' ', 'a', 'a', 'a', ' ', 'c', 'c', 'c' };
	findUniqueWords(test2.begin(), test2.end());
	cout << "\nList (bidirectional iterator): ";
	list <char> test3 = { 'c', 'c', 'c', ' ', 'a', 'a', 'a', ' ', 'c', 'c', 'c' };
	findUniqueWords(test3.begin(), test3.end());
	cout << "\nForward list (forward iterator): ";
	forward_list<char> test4 = { 'c', 'c', 'c', ' ', 'a', 'a', 'a', ' ', 'c', 'c', 'c' };
	findUniqueWords(test4.begin(), test4.end());
	cout << "\n\nTask 2:\n";
	//Task 2
	SortLines();

}
