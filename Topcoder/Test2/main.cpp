#include "SandTimers.cpp"

int main(int argc, char **argv)
{
  int i;
  class SandTimers TheClass;
  vector <int> retval;
  vector <int> timers;
  int maxInterval;
  int maxTime;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  timers = ;
  maxInterval = ;
  maxTime = ;
*/


 if (atoi(argv[1]) == 0) {
    timers.push_back( 5);
    timers.push_back( 7 );
    maxInterval = 10;
    maxTime = 10;
  }

 if (atoi(argv[1]) == 1) {
    timers.push_back( 2);
    timers.push_back( 10);
    timers.push_back( 20 );
    maxInterval = 30;
    maxTime = 40;
  }

 if (atoi(argv[1]) == 2) {
    timers.push_back( 2);
    timers.push_back( 5);
    timers.push_back( 9 );
    maxInterval = 360;
    maxTime = 360;
  }

 if (atoi(argv[1]) == 3) {
    timers.push_back( 4 );
    maxInterval = 23;
    maxTime = 47;
  }

 if (atoi(argv[1]) == 4) {
    timers.push_back( 20);
    timers.push_back( 13 );
    maxInterval = 30;
    maxTime = 30;
  }

 if (atoi(argv[1]) == 5) {
    timers.push_back( 20);
    timers.push_back( 17);
    timers.push_back( 13 );
    maxInterval = 25;
    maxTime = 30;
  }

  retval = TheClass.badIntervals(timers, maxInterval, maxTime);
  VIT(i, retval) cout << retval[i] << endl;

  exit(0);
}
