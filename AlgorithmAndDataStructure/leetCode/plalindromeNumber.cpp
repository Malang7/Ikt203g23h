#include <iostream>
#include <math.h>
#include <string>


using namespace std; 



/*
Given an integer x, return true if x is a
palindrome
, and false otherwise.

 

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:

    -231 <= x <= 231 - 1
*/



class Solution {
public:


    bool isWithInRange(int x)
    {
        if(x>=pow(-2, 31) && x<=pow(2,31))
        return true; 
        else
        return false; 
    }


    string fromTheRightToLeft (int  x)
    {

        if(!isWithInRange(x))
        {
            throw runtime_error("the number is out of the range"); 
        }

        string num = to_string(x); //convert to a string 
        string result; 
        int numResult;  
        int start = num.length()-1;  //starting from the last elemnet in the string  

        for(int i = start; i>=0; i--) 
        {
            result.push_back(num[i]); //append the result to the result string 
        }
        numResult = stoi(result); //convert the string to the integer and return it 
        return result;   
    }

    bool isPalindrome(int x)
    {



        if(!isWithInRange(x))
        {
            return false; 
        }
        

        string num  = to_string(x);     //convert the interger to the string, it would be easier to find the lenght of the digit
        
        int start = 0;  //start compering from the first digit on the left side 
        int end = num.length(); // the second variable start from the riaght side of the digit
 
        int middel = (start + end)/2;    //both left and right side will continue to reach the middle     


        bool check= false;   //a boolen variable to check if the element is palindorom or not 

        while(start<=middel && end >= middel)  //looping through the string until start and the end meet at the middel 
        {
            if(num[start] == num[end-1]) //check if the left side is equal to the right side 
            {
                check = true;       //the boolen variable come true 
                start++;        //increment the start 
                end--;           //decrement the end 
            }
            else   //otherwise, the check become false, and the loop breaks 
            {
                check = false; 
                break; 
            }

        }
       return check;   
    }
};





int main ()
{
    Solution s1;

    int num; 
    cout<<"Enter a number to check if the number is palindrom or not: "; 
    cin>>num; 
    if (!num)
    {
        cout<<"invalid input.";
    }
    else
    {
        bool check  = s1.isPalindrome(num);
        string fromRaightToLeft = s1.fromTheRightToLeft(num); 

        if (check)
        {
            cout<<num<<"reads as "<<fromRaightToLeft<< " from left to right and from right to left."; 
        }
        else
        {
            cout<<"From left to right, it reads "<<num<< " From right to left, it becomes "<< fromRaightToLeft<<". Therefore it is not a palindrome."; 
        }
    }
 

    



    return 0; 
}

