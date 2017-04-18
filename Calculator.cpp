#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

#include "Expression.h"
#include "BinaryExpr.h"
#include "LogExpr.h"


double UpdateRegister(string a)
{
	return atof(a.substr(2).c_str());	
}

double determineReceiver(string a, double x, double y, double z){
	if (a.substr(2, 1) == "x" || a.substr(5, 1) == "x"){
		return x;
	}
	
	if (a.substr(2, 1) == "y" || a.substr(5, 1) == "y"){
		return y;
	}
	
	if (a.substr(2, 1) == "z" || a.substr(5, 1) == "z"){
		return z;
	}
	
	return 0;
}

double determineArgument(string a, double x, double y, double z){
	if (a.substr(4, 1) == "x" || a.substr(5,1) == "x"){
		return x;
	}
	
	if (a.substr(4, 1) == "y" || a.substr(5,1) == "y"){
		return y;
	}
	
	if (a.substr(4, 1) == "z" || a.substr(5,1) == "z"){
		return z;
	}
	
	return 0;
}


void displayCommands()
{
	cout << "r - Calculator reset" << endl;
	cout << "v - Show value of registers" << endl;
	cout << "x - Enter value for register x" << endl << "y - Enter value for register y" << endl;
	cout << "z - Enter value for register z" << endl << "s - Do a step-by-step execution of expression sequence" << endl;
	cout << "e - Do a full execution of all expressions" << endl << "d - Display executed instructions" << endl;
	cout << "q - Quit" << endl;
	
}


