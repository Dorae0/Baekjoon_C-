#include <iostream>
#include <string>
#include <vector>
#define MAX 50

using namespace std;

enum calculateType {
	L,
	R,
	P,
	ALL,
};

string s;
vector<int> ans;
vector<int> ansCount;

void init();
void SearchTree();
vector<int> CalculateBigNum(vector<int> number, int calculateType);

int main()
{
	init();
	SearchTree();
	return 0;
}


void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
	ans.push_back(1);
	ansCount.push_back(1);
}

void SearchTree()
{
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case 'L' : 
			ans = CalculateBigNum(ans, L);
			break;
		case 'R' : 
			ans = CalculateBigNum(ans, R);
			break;
		case 'P' : 
			ans = CalculateBigNum(ans, P);
			break;
		case '*' : 
			ans = CalculateBigNum(ans, ALL);
			break;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
}

vector<int> CalculateBigNum(vector<int> number, int calculateType)
{
	int carry = 0;
	int count = 0;
	vector<int> ret;
	switch (calculateType)
	{
	case R:
		carry = 0;
		for (int i = 0; i < ans.size(); i++)
		{
			ret.push_back((ans[i] * 2 + carry) % 10);
			carry = (ans[i] * 2 + carry) / 10;
		}
		if (carry != 0) ret.push_back(carry);
		carry = 0;
		count = 0;
		while (carry != 0 || count < ansCount.size())
		{
			int retVal = 0;
			int ansCVal = 0;
			if (count < ret.size())
				retVal = ret[count];
			if (count < ansCount.size())
				ansCVal = ansCount[count];
			if (count < ret.size())
				ret[count] = ((retVal + ansCVal + carry) % 10);
			else
				ret.push_back((ansCVal + carry) % 10);
			carry = (retVal + ansCVal + carry) / 10;
			count++;
		}
		break;
	case L:
		carry = 0;
		for (int i = 0; i < ans.size(); i++)
		{
			ret.push_back((ans[i] * 2 + carry) % 10);
			carry = (ans[i] * 2 + carry) / 10;
		}
		if (carry != 0) ret.push_back(carry);
		break;
	case P:
		ret = ans;
		break;
	case ALL:
		carry = 0;
		for (int i = 0; i < ans.size(); i++)
		{
			ret.push_back((ans[i] * 5 + carry) % 10);
			carry = (ans[i] * 5 + carry) / 10;
		}
		if (carry != 0) ret.push_back(carry);
		carry = 0;
		count = 0;
		while (carry != 0 || count < ansCount.size())
		{
			int retVal = 0;
			int ansCVal = 0;
			if (count < ret.size())
				retVal = ret[count];
			if (count < ansCount.size())
				ansCVal = ansCount[count];
			if (count < ret.size())
				ret[count] = ((retVal + ansCVal + carry) % 10);
			else
				ret.push_back((ansCVal + carry) % 10);
			carry = (retVal + ansCVal + carry) / 10;
			count++;
		}
		count = 0;
		carry = 0;
		while (carry != 0 || count < ansCount.size())
		{
			int ansCVal = 0;
			if (count < ansCount.size())
				ansCVal = ansCount[count];
			if (count < ansCount.size())
				ansCount[count] = ((ansCVal * 3 + carry) % 10);
			else
				ansCount.push_back((ansCVal * 3 + carry) % 10);
			carry = (ansCVal * 3 + carry) / 10;
			count++;
		}
	}
	return ret;
}

// L : ans * 2;
// R : ans * 2 + (현재 답의 종류)
// P : ans * 1;
// ALL : ans * 5 + (현재 답의 종류)