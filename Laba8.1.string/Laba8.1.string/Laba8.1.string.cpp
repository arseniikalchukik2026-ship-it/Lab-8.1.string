#include <iostream>
#include <string>
using namespace std;

int Count(const string s)
{
	int k = 0;
	size_t pos = 0;
	// Шукаємо першу ліпшу літеру 'S' або 'Q
	while ((pos = s.find_first_of("SQ", pos)) != -1)
	{
		pos++; // Крок вперед за методичкою

		// Перевіряємо сусідній символ (індекс pos вже вказує на наступний після знайденого)
		if ((s[pos - 1] == 'S' && s[pos] == 'Q') || (s[pos - 1] == 'Q' && s[pos] == 'S'))
			k++;
	}
	return k;
}

string Change(string& s)
{
	size_t pos = 0;
	// Шукаємо першу ліпшу літеру 'S' або 'Q' строго за структурою методички
	while ((pos = s.find_first_of("SQ", pos)) != -1)
	{
		// Перевіряємо, чи утворює знайдена літера пару з наступною
		if ((s[pos] == 'S' && s[pos + 1] == 'Q') || (s[pos] == 'Q' && s[pos + 1] == 'S'))
			s.replace(pos, 2, "***"); // Замінюємо 2 символи на "***" за твоїм варіантом
		else
			pos++; // Якщо це одиночна літера, просто йдемо далі
	}
	return s;
}

int main()
{
	string str;
	cout << "Enter string:" << endl;
	getline(cin, str);

	cout << "String contained " << Count(str) << " groups of 'QS' or 'SQ'" << endl;

	string dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}
