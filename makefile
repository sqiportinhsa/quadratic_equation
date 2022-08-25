TARGET = build/square_equation_calculator.exe
CPPFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

.PHONY: all
all: $(TARGET)

clean: rm -rf $(TARGET) *.d *.o

$(TARGET): bin/main.o bin/solver.o bin/user_input_solver.o bin/testmode_solver.o
	g++ -MMD bin/main.o bin/solver.o bin/user_input_solver.o  bin/testmode_solver.o -o $(TARGET) $(CPPFLAGS)

bin/main.o: main.cpp solver.h user_input_solver.h testmode_solver.h
	g++ -MMD -c main.cpp -o bin/main.o $(CPPFLAGS)

bin/solver.o: solver.cpp solver.h
	g++ -MMD -c solver.cpp -o bin/solver.o $(CPPFLAGS)

bin/user_input_solver.o: user_input_solver.cpp user_input_solver.h solver.h
	g++ -MMD -c user_input_solver.cpp -o bin/user_input_solver.o $(CPPFLAGS)

bin/testmode_solver.o: testmode_solver.cpp testmode_solver.h solver.h
	g++ -MMD -c testmode_solver.cpp -o bin/testmode_solver.o $(CPPFLAGS)
