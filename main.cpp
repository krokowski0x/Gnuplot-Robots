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
  Prostokat obj1,obj2,obj3;
  robot robot,robot2,robot3,virtualRobot;
  Scena scena;
  Wektor2D wek, translacja;
  Sciezka move,move2,move3,virtualMove;
  PzG::LaczeDoGNUPlota Lacze;
  char a = 'm';
  double angle = 0, rad = 0, rad1 = 0, rad2 = 0, rad3 = 0;
  double oldRad = 0, oldRad1 = 0, oldRad2 = 0, oldRad3 = 0;
  double distance = 0, oldDistance = 0;
  double oldDistance1 = 0, oldDistance2 = 0, oldDistance3 = 0;
  int robotIndex = 1;
  const char *objectFile = "robot.dat";
  const char *moveFile = "move.dat";

  // Inicjalizacja GNUPlota

  Lacze.DodajNazwePliku("obj1.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("obj2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("obj3.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("robot.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("robot2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("robot3.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("move.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("move2.dat",PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku("move3.dat",PzG::RR_Ciagly,2);
  Lacze.ZmienTrybRys(PzG::TR_2D);
  Lacze.Inicjalizuj();
  Lacze.UstawZakresX(-5,150);
  Lacze.UstawZakresY(-5,150);

  // Inicjalizacja obiektow graficznych

  Init(20,20,10,robot);
  Init(110,20,15,robot2); rotate(robot2,M_PI);
  Init(90,100,5,robot3);  rotate(robot3,M_PI);
  Init(45,20,20,obj1);
  Init(80,70,10,obj2);
  Init(10,80,15,obj3);

  move.setStart(robot[7]);
  move.setEnd(robot[7]);
  move2.setStart(robot2[7]);
  move2.setEnd(robot2[7]);
  move3.setStart(robot3[7]);
  move3.setEnd(robot3[7]);

  scena.set(obj1,obj2,obj3,
	          robot,robot2,robot3);

  // Wypelnienie list

  /*  lista.push_back(obj1);
  lista.push_back(obj2);
  lista.push_back(obj3);
  lista.push_back(robot);
  lista.push_back(robot2);
  lista.push_back(robot3);

  cout << "Liczba obiektow na scenie wynosi: " << lista.size() << endl << endl;
  */

  // Zapis wspolrzednych do plikow i rysowanie w GNUPlocie

  obj1.drawToFile("obj1.dat");
  obj2.drawToFile("obj2.dat");
  obj3.drawToFile("obj3.dat");
  robot.drawToFile("robot.dat");
  robot2.drawToFile("robot2.dat");
  robot3.drawToFile("robot3.dat");
  move.drawToFile("move.dat");
  move2.drawToFile("move2.dat");
  move3.drawToFile("move3.dat");

  Lacze.Rysuj();

  virtualRobot = robot;
  virtualMove = move;
  rad = rad1;
  oldRad = oldRad1;
  oldDistance = oldDistance1;

  // Menu uzytkownika

  while(a != 'k'){
    switch(a){

    case 'm':
      cout << endl;
      cout << "M E N U:" << endl;
      cout << "w - wybor robota" << endl;
      cout << "z - zmiana szybkosci ruchu robota" << endl;
      cout << "o - obrot robota" << endl;
      cout << "j - jazda na wprost" << endl;
      cout << "d - dlugosc przebytej sciezki" << endl;
      cout << "t - translacja rysunku" << endl;
      cout << "p - powrot do ustawien poczatkowych" << endl;
      cout << "m - wyswietl menu" << endl;
      cout << "k - zakoncz dzialanie programu" << endl;
      break;

    case 'w': // Wybor robota
      cout << "Wybierz robota (1, 2 lub 3):" << endl;
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

    case 'z': // Zmiana szybkosci
      cout << "Robot nie moze jechac za szybko. Teraz jest OK!" << endl;
      break;

    case 'o': // Obrot o kat
      cout << "Podaj kat:" << endl;
      cin >> angle;

      oldRad = rad;
      rad = AtoR(angle);

      rotate(virtualRobot,rad);
      virtualRobot.drawToFile(objectFile);
      Lacze.Rysuj();
    break;

    case 'j': // Jazda na wprost
      cout << "Podaj odleglosc:" << endl;
      cin >> distance;
      oldDistance += distance;

      wek.setX(distance * cos(rad+oldRad));
      wek.setY(distance * sin(rad+oldRad));

      virtualMove.setStart(virtualRobot[7]);
      virtualMove.setEnd(virtualRobot[7]+wek);

      virtualRobot = virtualRobot + wek;
      virtualMove.drawToFile(moveFile);
      virtualRobot.drawToFile(objectFile);
      Lacze.Rysuj();
      if (virtualRobot.collision(obj1,obj2,obj3) == true)
	cout << "UWAGA! NASTAPILA KOLIZJA ROBOTA Z INNYM OBIEKTEM!" << endl;
      break;

    case 'd': // Przebyta droga
      cout << oldDistance << endl;
      break;

    case 't': // Translacja
      cout << "Podaj wektor translacji x,y:" << endl;
      cin >> translacja;
      virtualRobot = virtualRobot + translacja;
      virtualRobot.drawToFile(objectFile);
      Lacze.Rysuj();
      break;

    case 'p': // Ustawienia poczatkowe
      Init(20,20,10,robot);
      Init(110,20,15,robot2); rotate(robot2, M_PI);
      Init(90,100,5,robot3);  rotate(robot3, M_PI);

      robot.drawToFile("robot.dat");
      robot2.drawToFile("robot2.dat");
      robot3.drawToFile("robot3.dat");

      remove("move.dat");
      move.setStart(robot[7]);
      move.setEnd(robot[7]);
      Lacze.DodajNazwePliku("move.dat",PzG::RR_Ciagly,2);
      move.drawToFile("move.dat");
      Lacze.Rysuj();

      break;

    default:
      cout << "Takiej opcji nie ma w menu!" << endl;
      break;
    }
    cout << "Twoj wybor (Wybrany robot: " << robotIndex << ") -> ";
    cin >> a;
  }
  cout << "Koniec dzialania programu!" << endl << endl;

  remove("move.dat"); // Usuniecie starych sciezek
  remove("move2.dat");
  remove("move3.dat");
  return 0;
}
