#include "InternetSecurity.cpp"

int main(int argc, char **argv)
{
  int i;
  class InternetSecurity TheClass;
  vector <string> retval;
  vector <string> address;
  vector <string> keyword;
  vector <string> dangerous;
  int threshold;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  address = ;
  keyword = ;
  dangerous = ;
  threshold = ;
*/


 if (atoi(argv[1]) == 0) {
    address.push_back("www.topcoder.com");
    address.push_back("www.sindicate_of_evil.com");
    address.push_back("www.happy_citizens.com");
    keyword.push_back("hack encryption decryption internet algorithm");
    keyword.push_back("signal interference evil snake poison algorithm");
    keyword.push_back("flower baloon topcoder blue sky sea");
    dangerous.push_back("hack");
    dangerous.push_back("encryption");
    dangerous.push_back("decryption");
    dangerous.push_back("interference");
    dangerous.push_back("signal");
    dangerous.push_back("internet");
    threshold = 3;
  }

 if (atoi(argv[1]) == 1) {
    address.push_back("brokenlink");
    address.push_back("flowerpower.net");
    address.push_back("purchasedomain.com");
    keyword.push_back("broken");
    keyword.push_back("rose tulips");
    keyword.push_back("cheap free domain biggest greatest");
    dangerous.push_back("biggest");
    dangerous.push_back("enemy");
    dangerous.push_back("hideout");
    threshold = 2;
  }

 if (atoi(argv[1]) == 2) {
    address.push_back("a..a.ab.");
    address.push_back("...aa.b");
    keyword.push_back("a bc def");
    keyword.push_back("def ghij klmno");
    dangerous.push_back("a");
    dangerous.push_back("b");
    dangerous.push_back("c");
    dangerous.push_back("d");
    dangerous.push_back("e");
    threshold = 1;
  }

 if (atoi(argv[1]) == 3) {
    address.push_back("www.tsa.gov");
    keyword.push_back("information assurance signal intelligence research");
    dangerous.push_back("signal");
    dangerous.push_back("assurance");
    dangerous.push_back("penguin");
    threshold = 2;
  }

  retval = TheClass.determineWebsite(address, keyword, dangerous, threshold);
  VIT(i, retval) cout << retval[i] << endl;

  exit(0);
}
