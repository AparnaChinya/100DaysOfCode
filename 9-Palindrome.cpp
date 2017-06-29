/* Q

9. Palindrome Number 

Determine whether an integer is a palindrome. Do this without extra space.
click to show spoilers.
Some hints: 
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int res=0;
        int y=x;
        
        while(y)
        {
            res=res*10+y%10;
            y=y/10;
            
           
        }
        
        return (res==x);
        
    }
};