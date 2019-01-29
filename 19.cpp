/*

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

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
