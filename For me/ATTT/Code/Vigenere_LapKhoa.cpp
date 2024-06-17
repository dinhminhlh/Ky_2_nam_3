#include <iostream>
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string repeatKey(string input, string key)
{
	string newKey = key;
	int length = input.length();

	while (newKey.length() < length)
	{
		for (int i = 0; i < key.length(); i++)
		{
			newKey += key[i];
			if (newKey.length() == length)
				break;
		}
	}

	return newKey;
}

int position(char c)
{
	if (c > 'Z')
		return c - 'a';
	return c - 'A';
}

string VigenereEncryption(string input, string key)
{
	string cipher = "";
	int p, k, c, m = input.length();

	for (int i = 0; i < input.length(); i++)
	{
		p = position(input[i]);
		k = position(key[i % m]);
		c = (p + k) % 26;
		cipher += alphabet[c];
	}

	return cipher;
}

int main()
{
	string input, k, key;
	int length;

	cout << "Nhap input: ";
	cin >> input;
	cout << "Nhap key: ";
	cin >> key;

	cout << "Input: " << input << "\nKey: " << key << endl;

	string newKey;
	newKey = repeatKey(input, key);

	cout << "New Key: " << newKey << endl;

	string res = VigenereEncryption(input, newKey);

	cout << "Vigenere Encryption: " << res << endl;
}
