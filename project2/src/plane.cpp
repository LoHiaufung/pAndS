
#include "plane.hpp"
#include <iostream>

using namespace std;

 Plane::Plane(int fit, int time, Plane_status status)
 /* Post: The Plane data members flt_num, clock_start, and state are set to the
           values of the parameters fit, time and status, respectively. */
 {
   flt_num = fit;
   clock_start = time;
   state = status;
   cout << "Plane number " << fit << " ready to ";
   if (status == arriving)
      cout << "land." << endl;
   else
      cout << "take off." << endl;
}
Plane::Plane()
/* Post: The Plane data members fit hum, clock_start, state are set to illegal de
          fault values. */
{
  flt_num = -1;
  clock_start = - 1;
  state = null;
}

    void Plane::refuse() const
    /* Post: Processes a Plane wanting to use Runway, when the Queue is full. */
   {
       cout << "Plane number " << flt_num;
       if (state == arriving)
          cout << " directed to another airport" << endl;
     else
          cout << " told to try to takeoff again later" << endl;
}

void Plane::land(int time) const
/* Post: Processes a Plane that is landing at the specified time. */
{
  int wait = time - clock_start;
  cout << time << " :Plane number " << flt_num << " landed after "
  << wait << " time unit" << ((wait == 1)?"":"s")
  << " in the takeoff queue." << endl;
}

void Plane::fly(int time) const
/* Post: Process a Plane that is taking off at the specified time*/
{
  int wait = time - clock_start;
  cout << time << " :Plane number" << flt_num << "take off after "
       << wait << " time unit" << ((wait == 1)?"":"s")
       << " in the takeoff queue" << endl;
}

int Plane::started() const
/* Post: Return the time that the Plane entered the airport system..*/
{
   return clock_start;
}

