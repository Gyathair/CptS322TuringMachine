CC = g++
OPTIONS = -g -Wall

all: tm

test: Main_StateTest Main_TapeTest

Tape.o: Tape.cpp Tape.h
	$(CC) $(OPTIONS) -c Tape.cpp -o Tape.o
State.o: State.cpp State.h
	$(CC) $(OPTIONS) -c State.cpp -o State.o
Final_State.o: Final_State.cpp Final_State.h
	$(CC) $(OPTIONS) -c Final_State.cpp -o Final_State.o
States.o: States.cpp States.h
	$(CC) $(OPTIONS) -c States.cpp -o States.o
Final_States.o: Final_States.cpp Final_States.h
	$(CC) $(OPTIONS) -c Final_States.cpp -o Final_States.o
Crash.o: Crash.cpp Crash.h
	$(CC) $(OPTIONS) -c Crash.cpp -o Crash.o
Transition.o: Transition.cpp Transition.h
	$(CC) $(OPTIONS) -c Transition.cpp -o Transition.o
Transition_Function.o: Transition_Function.cpp Transition_Function.h
	$(CC) $(OPTIONS) -c Transition_Function.cpp -o Transition_Function.o
Visible.o: Visible.cpp Visible.h
	$(CC) $(OPTIONS) -c Visible.cpp -o Visible.o
Turing_Machine.o: Turing_Machine.cpp Turing_Machine.h
	$(CC) $(OPTIONS) -c Turing_Machine.cpp -o Turing_Machine.o
Input_Alphabet.o: Input_Alphabet.cpp Input_Alphabet.h
	$(CC) $(OPTIONS) -c Input_Alphabet.cpp -o Input_Alphabet.o
Tape_Alphabet.o: Tape_Alphabet.cpp Tape_Alphabet.h
	$(CC) $(OPTIONS) -c Tape_Alphabet.cpp -o Tape_Alphabet.o

tm.o: Main.cpp 
	$(CC) $(OPTIONS) -c Main.cpp -o tm.o

tm: tm.o Tape.o Crash.o State.o Final_State.o Final_States.o States.o Transition.o Transition_Function.o Visible.o Turing_Machine.o Input_Alphabet.o Tape_Alphabet.o
	$(CC) $(OPTIONS) tm.o Tape.o State.o Crash.o -o tm

Main_StateTest.o: Main_StateTest.cpp
	$(CC) $(OPTIONS) -c Main_StateTest.cpp -o Main_StateTest.o

Main_StateTest: Main_StateTest.o State.o
	$(CC) $(OPTIONS) Main_StateTest.o State.o -o Main_StateTest

Main_TapeTest.o: Main_TapeTest.cpp
	$(CC) $(OPTIONS) -c Main_TapeTest.cpp -o Main_TapeTest.o

Main_TapeTest: Main_TapeTest.o Tape.o Crash.o
	$(CC) $(OPTIONS) Main_TapeTest.o Tape.o Crash.o -o Main_TapeTest

clean:
	@rm -f tm Main_StateTest Main_TapeTest
	@rm -f *.o

