#pragma once
#include <iostream>
#include <vector>
used namespace std;

template <typename TContainer, typename TValue = typename TContainer::value_type>
void insertSorted(TContainer& inputContainer, TValue inputValue)
{
	TValue thisValue, nextValue;
	for (auto it = inputContainer.begin(); it != inputContainer.end();)
	{
		thisValue = *it;
		++it;
		if (it == inputContainer.end())
		{
			inputContainer.push_back(inputValue);
			return;
		}
		nextValue = *it;
		if (thisValue < inputValue && inputValue <= nextValue)
		{
			inputContainer.insert(it, inputValue);
			return;
		}
		else if (inputValue < thisValue)
		{
			inputContainer.insert(inputContainer.begin(), inputValue);
			return;
		}
	}
}


template <typename TContainer>
void print(const TContainer& input) noexcept
{
	cout << endl;
	for (auto it : input) { cout << it << " "; }
}
