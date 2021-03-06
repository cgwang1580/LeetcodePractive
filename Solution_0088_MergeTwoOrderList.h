#include "SolutionBase.h"

#include "ListNode.h"
#include <vector>
#include <stack>
#include <algorithm>

class Solution_0088_MergeTwoOrderList : public SolutionBase
{
public:

    virtual void RunTest()
    {
		std::vector<int> list0{1, 0};
		std::vector<int> list1{2};
		//cg_tool::PrintList(list0, "list0");
		//cg_tool::PrintList(list1, "list1");
		mergeWithList(list0, 1, list1, 1);
		//cg_tool::PrintList(list0, "list res");
    }

    // 使用 list, 时间复杂度为 O(m+n))，空间复杂度为 O(m+n)
	void mergeWithList(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		if (m == 0)
		{
			nums1 = nums2;
			return;
		}

		if (n == 0)
			return;

		size_t index_0 = 0;
		size_t index_1 = 0;
		size_t index_res = 0;

		std::vector<int> resList(m + n);
		do
		{
			if (nums1[index_0] <= nums2[index_1])
			{
				resList[index_res++] = nums1[index_0];
				++index_0;
			}
			else
			{
				resList[index_res++] = nums2[index_1];
				++index_1;
			}

		} while ((index_0 < m) && (index_1 < n));

		if (index_0 < m)
		{
			for (size_t i = index_0; i < m; ++i)
			{
				resList[index_res++] = nums1[i];
			}
		}
		if (index_1 < n)
		{
			for (size_t i = index_1; i < n; ++i)
			{
				resList[index_res++] = nums2[i];
			}
		}

		nums1 = resList;

		return;
	}

	// sort 内部使用快速排序方法，时间复杂度为 O((m+n)*(log(m+n))) 空间复杂度为 O(log(m+n))
	void mergeWithSort(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			nums1[m + i] = nums2[i];
		}
		sort(nums1.begin(), nums1.end());

		return;
	}
};