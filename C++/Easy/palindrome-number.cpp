#include <string>
#include <iostream>

bool isPalindrome(int x) {
	if (x < 0) return false;
	std::string s = std::to_string(x);
	for (int8_t ss = 0; ss < s.length(); ss++)
		if (s[ss] != s[s.length() - ss - 1])
			return false;

	return true;
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << isPalindrome(121) << std::endl;
	std::cout << isPalindrome(1234) << std::endl;
}