int main (int argc, char * const argv[]) {
	
	string line;
	vector<string> expressions;
	
	double xReg, yReg, zReg;
	
	xReg = 0;
	yReg = 0;
	zReg = 0;
	
	int exprCounter = 0;
	
	ifstream myfile (argv[1]);

	if (myfile.is_open()){
		while ( getline (myfile,line) )
		{
			line.erase(remove(line.begin(), line.end(), ' '), line.end() );
			expressions.push_back(line);
		}
		myfile.close();
	}
	else {
		std::cout << "Command line argument 1 must read in a text file" << endl;
		exit(0);
	}
	
	string command;
		
	// The application starts here
	cout << "This is the PC (programmable calculator). You can choose from any of the following";
	cout << " commands below. Press 'h' at any time to display them again." << endl;
	displayCommands();
	
	do
	{
		cout << "Enter command: ";
		cin >> command;
		
		if (command == "h"){
			displayCommands();	
		}
		
		// Displays current sequence of evaluated expressions.
		if (command == "d"){
			for (int i = 0; i < exprCounter; i++)
			{
				cout << expressions[i] << endl;	
			
			}
			
			if (exprCounter == 0){
				cout << "No expressions have been evaluated." << endl;
			}
			
		}
		
		// Shows value of registers
		if (command == "v"){
			cout << "x: " << xReg << endl;
			cout << "y: " << yReg << endl;
			cout << "z: " << zReg << endl;		
		}
		
		if (command == "x"){
			cout << "Enter value for x register" << endl;
			cin >> xReg;	
		}
		
		if (command == "y"){
			cout << "Enter value for y register" << endl;
			cin >> yReg;	
		}
		
		if (command == "z"){
			cout << "Enter value for z register" << endl;
			cin >> zReg;	
		}
		
		if (command == "r"){
			xReg = 0;
			yReg = 0;
			zReg = 0;
			
			exprCounter = 0;
			
			cout << "Registers cleared" << endl;
			cout << "Expression sequence reset " << endl;
		}
		
		// Complete execution
		if (command == "e"){
			exprCounter = 0;
			xReg = 0;
			yReg = 0;
			zReg = 0;
			
			for (int i = 0; i < expressions.size(); i++)
			{		
				
				if (expressions[i].substr(3,2) == "**"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[i], xReg, yReg, zReg);
					double argument = determineArgument(expressions[i], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[i].substr(0,1) == "x"){
						xReg = expr.exponentiate();
					}
					if (expressions[i].substr(0,1) == "y"){
						yReg = expr.exponentiate();
					}
					if (expressions[i].substr(0,1) == "z"){
						zReg = expr.exponentiate();
					}
					
				}
				else if (expressions[i].substr(3,1) == "+"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[i], xReg, yReg, zReg);
					double argument = determineArgument(expressions[i], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[i].substr(0,1) == "x"){
						xReg = expr.add();
					}
					if (expressions[i].substr(0,1) == "y"){
						yReg = expr.add();
					}
					if (expressions[i].substr(0,1) == "z"){
						zReg = expr.add();
					}
					
				}
				else if (expressions[i].substr(3,1) == "-"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[i], xReg, yReg, zReg);
					double argument = determineArgument(expressions[i], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[i].substr(0,1) == "x")
					{
						xReg = expr.subtract();
					}
					if (expressions[i].substr(0,1) == "y")
					{
						yReg = expr.subtract();
					}
					if (expressions[i].substr(0,1) == "z")
					{
						zReg = expr.subtract();
					}
				}
				else if (expressions[i].substr(3,1) == "*"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[i], xReg, yReg, zReg);
					double argument = determineArgument(expressions[i], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[i].substr(0,1) == "x"){
						xReg = expr.multiply();
					}
					if (expressions[i].substr(0,1) == "y"){
						yReg = expr.multiply();
					}
					if (expressions[i].substr(0,1) == "z"){
						zReg = expr.multiply();
					}
				}
				else if (expressions[i].substr(3,1) == "/"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[i], xReg, yReg, zReg);
					double argument = determineArgument(expressions[i], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[i].substr(0,1) == "x"){
						xReg = expr.divide();
					}
					if (expressions[i].substr(0,1) == "y"){
						yReg = expr.divide();
					}
					if (expressions[i].substr(0,1) == "z"){
						zReg = expr.divide();
					}
				}
				else if (expressions[i].substr(2,3) == "log"){
					LogExpr expr;
					
					double receiver = determineReceiver(expressions[i], xReg, yReg, zReg);
					expr.setReceiver(receiver);
					
					if (expressions[i].substr(0,1) == "x"){
						xReg = expr.getLog();
					}
					if (expressions[i].substr(0,1) == "y"){
						yReg = expr.getLog();
					}
					if (expressions[i].substr(0,1) == "z"){
						zReg = expr.getLog();
					}
				}
				else {	
					if (expressions[i].substr(0,1) == "x"){
						xReg = UpdateRegister(expressions[i]);
					}
					if (expressions[i].substr(0,1) == "y"){
						yReg = UpdateRegister(expressions[i]);
					}
					if (expressions[i].substr(0,1) == "z"){
						zReg = UpdateRegister(expressions[i]);
					}
				}	
				
			}
			
			exprCounter = expressions.size();
			
			cout << "x: " << xReg << endl;
			cout << "y: " << yReg << endl;
			cout << "z: " << zReg << endl;
			
		} // End of complete execution
		
		
		// Step-by-Step execution
		if (command == "s"){
			
			if (exprCounter < expressions.size() ){
			
				if (expressions[exprCounter].substr(3,2) == "**"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[exprCounter], xReg, yReg, zReg);
					double argument = determineArgument(expressions[exprCounter], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[exprCounter].substr(0,1) == "x"){
						xReg = expr.exponentiate();
					}
					if (expressions[exprCounter].substr(0,1) == "y"){
						yReg = expr.exponentiate();
					}
					if (expressions[exprCounter].substr(0,1) == "z"){
						zReg = expr.exponentiate();
					}
				}
				else if (expressions[exprCounter].substr(3,1) == "+"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[exprCounter], xReg, yReg, zReg);
					double argument = determineArgument(expressions[exprCounter], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[exprCounter].substr(0,1) == "x"){
						xReg = expr.add();
					}
					if (expressions[exprCounter].substr(0,1) == "y"){
						yReg = expr.add();
					}
					if (expressions[exprCounter].substr(0,1) == "z"){
						zReg = expr.add();
					}
					
				}
				else if (expressions[exprCounter].substr(3,1) == "-"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[exprCounter], xReg, yReg, zReg);
					double argument = determineArgument(expressions[exprCounter], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[exprCounter].substr(0,1) == "x"){
						xReg = expr.subtract();
					}
					if (expressions[exprCounter].substr(0,1) == "y"){
						yReg = expr.subtract();
					}
					if (expressions[exprCounter].substr(0,1) == "z"){
						zReg = expr.subtract();
					}
				}
				else if (expressions[exprCounter].substr(3,1) == "*"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[exprCounter], xReg, yReg, zReg);
					double argument = determineArgument(expressions[exprCounter], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[exprCounter].substr(0,1) == "x"){
						xReg = expr.multiply();
					}
					if (expressions[exprCounter].substr(0,1) == "y"){
						yReg = expr.multiply();
					}
					if (expressions[exprCounter].substr(0,1) == "z"){
						zReg = expr.multiply();
					}
				}
				else if (expressions[exprCounter].substr(3,1) == "/"){
					BinaryExpr expr;
					
					double receiver = determineReceiver(expressions[exprCounter], xReg, yReg, zReg);
					double argument = determineArgument(expressions[exprCounter], xReg, yReg, zReg);
					
					expr.setReceiver(receiver);
					expr.setArgument(argument);
					
					if (expressions[exprCounter].substr(0,1) == "x"){
						xReg = expr.divide();
					}
					if (expressions[exprCounter].substr(0,1) == "y"){
						yReg = expr.divide();
					}
					if (expressions[exprCounter].substr(0,1) == "z"){
						zReg = expr.divide();
					}
				}
				else if (expressions[exprCounter].substr(2,3) == "log"){
					LogExpr expr;
					
					double receiver = determineReceiver(expressions[exprCounter], xReg, yReg, zReg);
					expr.setReceiver(receiver);
					
					if (expressions[exprCounter].substr(0,1) == "x"){
						xReg = expr.getLog();
					}
					if (expressions[exprCounter].substr(0,1) == "y"){
						yReg = expr.getLog();
					}
					if (expressions[exprCounter].substr(0,1) == "z"){
						zReg = expr.getLog();
					}
					
				}
				else {
					
					if (expressions[exprCounter].substr(0,1) == "x"){
						xReg = UpdateRegister(expressions[exprCounter]);
					}
					if (expressions[exprCounter].substr(0,1) == "y"){
						yReg = UpdateRegister(expressions[exprCounter]);
					}
					if (expressions[exprCounter].substr(0,1) == "z"){
						zReg = UpdateRegister(expressions[exprCounter]);
					}
				}		
			
				exprCounter++;
			
			cout << "x: " << xReg << endl;
			cout << "y: " << yReg << endl;
			cout << "z: " << zReg << endl;
			
		}
		else{
		  cout << "There are no more commands to step through." << endl;
		  cout << "Reset the PC to start another step-by-step execution." << endl;
		}
			
		} // End of step-by-step execution
		
	}while (command != "q");
	
	
	return 0;
}
