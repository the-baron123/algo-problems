#include <iostream>
#include <vector>


std::vector<int> productExceptSelf(std::vector<int>& nums)
{
	int multy = 1, save = 1, i = 0;
	std::vector<int> left, right, mult;

	for (int i : nums)
	{
		multy *= save;
		left.push_back(multy);
		save = i;
	}
	multy = 1;
	save = 1;
	for (i = nums.size() - 1; i >= 0; i--)
	{
		multy *= save;
		right.push_back(multy);
		save = nums.at(i);
	}

	for (i = 0; i < nums.size(); i++)
	{
		mult.push_back(left[i]*right[(nums.size()-1)-i]);
	}

	return mult;
}

int main()
{

}
