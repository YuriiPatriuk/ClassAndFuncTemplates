#include <iostream>
#include <string>
#include "Func.h"
using namespace std;

template <typename T1, typename T2>
auto max(const T1& first, const T2& second) //auto - автоматичне визначення типу
{
	return first > second ? first : second;
}

int main()
{
	auto value = 123.45f;
	cout << typeid(value).name() << endl;

	const int SIZE = 5;
	int arr[SIZE]{ 1,2,3,4,5 };
	cout << "Max in array: " << maxIntArray(arr, SIZE) << endl;// компілятор створив функцію
	//T = int
	string fruits[SIZE] = { "apple", "orange", "banana", "cherry", "lemon" };
	cout << "Max in fruits: " << maxIntArray(fruits, SIZE) << endl;
	//t = string

	int i = 102;
	size_t d = 100.5;
	auto result = max(i, d);
	cout << "type of result: " << typeid(result).name() << endl;
	cout << "Max(" << i << ";" << d << "): " << max(i, d) << endl;

	char symbols[SIZE] = { 'a','z','Z','y','m' };
	cout << "Max in symbols array: " << maxIntArray(symbols, SIZE) << endl;// компілятор обере ЗВИЧАЙНУ функцію 
	cout << "Max in symbols array: " << maxIntArray<char>(symbols, SIZE) << endl;// компілятор обере TEMPLATE функцію
	//звичайна функція (має вищий пріоритет)
	//спеціалізація



}

