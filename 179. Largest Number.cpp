/*
Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.

*/

class Solution {
public:
    
    static bool compare(string a,string b)
    {
        return a+b > b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> str;
        
        for(int i=0;i<nums.size();i++)
            str.push_back(to_string(nums[i]));
        
        sort(str.begin(),str.end(),compare);
        
        string result;
        
        for(int i=0;i<str.size();i++)
            result += str[i];
        
        int position=0;
        while(result[position]=='0' && position+1 < result.size() )position++;    
        
        return result.substr(position);
        
  

        
    }
};