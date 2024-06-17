#include <iostream>
#include <map>

using namespace std;

map<char, char> M;

void reverKey(string key)
{
	int d = 0;
	for (char i = 'A'; i <= 'Z'; i++)
		M[i] = key[d++];
}

string monoalphabeticEncyption(string input, string key)
{
	reverKey(key);
	string output = "";
	for (int i = 0; i < input.length(); i++)
		output += M[input[i]];
	return output;
}

bool checkKey(string key)
{
	if (key.length() != 26)
		return false;
	map<char, bool> check;
	for (int i = 0; i < key.length(); i++)
	{
		if (check[key[i]] == false)
		{
			check[key[i]] = true;
		}
		else if (check[key[i]] == true)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string input, key, res = "";

	cout << "Nhap input: ";
	cin >> input;
	cout << "Nhap key: ";
	cin >> key;

	if (checkKey(key) == false)
	{
		cout << "Key khong hop le";
		return 0;
	}

	cout << "\nInput: " << input << "\nKey: " << key << endl;

	res = monoalphabeticEncyption(input, key);
	cout << "\nMonoAlphabetic Encyption: " << res << endl;
}
