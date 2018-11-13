/*65. Valid Number
Validate if a given string can be interpreted as a decimal number.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
	• Numbers 0-9
	• Exponent - "e"
	• Positive/negative sign - "+"/"-"
	• Decimal point - "."
Of course, the context of these characters also matters in the input.
Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

From <https://leetcode.com/problems/valid-number/description/>
*/

class Solution {
public:
    bool isNumber(string s) {
        bool numberSeen = false;
        bool numberAfterE = true;
        bool pointSeen = false;
        bool eSeen = false;

        int start = 0;
        //Trim leading spce
        while(s[start] == ' ') {
            start++;
        }
        //Trim ending space
        int end = s.size()-1;
        while(s[end] == ' ') {
            end--;
        }

        for(int i = start; i <= end; i++) {

            //If number seen
            if(s[i] >= '0' && s[i] <= '9') {
                cout << s[i];
                numberSeen = true;
                numberAfterE = true;
            }
                //If . seen
            else if(s[i] == '.') {
                cout << s[i];
                if(pointSeen || eSeen) {
                    return false;
                }
                pointSeen = true;
            }
                //if E seen
            else if(s[i] == 'e') {
                cout << i;
                if(eSeen || !numberSeen) {
                    return false;
                }
                cout << s[i];
                eSeen = true;
                numberAfterE = false;
            }
                //+ - seen
            else if(s[i] == '+' || s[i] == '-') {
                if(i != start && s[i-1] != 'e') {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return numberSeen && numberAfterE;
    }
};

