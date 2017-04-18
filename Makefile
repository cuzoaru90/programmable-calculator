all: Calculator

Calculator: Calculator.o BinaryExpr.o Expression.o LogExpr.o
	g++ -o Calculator Calculator.o BinaryExpr.o Expression.o LogExpr.o
Calculator.o:
	g++ -c Calculator.cpp
BinaryExpr.o:
	g++ -c BinaryExpr.cpp
Expression.o:
	g++ -c Expression.cpp
LogExpr.o:
	g++ -c LogExpr.cpp
