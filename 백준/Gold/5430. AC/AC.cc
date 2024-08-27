#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int t, n;
string p, x;
bool frontback = true;

deque<int> dq;

void dequeInit();
bool Execute();
void Reverse();
bool Discard();
void Print();
bool IsNum(char c);

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		frontback = true;
		cin >> p >> n;
		cin >> x;
		dequeInit();
		if (Execute())
			Print();

		else
			cout << "error";
		cout << '\n';
	}
}

void dequeInit()
{
	int left_iter = 1;
	int right_iter = 1;
	while (right_iter < x.size())
	{
		if (x == "[]")
			break;
		if (!IsNum(x[right_iter]))
		{
			string temp_s = x.substr(left_iter, right_iter - left_iter);
			dq.push_back(stoi(temp_s));
			left_iter = right_iter + 1;
		}
		right_iter++;
	}
}


bool IsNum(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

bool Execute()
{
	Reverse();
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == 'R')
			Reverse();
		else
			if (!Discard())
				return false;
	}
	return true;
}

void Reverse()
{
	if (frontback)
		frontback = false;
	else
		frontback = true;
}

bool Discard()
{
	if (dq.empty())
		return false;

	if (frontback)
		dq.pop_back();
	else
		dq.pop_front();
	return true;
}

void Print()
{
	cout << '[';
	while (!dq.empty())
	{
		if (frontback)
		{
			cout << dq.back();
			dq.pop_back();
			if (!dq.empty())
				cout << ',';
		}
		else
		{
			cout << dq.front();
			dq.pop_front();
			if (!dq.empty())
				cout << ',';
		}

	}
	cout << ']';
}