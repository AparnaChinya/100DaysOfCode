/*Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
Example 1:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:
Input: [[7,10],[2,4]]
Output: 1
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
      //need an ordered map
      map<int,int> myMap;
      int rooms = 0;
      int minimum = INT_MIN;
      //O(n) Time and O(n) space
      //Use map and store count of start and end time
      for(auto item : intervals) {
          myMap[item.start] += 1;
          myMap[item.end] -= 1;
        }
      
      //Count the minimum number of rooms required at any point
      for(auto item : myMap) {
        cout<< item.first << item.second << endl;
        minimum = max(minimum, rooms+=item.second);
      }
      
      return minimum == INT_MIN ? 0 : minimum;
    }
};
