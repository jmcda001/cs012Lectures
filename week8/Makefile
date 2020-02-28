# Payroll makefile

COMPILE=g++
EXE=payroll
FLAGS=-g -W -Wall -ansi -pedantic -std=c++11 
OBJS=Employee.o Lecturer.o StudentEmpl.o

# @ symbol runs command silently (doesn't display the command)
all: main.cpp $(OBJS)
	@echo "Compiling \"$^...\""
	$(COMPILE) $(FLAGS) -o $(EXE) main.cpp $(OBJS)

Employee.o: Employee.cpp Employee.h
	@echo "Compiling \"Employee.o ...\""
	$(COMPILE) $(FLAGS) -c Employee.cpp

StudentEmpl.o: StudentEmpl.cpp StudentEmpl.h Employee.h
	@echo "Compiling \"StudentEmpl.o ...\""
	$(COMPILE) $(FLAGS) -c StudentEmpl.cpp

Lecturer.o: Lecturer.cpp Lecturer.h Employee.h
	@echo "Compiling \"Lecturer.o ...\""
	$(COMPILE) $(FLAGS) -c Lecturer.cpp

# Rule using patterns (%), replaces 3 rules from above
# % on the target (before :) matches a string that is then used to replace % on the right (after :)
# $^ expands to the entire dependency list (after :)
# $< expands to the first item in the dependency list (after :)
# $@ expands to the target (before :)
%.o: %.cpp %.h
	@echo "Compiling \"$@...\""
	$(COMPILE) $(FLAGS) -c $<

test: run_tests
	./run_tests
run_tests: test_main.cpp $(OBJS) tests.h
	@echo "Compiling \"$^...\""
	$(COMPILE) $(FLAGS) -o $@ $^

clean:
	rm -rf *.o $(EXE)
