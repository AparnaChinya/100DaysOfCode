/*
93. Restore IP Addresses
DescriptionHintsSubmissionsDiscussSolution
Pick One

Given a string containing only digits, restore it by returning all possible valid IP address combinations.
Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

From <https://leetcode.com/problems/restore-ip-addresses/description/>

*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ans;
        cout << s << endl;
        for(int a = 1; a <=3; a++) {
            for(int b = 1; b <=3; b++) {
                for(int c = 1; c <=3; c++) {
                    for(int d = 1; d <=3; d++) {
                        if(a+b+c+d == s.length()) {
                            cout << a << b << c << d <<endl;

                            int A = stoi(s.substr(0,a));
                            int B = stoi(s.substr(a,b));
                            int C = stoi(s.substr(a+b,c));
                            int D = stoi(s.substr(a+b+c,d));
                            cout << A <<" "<< B <<" "<< C <<" "<< D <<endl;

                            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                                ans = to_string(A)+ "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                                if(ans.length() == s.length() + 3) {
                                    result.push_back(ans);
                                }
                            }

                        }

                    }
                }
            }
        }

        return result;
    }
};

