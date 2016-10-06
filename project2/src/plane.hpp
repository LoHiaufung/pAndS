#ifndef PLANE_HPP
#define PLANE_HPP

 enum Plane_status {null, arriving, departing};
 class Plane {
 public:
    Plane();
    Plane(int fit, int time, Plane_status status);
   void refuse() const;
   void land(int time) const;
   void fly(int time) const;
   int started() const;
   void operator= ( Plane x) {
   	flt_num = x.flt_num;
   	clock_start = x.clock_start;
   	state = x.state;
   }
   int getFltNum() {return flt_num;}
   int getClockStart() {return clock_start;}
   Plane_status getPlaneStatus() {return state;}

private:
   int flt_num;
   int clock_start;
   Plane_status state;
};

#endif