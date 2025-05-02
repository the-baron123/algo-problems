/*Given an integer array nums and an integer k, return the k most frequent elements within the array.*/
#include <iostream>
#include <vector>
#include <unordered_map>

static std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
	std::vector<int> res;
	std::unordered_map<int, int> Hash;
	int n = nums.size(), i = 0;
	std::vector<std::vector<int>> frequent(n+1);

	for (int i : nums)
	{
		Hash[i]++;
	}
	for (auto i : Hash)
	{
		frequent[i.second].push_back(i.first);
	}

	for (i = n; i >= 0 && k > 0; --i) {
		for (int num : frequent[i]) {
			res.push_back(num);
			if (--k == 0) break;
		}
	}
	return res;
}

int main()
{

}
