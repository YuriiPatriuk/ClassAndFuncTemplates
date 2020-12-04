#pragma once
#include<iostream>
using namespace std;
template<typename T> //<> - <typename параметр типу> 
inline T maxIntArray(T arr[], size_t size)
{
	T max = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}// шаблон функції = зразок для створення функії

template <>//спеціалізація шаблону
inline char maxIntArray(char arr[], size_t size)
{
	cout << "Specialization of template function\n";
	char max = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (tolower(arr[i]) == tolower(max)) //великі букви більші
		{
			if (isupper(arr[i]))
				max = arr[i];
		}
		else if (tolower(arr[i]) > tolower(max))
			max = arr[i];
			
	}
	return max;
}

inline char maxIntArray(char arr[], size_t size)
{
	cout << "Ordinary function\n";
	char max = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (tolower(arr[i]) > tolower(max)) //порівняння без врахування регістру
			max = arr[i];
	}
	return max;
}



