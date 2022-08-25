TARGET = build/square_equation_calculator.exe

.PHONY: all
all: $(TARGET)

clean: rm -rf $(TARGET) *.d

$(TARGET): bin/main.o bin/solver.o bin/user_input_solver.o bin/testmode_solver.o
	g++ -MMD bin/main.o bin/solver.o bin/user_input_solver.o  bin/testmode_solver.o -o $(TARGET)

bin/main.o: main.cpp solver.h user_input_solver.h testmode_solver.h
	g++ -MMD -c main.cpp -o bin/main.o

bin/solver.o: solver.cpp solver.h
	g++ -MMD -c solver.cpp -o bin/solver.o 

bin/user_input_solver.o: user_input_solver.cpp user_input_solver.h solver.h
	g++ -MMD -c user_input_solver.cpp -o bin/user_input_solver.o

bin/testmode_solver.o: testmode_solver.cpp testmode_solver.h solver.h
	g++ -MMD -c testmode_solver.cpp -o bin/testmode_solver.o
