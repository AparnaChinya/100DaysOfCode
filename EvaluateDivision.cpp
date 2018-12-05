/*
399. Evaluate Division
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].
The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
According to the example above:
equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.


From <https://leetcode.com/problems/evaluate-division/description/>
*/

class Solution {
public:
    double check(string first, string second,unordered_map<string,unordered_map<string,double>> &myMap,unordered_set<string> s) {
        if(myMap[first].find(second) != myMap[first].end()) {
            return myMap[first][second];
        }

        for(auto i : myMap[first]) {
            if(s.find(i.first) == s.end()) {
                s.insert(i.first);
                double temp = check(i.first,second,myMap,s);
                if(temp != 0) {
                    return temp * i.second;
                }
            }
        }
        return 0;
    }


    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string,unordered_map<string,double>> myMap;

        for(int i = 0; i < equations.size(); i++) {
            myMap[equations[i].first].insert(make_pair(equations[i].second,values[i]));
            if(values[i] != 0) {
                myMap[equations[i].second].insert(make_pair(equations[i].first,1/values[i]));
            }
        }
        vector<double> result;
        for(int i = 0; i < queries.size(); i++) {
            unordered_set<string> s;
            double temp = check(queries[i].first, queries[i].second, myMap, s);
            if(temp != 0) {
                result.push_back(temp);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};

