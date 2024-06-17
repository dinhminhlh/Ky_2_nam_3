#include <iostream>
#include <map>

using namespace std;

string arrKey = "";
map<char, int> M;

string createArrKey(string key)
{
	int x = 0, y = 0;

	for (auto c : key)
	{
		if (!M[c])
		{
			arrKey += c;
			if (c == 'J' || c == 'I')
				M['I'] = M['J'] = 1;
			M[c] = 1;
		}
	}

	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (!M[i])
		{
			arrKey += i;
			if (i == 'J' || i == 'I')
				M['I'] = M['J'] = 1;
			M[i] = 1;
		}
	}

	for (int i = 0; i < arrKey.length(); i++)
		M[arrKey[i]] = i;

	return arrKey;
}

string splitLetters(string input)
{
	string s = "";
	s += input[0];
	for (int i = 1; i < input.length(); i++)
	{
		if (input[i] == input[i - 1])
		{
			s += 'X';
		}
		s += input[i];
	}
	if (input.length() % 2)
		s += 'X';

	return s;
}

string PlayFairEncyption(string input, string key)
{
	string output = "";
	for (int i = 0; i < input.length(); i += 2)
	{
		int p1 = M[input[i]];
		int p2 = M[input[i + 1]];
		int row1 = p1 / 5, col1 = p1 % 5;
		int row2 = p2 / 5, col2 = p2 % 5;
		if (row1 == row2)
		{
			col1 = ++col1 % 5;
			col2 = ++col2 % 5;
			output += arrKey[row1 * 5 + col1];
			output += arrKey[row2 * 5 + col2];
		}
		else if (col1 == col2)
		{
			row1 = ++row1 % 5;
			row2 = ++row2 % 5;
			output += arrKey[row1 * 5 + col1];
			output += arrKey[row2 * 5 + col2];
		}
		else
		{
			output += arrKey[row1 * 5 + col2];
			output += arrKey[row2 * 5 + col1];
		}
	}

	return output;
}

int main()
{
	string input, key;

	cout << "Nhap input: ";
	cin >> input;
	cout << "Nhap key: ";
	cin >> key;

	cout << "\nInput: " << input << "\nKey: " << key << endl;

	key = createArrKey(key);
	cout << "\nMa tran khoa Playfair: " << key << endl;

	input = splitLetters(input);

	input = PlayFairEncyption(input, key);
	cout << "\nPlayFair Encyption: " << input << "\n";
}
