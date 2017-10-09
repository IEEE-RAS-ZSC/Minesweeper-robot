#include <ros.h>
#include <std_msgs/Char.h>
#include <std_msgs/UInt16MultiArray.h>

ros::NodeHandle nh;

std_msgs::Char str_msg;
std_msgs::UInt16MultiArray coor;

ros::Publisher mine_lo("Mine_located", &str_msg);
ros::Publisher mine_pl("Mine_place", &coor);


char type = 'n';
int x=0,y=0;
void setup() {
  nh.initNode();
  nh.advertise(mine_lo);
  coor.data_length =3;
  nh.advertise(mine_pl);
  pinMode(4, INPUT);
  pinMode(5, INPUT);

}

void loop() {
  if ( digitalRead(4) == HIGH)
  {
    type = 's';
    publish();
  }
  else if (digitalRead(5) == HIGH )
  {
    type = 'b';
    publish();
  }


  nh.spinOnce();
  delay(50);

}

void publish()
{
  x= random(1,20);
  y= random(1,20);
  coor.data[1]= x;
  coor.data[2]= y;
  str_msg.data = type;
  mine_lo.publish( &str_msg);
  delay(1);
  mine_pl.publish(&coor);

  }



