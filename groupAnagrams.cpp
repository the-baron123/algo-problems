/*
Given an array of strings strs, group all anagrams together into sublists.
You may return the output in any order.
An anagram is a string that contains the exact same characters as another string,
but the order of the characters can be different.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
/*slower solution but still more uniqe(in my opinion at least)*/
static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
	std::vector<std::vector<std::string>> res;
	std::map<std::map<char, int>, std::vector<std::string>> groups;//hold the groups of anagrams by index to put in the answer after
	std::map<char, int> MapForWord;

	for (std::string word : strs)
	{
		for (char c : word)
		{
			MapForWord[c]++;
		}
		groups[MapForWord].push_back(word);
		MapForWord.clear();
	}
	for (auto& entry : groups)
	{
		res.push_back(std::move(entry.second));
	}
	return res;
}

/*second solution faster and more simple but still not optimal I could'nt understand the idea :( */
static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
	std::unordered_map<std::string, std::vector<std::string>> res;
	for (const auto& s : strs) {
		std::string sortedS = s;
		sort(sortedS.begin(), sortedS.end());
		res[sortedS].push_back(s);
	}
	std::vector<std::vector<std::string>> result;
	for (auto& pair : res) {
		result.push_back(pair.second);
	}
	return result;
}
int main()
{

}