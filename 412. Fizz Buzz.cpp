
/*
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> mystring(n);
        
			for (int l = 1; l <= n; l++)
			{
				if ((l % 3) == 0 && (l % 5) == 0)
				{
					mystring[l-1]="FizzBuzz";
				}
				else

					if (l % 3 == 0)
					{
						mystring[l-1]= "Fizz";
					}
					else
						if (l % 5 == 0)
						{
							mystring[l-1]="Buzz";
						}
						else
						{
							mystring[l-1]= to_string(l);
						}

			}
        return mystring;

    }
};