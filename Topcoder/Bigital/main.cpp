#include "Bigital.cpp"

int main(int argc, char **argv)
{
  int i;
  class Bigital TheClass;
  double retval;
  string tStart;
  string tEnd;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  tStart = ;
  tEnd = ;
*/


 if (atoi(argv[1]) == 0) {
    tStart = "12:00:00";
    tEnd = "12:00:00";
  }

 if (atoi(argv[1]) == 1) {
    tStart = "12:59:59";
    tEnd = "01:00:00";
  }

 if (atoi(argv[1]) == 2) {
    tStart =  "12:01:00";
    tEnd = "12:00:00";
  }

  retval = TheClass.energy(tStart, tEnd);
  cout << retval << endl;

  exit(0);
}
