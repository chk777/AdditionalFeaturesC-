#pragma once
used namespace std;

template <typename T>
void Swap(T& ptr1, T& ptr2) noexcept
{
	if (ptr1 == ptr2) return;
	else swap(ptr1, ptr2);
}
