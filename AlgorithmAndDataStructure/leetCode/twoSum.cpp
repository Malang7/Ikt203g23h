#include <iostream>
#include <vector>
#include <math.h> 
using namespace std; 

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
    2 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9

*/


class Solution {
public:

    bool lenghtIsgreterThanTo(vector<int>nums)
    {
        if(nums.size()>=2)
        return true; 
        
        else
        return false;
        
    }

    bool lenghtIsLessThanTentousend(vector<int>nums)
    {
        if(nums.size()<= pow(10,4))
        return true;
        else
        return false; 
    }

    bool elementISGreaterThanNegtaiveTenTOPowerOfNine(int num)
    {
        if(num>= pow(-10, 9))
        return true;
        else 
        return false;  
    }

    bool elementISLessThanTenTOPowerOfNine(int num)
    {
        if(num<= pow(10, 9))
        return true;
        else 
        return false;  
    }

    int sum(int a, int b)
    {
        return a+b; 
    }


    void display(vector<int>nums)
    {
        if(nums.empty())
        {
            cout<<"there is not any element in the array."; 
        }

        for(int i = 0; i<nums.size(); i++)
        {
            cout<<nums[i]<<endl;
        }
    }

    vector<int> twoSum(vector<int>& nums, int target)
    {

        vector<int> result; 

        if(lenghtIsgreterThanTo(nums) && elementISGreaterThanNegtaiveTenTOPowerOfNine(target) && elementISLessThanTenTOPowerOfNine(target))
        {
            for (int i = 0; i<nums.size(); i++)
            {
                for(int j = i+1; j<nums.size(); j++)
                {
                    if(elementISGreaterThanNegtaiveTenTOPowerOfNine(nums[i]&&elementISLessThanTenTOPowerOfNine(nums[i])&&
                    elementISGreaterThanNegtaiveTenTOPowerOfNine(nums[j])&&elementISLessThanTenTOPowerOfNine(nums[j])))
                    {
                        if(nums[i] !=nums[j])
                        {
                            if(sum(nums[i],nums[j]) == target)
                            {
                                result.push_back(i);
                                result.push_back(j);
                            }
                        }
                    
                    }
                }
            }
        }
         return result; 

    }
};

//next find other solution for this assignement 

int main()
{
   Solution s1; 

   vector<int> array = {3,3}; 
   int target; 
   cout<<"please enter the target: "; 
   cin>>target; 

   vector<int> result = s1.twoSum(array, target);
   s1.display(result); 


    return 0;  
}
