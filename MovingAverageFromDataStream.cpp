/*
346. Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
Example:
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

From <https://leetcode.com/problems/moving-average-from-data-stream/description/>


*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    int size;
    double sum = 0;
    int n = 0;
    queue<int> myQueue;

    MovingAverage(int size) {
        this->size = size;
    }

    double next(int val) {
        if(myQueue.size() >= size) {
            int temp = myQueue.front();
            cout <<temp << " ";
            myQueue.pop();
            sum -= temp;
            n--;
        }
        myQueue.push(val);
        sum += val;
        n++;
        return sum/n;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

