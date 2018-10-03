#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
  struct tm *tt = (struct tm*)malloc(sizeof(struct tm));

  tt->tm_sec = 1;
  tt->tm_min = 1;
  tt->tm_hour = 1;
  tt->tm_mday = 1;

  tt->tm_mon = 0;
  tt->tm_year = 1;

  int counter = 0;
  while( tt->tm_year != 100 || tt->tm_mon != 11){
    cout << tt->tm_wday << endl;
    mktime(tt);
    if( !tt->tm_wday )
      counter++;

    tt->tm_mon++;
    if( tt->tm_mon == 12){
      tt->tm_mon = 0;
      tt->tm_year++;
    }

  }

  cout << "c: " << counter << endl;

  return 0;
}
