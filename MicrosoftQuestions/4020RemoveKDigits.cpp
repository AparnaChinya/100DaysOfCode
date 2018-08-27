/*402. Remove K Digits 
 

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.  

Note: 
 

The length of num is less than 10002 and will be ≥ k. 

The given num does not contain any leading zero. 

Example 1:  

Input: num = "1432219", k = 3 Output: "1219" Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.  

Example 2:  

Input: num = "10200", k = 1 Output: "200" Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.  

*/ 

 

class Solution { 

public: 

    string removeKdigits(string num, int k) { 

        deque<char> myQueue; 

        string result = ""; 

        int totalLength = num.size()-k; 

        //Use Deque for the solutoin 

         

        //If total length of k is the size of the tring 

        if(num.size() == 0 || num.size() == k) { 

            return "0"; 

        } 

        //Put just the lowest numbers in the queue until you have removed k elements 

        for(int i=0; i < num.size(); i++) { 

            while(!myQueue.empty() && k && num[i] < myQueue.back()) { 

                k--; 

                myQueue.pop_back(); 

            } 

            myQueue.push_back(num[i]); 

        } 

        //REmove leading 0's 

        while(!myQueue.empty() && myQueue.front() == '0'){ 

            myQueue.pop_front(); 

            totalLength--; 

        } 

        //Pop from the front of the queue until you get the required size 

         while(!myQueue.empty() && totalLength > 0){ 

            result += myQueue.front(); 

            myQueue.pop_front(); 

             totalLength--; 

        } 

         

        return result == "" ? "0" : result; 

    } 

}; 
