CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: robot2D
	./robot2D

robot2D: obj obj/main.o obj/gnuplot_driver.o obj/Vector2D.o obj/Matrix2x2.o obj/Rectangle.o obj/Robot2D.o obj/Path.o obj/Stage.o
	g++ -Wall -pedantic -std=c++0x -o robot2D obj/main.o obj/gnuplot_driver.o obj/Vector2D.o obj/Matrix2x2.o obj/Rectangle.o obj/Robot2D.o obj/Path.o obj/Stage.o

obj:
	mkdir obj

obj/gnuplot_driver.o: gnuplot_driver.cpp gnuplot_driver.hh
	g++ -c ${CXXFLAGS} -o obj/gnuplot_driver.o gnuplot_driver.cpp

obj/main.o: main.cpp Rectangle.hh Matrix2x2.hh Vector2D.hh Robot2D.hh Path.hh Stage.hh
	g++ -c ${CXXFLAGS} -o obj/main.o main.cpp

obj/Stage.o: Stage.cpp Stage.hh
	g++ -c ${CXXFLAGS} -o obj/Stage.o Stage.cpp

obj/Path.o: Path.cpp Path.hh
	g++ -c ${CXXFLAGS} -o obj/Path.o Path.cpp

obj/Robot2D.o: Robot2D.cpp Robot2D.hh
	g++ -c ${CXXFLAGS} -o obj/Robot2D.o Robot2D.cpp

obj/Rectangle.o: Rectangle.cpp Rectangle.hh
	g++ -c ${CXXFLAGS} -o obj/Rectangle.o Rectangle.cpp

obj/Matrix2x2.o: Matrix2x2.cpp Matrix2x2.hh
	g++ -c ${CXXFLAGS} -o obj/Matrix2x2.o Matrix2x2.cpp

obj/Vector2D.o: Vector2D.cpp Vector2D.hh
	g++ -c ${CXXFLAGS} -o obj/Vector2D.o Vector2D.cpp

clean:
	rm -f obj/*.o robot2D
