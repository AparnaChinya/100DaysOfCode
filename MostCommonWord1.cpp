/*
819. Most Common Word
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.
 
Example:
Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.
 
Note:
	• 1 <= paragraph.length <= 1000.
	• 1 <= banned.length <= 100.
	• 1 <= banned[i].length <= 10.
	• The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
	• paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
	• There are no hyphens or hyphenated words.
	• Words only consist of letters, never apostrophes or other punctuation symbols.

From <https://leetcode.com/problems/most-common-word/description/>

*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string result = "";
        string midParagraph = "";
        map<string,int> myMap;
        int max = INT_MIN;

        for(auto &item : paragraph) {
            if(!isalpha(item)) {
                item = ' ';
            } else {
                item = tolower(item);
            }
        }
        //cout << paragraph;
        int count = 0;
        int j = 0;
        for(int i = 0; i < paragraph.size(); i++) {
            j = 0;
            while(paragraph[i] != ' ') {
                midParagraph += paragraph[i];
                //cout << paragraph[i];
                i++; j++;
            }
            if(j != 0) {
                //cout<<midParagraph<<endl;
                if(find(banned.begin(),banned.end(),midParagraph) == banned.end()) {
                    myMap[midParagraph]++;
                }
                midParagraph = "";
            }

            count = i;
        }

        for(auto item : myMap) {
            cout << item.first << item.second << " " << max << endl;
            if(max < item.second) {
                max = item.second;
                result = item.first;
            }
        }

        return max == INT_MIN ? 0 : result;

    }
};

