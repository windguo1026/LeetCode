#include "../problems/Code33_Search_in_Rotated_Sorted_Array.h"
#include <gtest/gtest.h>

#define CODE33_UNIT_TEST 0

#if CODE33_UNIT_TEST

TEST(Code33_Search, UnitTest)
{
	Code33::Solution so;

	// 空数组
	vector<int> nums;
	EXPECT_EQ(-1, so.search(nums, 11));

	// 1个元素
	nums = { 3 };
	EXPECT_EQ(0, so.search(nums, nums[0]));

	// 2个元素
	nums = { 3, 1 };
	EXPECT_EQ(0, so.search(nums, nums[0]));
	EXPECT_EQ(1, so.search(nums, nums[1]));

	// 多个元素
	nums = { 14, 18, 23, 27, 80, 1, 2, 4, 7, 10, 12 };
	EXPECT_EQ(-1, so.search(nums, 0));
	EXPECT_EQ(-1, so.search(nums, 99999));
	EXPECT_EQ(-1, so.search(nums, 99));
	for (int i = 0; i < (int)nums.size(); i ++)
	{
		int ret = so.search(nums, nums[i]);
		EXPECT_EQ(i, ret) << "expIndex " << i
			<< " num "<< nums[i] << " ret " << ret;
	}
}

#endif // CODE33_UNIT_TEST