#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <math.h>
#include "Vector2D.hh"
#include "Matrix2x2.hh"
#include "Rectangle.hh"
#include "Robot2D.hh"
#include "Path.hh"
#include "Stage.hh"
#include "gnuplot_driver.hh"

using namespace std;

double AtoR (double r)
{
  return ((r * M_PI)/180.0);
}

int main()
{
  Rectangle obj1,obj2,obj3;
  robot robot, robot2, robot3, virtualRobot;
  Stage stage;
  Vector2D vec, translate;
  Path move, move2, move3, virtualMove;
  PzG::GNUPlotDoGNUPlota GNUPlot;
  char a = 'm';
  double angle = 0, rad = 0, rad1 = 0, rad2 = 0, rad3 = 0;
  double oldRad = 0, oldRad1 = 0, oldRad2 = 0, oldRad3 = 0;
  double distance = 0, oldDistance = 0;
  double oldDistance1 = 0, oldDistance2 = 0, oldDistance3 = 0;
  int robotIndex = 1;
  const char *objectFile = "robot.dat";
  const char *moveFile = "move.dat";

  // GNUPlot init (methods have to be in Polish)

  GNUPlot.DodajNazwePliku("obj1.dat",PzG::RR_Ciagly,2);
  GNUPlot.DodajNazwePliku("obj2.dat",PzG::RR_Ciagly,2);
  GNUPlot.DodajNazwePliku("obj3.dat",PzG::RR_Ciagly,2);
  GNUPlot.DodajNazwePliku("robot.dat",PzG::RR_Ciagly,2);
  GNUPlot.DodajNazwePliku("robot2.dat",PzG::RR_Ciagly,2);
  GNUPlot.DodajNazwePliku("robot3.dat",PzG::RR_Ciagly,2);
  GNUPlot.DodajNazwePliku("move.dat",PzG::RR_Ciagly,2);
  GNUPlot.DodajNazwePliku("move2.dat",PzG::RR_Ciagly,2);
  GNUPlot.DodajNazwePliku("move3.dat",PzG::RR_Ciagly,2);
  GNUPlot.ZmienTrybRys(PzG::TR_2D);
  GNUPlot.Inicjalizuj();
  GNUPlot.UstawZakresX(-5,150);
  GNUPlot.UstawZakresY(-5,150);

  // Graphic objects init

  Init(20,20,10, robot);
  Init(110,20,15, robot2); rotate(robot2, M_PI);
  Init(90,100,5, robot3);  rotate(robot3, M_PI);
  Init(45,20,20, obj1);
  Init(80,70,10, obj2);
  Init(10,80,15, obj3);

  move.setStart(robot[7]);
  move.setEnd(robot[7]);
  move2.setStart(robot2[7]);
  move2.setEnd(robot2[7]);
  move3.setStart(robot3[7]);
  move3.setEnd(robot3[7]);

  stage.set(obj1,obj2,obj3,
	          robot,robot2,robot3);

  // List alternative

  /*  lista.push_back(obj1);
  lista.push_back(obj2);
  lista.push_back(obj3);
  lista.push_back(robot);
  lista.push_back(robot2);
  lista.push_back(robot3);

  cout << "Liczba obiektow na scenie wynosi: " << lista.size() << endl << endl;
  */

  // Writing coords to file and GNUPlot drawing

  obj1.drawToFile("obj1.dat");
  obj2.drawToFile("obj2.dat");
  obj3.drawToFile("obj3.dat");
  robot.drawToFile("robot.dat");
  robot2.drawToFile("robot2.dat");
  robot3.drawToFile("robot3.dat");
  move.drawToFile("move.dat");
  move2.drawToFile("move2.dat");
  move3.drawToFile("move3.dat");

  GNUPlot.Rysuj();

  virtualRobot = robot;
  virtualMove = move;
  rad = rad1;
  oldRad = oldRad1;
  oldDistance = oldDistance1;

  // USER'S MENU

  while(a != 'k'){
    switch(a){

    case 'm':
      cout << endl;
      cout << "M E N U:" << endl;
      cout << "w - pick a robot" << endl;
      cout << "z - change robot's move speed" << endl;
      cout << "o - rotate robot" << endl;
      cout << "j - go forward" << endl;
      cout << "d - robot's path length" << endl;
      cout << "t - translate whole drawing" << endl;
      cout << "p - back to the initial settings" << endl;
      cout << "m - show manu" << endl;
      cout << "k - exit" << endl;
      break;

    case 'w': // Pick a robot
      cout << "Pick a robot (1, 2 or 3):" << endl;
      cin >> robotIndex;
      switch(robotIndex) {
      case 1:
	virtualRobot = robot;
	virtualMove = move;
	objectFile = "robot.dat";
	moveFile = "move.dat";
	rad = rad1;
	oldRad = oldRad1;
	oldDistance = oldDistance1;
	break;
      case 2:
	virtualRobot = robot2;
	virtualMove = move2;
	objectFile = "robot2.dat";
	moveFile = "move2.dat";
	rad = rad2;
	oldRad = oldRad2;
	oldDistance = oldDistance2;
	break;
      case 3:
	virtualRobot = robot3;
	virtualMove = move3;
	objectFile = "robot3.dat";
	moveFile = "move3.dat";
	rad = rad3;
	oldRad = oldRad3;
	oldDistance = oldDistance3;
	break;
      }
      break;

    case 'z': // Speed change
      cout << "Robot can't go too fast. Now it's OK!" << endl;
      break;

    case 'o': // Rotate certain angle
      cout << "Choose an angle to rotate:" << endl;
      cin >> angle;

      oldRad = rad;
      rad = AtoR(angle);

      rotate(virtualRobot,rad);
      virtualRobot.drawToFile(objectFile);
      GNUPlot.Rysuj();
    break;

    case 'j': // Go forward
      cout << "Give me a distance:" << endl;
      cin >> distance;
      oldDistance += distance;

      vec.setX(distance * cos(rad+oldRad));
      vec.setY(distance * sin(rad+oldRad));

      virtualMove.setStart(virtualRobot[7]);
      virtualMove.setEnd(virtualRobot[7]+vec);

      virtualRobot = virtualRobot + vec;
      virtualMove.drawToFile(moveFile);
      virtualRobot.drawToFile(objectFile);
      GNUPlot.Rysuj();
      if (virtualRobot.collision(obj1,obj2,obj3) == true)
	     cout << "WARNING! There was a robot collision with other object!" << endl;
      break;

    case 'd': // Distance traveled
      cout << oldDistance << endl;
      break;

    case 't': // Translation
      cout << "Give me a translation vector x, y:" << endl;
      cin >> translate;
      virtualRobot = virtualRobot + translate;
      virtualRobot.drawToFile(objectFile);
      GNUPlot.Rysuj();
      break;

    case 'p': // Reset settings
      Init(20,20,10,robot);
      Init(110,20,15,robot2); rotate(robot2, M_PI);
      Init(90,100,5,robot3);  rotate(robot3, M_PI);

      robot.drawToFile("robot.dat");
      robot2.drawToFile("robot2.dat");
      robot3.drawToFile("robot3.dat");

      remove("move.dat");
      move.setStart(robot[7]);
      move.setEnd(robot[7]);
      GNUPlot.DodajNazwePliku("move.dat",PzG::RR_Ciagly,2);
      move.drawToFile("move.dat");
      GNUPlot.Rysuj();

      break;

    default:
      cout << "This is not an option from menu!" << endl;
      break;
    }
    cout << "Your choice (Picked robot: " << robotIndex << ") -> ";
    cin >> a;
  }
  cout << "Exit! See you soon!" << endl << endl;

  remove("move.dat"); // Remove old paths
  remove("move2.dat");
  remove("move3.dat");
  return 0;
}
