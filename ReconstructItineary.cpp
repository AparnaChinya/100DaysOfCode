/*
332. Reconstruct Itinerary
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
Note:
	1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
	2. All airports are represented by three capital letters (IATA code).
	3. You may assume all tickets form at least one valid itinerary.
Example 1:
Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.

From <https://leetcode.com/problems/reconstruct-itinerary/description/>


*/

class Solution {
public:
    void helper(string airport, vector<pair<string, string>> tickets,map<string,multiset<string>> &myMap,vector<string> &result) {
        while(myMap[airport].size()) {
            string temp = *myMap[airport].begin();
            myMap[airport].erase(myMap[airport].begin());
            helper(temp,tickets,myMap,result);
        }
        result.push_back(airport);
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string,multiset<string>> myMap;
        vector<string> result;

        for(int i = 0; i < tickets.size(); i++) {
            myMap[tickets[i].first].insert(tickets[i].second);
        }
        helper("JFK", tickets, myMap, result);
        reverse(result.begin(),result.end());
        return result;
    }
};

