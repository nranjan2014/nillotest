// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
One kind of combination lock often used on bicycles and notebook computers consists of several parallel disks with the digits '0' to '9' printed in order on the outside surface of the disks.  To dial a combination, you turn the disks so that the appropriate digit on each disk lines up with a reference mark.
Each time you turn a disk, you rotate it up to three positions clockwise or counterclockwise.  By grasping several disks with your fingertips, 
you can simultaneously turn up to three adjacent disks by the same amount.  Note that '0' and '9' are adjacent on the disks.



Given the current numbers showing on each disk (as a string) and the desired numbers (also as a string), find the
minimum number of turns needed to dial the desired combination.  For example, if the current numbers are "555" and the desired numbers are "464", then one way to dial the combination would be to turn each disk separately, taking 3 turns altogether.  However, a better way to dial the combination is to turn all three disks simultaneously to "444" and then turn the middle disk by itself to "6", taking 2 turns altogether.


DEFINITION
Class:BikeLock
Method:minTurns
Parameters:string, string
Returns:int
Method signature:int minTurns(string current, string desired)


CONSTRAINTS
-current contains between 3 and 50 characters, inclusive.
-desired is the same length as current.
-current contains only digits ('0'-'9').
-desired contains only digits ('0'-'9').


EXAMPLES

0)
"555"
"464"

Returns: 2

The example above.

1)
"1234"
"3456"

Returns: 2

If you could turn four disks simultaneously, you could do this in 1 turn.  But you can't turn more than three disks at once, so it takes 2 turns.

2)
"06012005"
"06012005"

Returns: 0

3)
"123456789"
"567412490"

Returns: 5

4)
"23887547676234543215443276347856987698648735634265"
"14327805497625497814327632146531429785698765309822"

Returns: 34

// END CUT HERE
#line 67 "BikeLock.cpp"
#include <string>
#include <vector>
class BikeLock {
	public:
	int minTurns(string current, string desired) {
		
	}
};
