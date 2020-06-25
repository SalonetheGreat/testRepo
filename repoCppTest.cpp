#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdint>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int start = 0, end = nums.size()-1, middle;
    	if (nums.empty())
    		return 0;
    	if (nums.size() == 1) {
    		if (nums[0] < target)
    			return 1;
    		return 0;
    	}

    	// >2 elements
    	while (1) {
    		middle = (start+end)/2;
    		if (nums[middle] == target)
    			return middle;
    		if (end-start == 1) {
    			if (nums[start] > target)
    				return start;
    			if (nums[end] < target)
    				return end+1;
    			return end; 
    		}

    		if (nums[middle] < target) {
    			// target should on RHS (may include middle)
    			start = middle;
    		}
    		else {
    			// target should on LHS (may include middle)
    			end = middle;
    		}
    	}
    }
};