// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Sigh...  If only the king could make up his mind.  First he wanted rounds in the Royal Wrestling Tournament to last for 2 minutes, then he changed his mind to 3 minutes.  He wanted periods in the Royal Hockey Tournament to last for 20 minutes, then he decided on 15.  Your job as the Royal Time Keeper would be much easier if he would buy you a modern stopwatch, but he insists that you use the Royal Sand Timers, which have been in his family since the 14th century.  You're worried that someday he is going to ask you to measure a time interval that simply can't be measured with the timers you have available.



Given a vector <int> timers of the times that each of your timers can measure, you want to determine which integral intervals between 1 minute
and maxInterval minutes (inclusive) cannot be measured.  
You always begin with all the sand in the bottom of your timers.  You turn over some or all of
your timers and the sand begins to fall.  Whenever the sand runs out of a timer, you can again turn over some timers.  You yell "Start" when you turn
over some timer and "Stop" when the sand runs out of some timer.  The time between the yells is the interval you are measuring.  Because the king's
patience is limited, you must yell "Stop" no later than maxTime minutes after turning over the first sand timer.



For example, if you had a 5-minute timer and a 7-minute timer, you could easily measure intervals of 5, 7, and 10 minutes.  With a little more trouble you can measure intervals of 2, 3, 4, and 9 minutes.  To measure 4 minutes, you start by flipping over both timers.  When the 5-minute timer runs out, you flip it over and yell "Start", leaving the 7-minute timer running.  When the 7-minute timer runs out two minutes later, you again flip over the 5-minute timer, which
has been running for two minutes.  The 5-minute timer runs out two minutes later, and you yell "Stop".  However, no matter how you try, you cannot
find a way to measure 1, 6, or 8 minutes, assuming the king's patience is limited to 10 minutes. 



You will return a vector <int> of the intervals you cannot measure, arranged in increasing order.
Note that, after years of training, you are able to turn over a sand timer instantaneously.
However, tradition forbids you to ever lay a sand timer on its side.



DEFINITION
Class:SandTimers
Method:badIntervals
Parameters:vector <int>, int, int
Returns:vector <int>
Method signature:vector <int> badIntervals(vector <int> timers, int maxInterval, int maxTime)


CONSTRAINTS
-timers contains between 1 and 3 elements, inclusive.
-Each element of timers is between 1 and 20, inclusive.
-maxInterval is between 1 and 360, inclusive.
-maxTime is between 1 and 360, inclusive.
-maxInterval is no greater than maxTime.


EXAMPLES

0)
{ 5, 7 }
10
10

Returns: {1, 6, 8 }

The example above.

1)
{ 2, 10, 20 }
30
40

Returns: {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29 }

All your timers are even, so you can't measure an odd number of minutes.

2)
{ 2, 5, 9 }
360
360

Returns: { }

You can measure all possible intervals.

3)
{ 4 }
23
47

Returns: {1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15, 17, 18, 19, 21, 22, 23 }

4)
{ 20, 13 }
30
30

Returns: {1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 28, 29, 30 }

5)
{ 20, 17, 13 }
25
30

Returns: {18, 19 }

// END CUT HERE
#line 97 "SandTimers.cpp"
#include <string>
#include <vector>
class SandTimers {
	public:
	vector <int> badIntervals(vector <int> timers, int maxInterval, int maxTime) {
		
	}
};
