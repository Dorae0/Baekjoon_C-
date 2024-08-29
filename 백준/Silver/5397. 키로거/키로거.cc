#include <iostream>
#include <string>
#include <list>

#define MAX (int)1e6

using namespace std;

long long n;
string s;
list<char> li;
list<char>::iterator position = li.begin();

void Init();
void Keylogger();
void move(char c);
void delete_char();
void add_char(char c);
void Print();

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		Init();
		Keylogger();
		Print();
	}
}

void Init()
{
	cin >> s;
	li.clear();
	position = li.begin();
}

void Keylogger()
{
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '<':
		case '>':
			move(s[i]);
			break;
		case '-':
			delete_char();
			break;
		default:
			add_char(s[i]);
			break;
		}
	}
}

void move(char c)
{
	switch (c)
	{
	case '<':
		if(position != li.begin())
			position--;
		break;
	case '>':
		if (position != li.end())
			position++;
		break;
	}
}

void delete_char()
{
	if (position != li.begin())
	{
		position = li.erase(--position);
	}
}

void add_char(char c)
{
	li.insert(position, c);
}

void Print()
{
	for (auto i : li)
		cout << i;
	cout << '\n';
}