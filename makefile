CC = g++ -std=c++11
EXE_FILE = main.out

&(EXE_FILE) : main.o driver.o mission.o software.o travel.o
	$(CC) main.o driver.o mission.o software.o travel.o -o $(EXE_FILE)

main.o: software.hpp
	$(CC) -c main.cpp -o main.o


driver.o: driver.hpp general.hpp
	$(CC) -c driver.cpp -o driver.o


mission.o: mission.hpp general.hpp
	$(CC) -c mission.cpp -o mission.o


software.o: software.hpp general.hpp mission.cpp travel.hpp driver.hpp
	$(CC) -c software.cpp -o software.o


travel.o: travel.hpp general.hpp 
	$(CC) -c travel.cpp -o travel.o


clean:
	rm *.o $(EXE_FILE)