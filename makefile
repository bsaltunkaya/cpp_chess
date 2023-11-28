all: clean compile run

compile: runchess.cpp chesshead.cpp
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ -o test runchess.cpp chesshead.cpp -lm

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "======================================================================="
	@./test
	@echo "======================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Cleaning..."
	@rm -f *.o
	@rm -f test