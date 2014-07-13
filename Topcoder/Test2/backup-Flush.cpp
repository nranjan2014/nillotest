// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are playing a card game in which large flushes, or 
// sets of cards of the same suit, are beneficial. Your next 
// move is to draw number cards: the larger the flush you 
// get, the better. You wish to know the expected size of the 
// largest flush in the cards you draw. The deck will consist 
// of some number of cards of four suits, given as suits. The 
// ith element of suits is the number of cards of that suit 
// in the deck. Return a double, the expected size of the 
// largest flush your hand will make.
// 
// The expected size of the largest flush is calculated as 
// follows: For each possible hand, multiply the size of the 
// largest flush in that hand by the probability of getting 
// that hand. Then add all of these values together to get 
// the expected size of the largest flush. For example, if 
// half of the possible hands give you a flush of size 3, and 
// the rest give you one of size 2, the expected value is 
// (0.5 * 3) + (0.5 * 2) = 2.5.  Also, recall that there are 
// n Choose k = n!/k!/(n-k)! ways to select k cards of one 
// suit out of a total of n cards in that suit, where ! 
// denotes the factorial operation.  Thus, if suits = 
// {3,3,3,3}, then there are (3 Choose 3) * (3 Choose 2) * (3 
// Choose 1) * (3 Choose 0) = 1 * 3 * 3 * 1 = 9 ways to get 3 
// cards of the first suit, 2 of the second, 1 of the third, 
// and none of the fourth.
// 
// 
// DEFINITION
// Class:Flush
// Method:size
// Parameters:vector <int>, int
// Returns:double
// Method signature:double size(vector <int> suits, int number)
// 
// 
// NOTES
// -Look out for overflow! A 32-bit datatype may not be large 
// enough.
// -Your return value must have an absolute or relative error 
// less than 1e-9.
// 
// 
// CONSTRAINTS
// -suits will contain exactly four elements.
// -Each element of suits is between 0 and 13, inclusive.
// -number is between 0 and the sum of the elements of suits, 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {2,2,2,2}
// 2
// 
// Returns: 1.1428571428571428
// 
// Draw the first card; you have a 1 out of 7 chance to draw 
// the matching suit for your second card. The expected size 
// is thus (1/7 * 2) + (6/7 * 1) = 8/7 = 1.1428571428571428.
// 
// 1)
// {1,4,7,10}
// 22
// 
// Returns: 10.0
// 
// You are drawing all of the cards, so your largest flush 
// will be of size 10.
// 
// 2)
// {13, 13, 13, 13}
// 49
// 
// Returns: 13.0
// 
// If you get 12 cards of each suit, you must have drawn 48 
// cards, so drawing 49, 50, 51, or 52 cards must give you a 
// flush of size 13.
// 
// 3)
// {13, 13, 13, 13}
// 26
// 
// Returns: 8.351195960938014
// 
// 4)
// {13,13,13,13}
// 0
// 
// Returns: 0.0
// 
// END CUT HERE
#line 97 "Flush.cpp"
#include <string>
#include <vector>
class Flush {
	public:
	double size(vector <int> suits, int number) {
		
	}
};
