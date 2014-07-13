// BEGIN CUT HERE
// PROBLEM STATEMENT
// The distance between two strings with respect to a letter is defined as (n1 - n2)2, where n1 and n2 are the number of occurrences (both lowercase and uppercase) of that letter in the first and second strings, respectively.  The distance between two strings with respect to a third string is the sum of the distances between the two strings with respect to each letter in the third string.

You will be given three Strings a, b and letterSet.  All the letters in letterSet will be distinct. Return the distance between a and b with respect to letterSet.

DEFINITION
Class:DistanceBetweenStrings
Method:getDistance
Parameters:String, String, String
Returns:int
Method signature:int getDistance(String a, String b, String letterSet)


CONSTRAINTS
-a will contain between 1 and 50 characters, inclusive.
-a will contain only letters ('a'-'z', 'A'-'Z').
-b will contain between 1 and 50 characters, inclusive.
-b will contain only letters ('a'-'z', 'A'-'Z').
-letterSet will contain between 1 and 26 characters, inclusive.
-letterSet will contain only lowercase letters ('a'-'z').
-Each character in letterSet will be distinct.


EXAMPLES

0)
"topcoder"
"contest"
"tcp"

Returns: 2

The letter 't' occurs once in the first string and twice in the second; the letter 'c' occurs once in the first string and once in the second; the letter 'p' occurs once in the first string and does not occur in the second one. The total distance is 1+0+1=2.

1)
"abcdef"
"fedcba"
"fed"

Returns: 0

The second string is a permutation of the letters in the first one thus the distance is 0.

2)
"aaaaa"
"bbbbb"
"a"

Returns: 25

The distance with respect to a single character in this case is 5*5=25.

3)
"aaAaB"
"BbaAa"
"ab"

Returns: 2

Lowercase and uppercase letters are regarded the same.

4)
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
"ba"

Returns: 5000

These two strings are quite far away.

5)
"ToPcOdEr"
"tOpCoDeR"
"wxyz"

Returns: 0



// END CUT HERE
import java.util.*;
public class DistanceBetweenStrings {
	public int getDistance(String a, String b, String letterSet) {
		
	}
	public static void main(String[] args) {
		DistanceBetweenStrings temp = new DistanceBetweenStrings();
		System.out.println(temp.getDistance(String a, String b, String letterSet));
	}
}
