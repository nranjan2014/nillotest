#include "Alarmed.cpp"

int main(int argc, char **argv)
{
  int i;
  class Alarmed TheClass;
  double retval;
  vector <int> x;
  vector <int> y;
  vector <int> threshold;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  x = ;
  y = ;
  threshold = ;
*/


 if (atoi(argv[1]) == 0) {
    x.push_back(50);
    y.push_back(2);
    threshold.push_back(87);
  }

 if (atoi(argv[1]) == 1) {
    x.push_back(1);
    x.push_back(99);
    y.push_back(50);
    y.push_back(50);
    threshold.push_back(1);
    threshold.push_back(1);
  }

 if (atoi(argv[1]) == 2) {
    x.push_back(3);
    x.push_back(11);
    x.push_back(2);
    x.push_back(62);
    x.push_back(91);
    y.push_back(90);
    y.push_back(10);
    y.push_back(75);
    y.push_back(25);
    y.push_back(50);
    threshold.push_back(5);
    threshold.push_back(4);
    threshold.push_back(3);
    threshold.push_back(2);
    threshold.push_back(1);
  }

 if (atoi(argv[1]) == 3) {
    x.push_back( 1);
    x.push_back(99);
    y.push_back( 50);
    y.push_back(50);
    threshold.push_back( 1);
    threshold.push_back( 2);
  }

  retval = TheClass.noise(x, y, threshold);
  cout << retval << endl;

  exit(0);
}
