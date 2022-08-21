#pragma once
template <typename T>
void Swap(T& ptr1, T& ptr2) noexcept
{
	if (ptr1 == ptr2) return;
	else std::swap(ptr1, ptr2);

}
