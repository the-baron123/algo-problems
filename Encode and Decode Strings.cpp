/*   Design an algorithm to encode a list of strings to a single string.
 *  The encoded string is then decoded back to the original list of strings.
 */
#include <iostream>
#include <vector>
#include <string>

std::string encode(std::vector<std::string>& strs) {
	std::string ans = "";
	for (std::string str : strs)
	{
		ans += std::to_string(str.length());
		ans += "#"+str;
	}
	return ans;
}

std::vector<std::string> decode(std::string s) {
	int len = 0, index = 0;
	std::vector<std::string> ans;
	if (s.length() == 0)
	{
		return ans;
	}
	while (true)
	{
		index = 0;
		for (char ch : s)
		{
			if (ch == '#')
				break;
			index++;
		}
		len = std::stoi(s.substr(0, index));
		ans.push_back(s.substr(index + 1, len));
		s = s.substr(len + index + 1);
		if (s.length() == 0)
		{
			break;
		}
	}
	return ans;
}


int main()
{

}