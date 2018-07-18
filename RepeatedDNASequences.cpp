/*
187. Repeated DNA Sequences
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
Example:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC", "CCCCCAAAAA"]

From <https://leetcode.com/problems/repeated-dna-sequences/description/>


*/

class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        if(s == "" || s.length() < 10) {
            return {};
        }
        vector<string> result;
        set<string> mySet,resSet;

        for(int i = 0; i < s.length()-9; i++) {
            string temp = s.substr(i,10);
            if(mySet.find(temp) != mySet.end()) {
                resSet.insert(temp);
            }
            mySet.insert(temp);
        }

        result.assign(resSet.begin(),resSet.end());

        return (result.size() == 0) ? result : result;
    }
};

