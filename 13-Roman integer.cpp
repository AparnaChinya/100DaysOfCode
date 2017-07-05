/*
Q:https://leetcode.com/problems/roman-to-integer/#/description
13-Roman integer
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
   int romanToInt(string s) {

	map<char, int> map;
	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;

	int count = 0;
	int Sum = 0;

	for (int i = 0; i < s.size(); i++)
	{
		
		if (s[i] == s[i + 1])
		{	
			count++;
			if (count <= 3)
			{
			Sum += map[s[i]];
			}
			else
			{
				Sum += map[s[i + 1]] - map[s[i]]; i++;
			}
		}
		else 
			if (map[s[i]] < map[s[i + 1]])
			{
				Sum += map[s[i + 1]] - map[s[i]]; i++;
			}
			else
		{
			Sum += map[s[i]];
			count = 0;
		}
			
				
	}

	return Sum;
	
}
};