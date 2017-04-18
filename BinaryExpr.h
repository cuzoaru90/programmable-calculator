/*
 *  BinaryExpr.h
 *  proj 5
 *
 *  Created by Chuk Uzoaru on 12/4/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */


#ifndef BINARYEXPR_H
#define BINARYEXPR_H

#include "Expression.h"
using namespace std;


class BinaryExpr : public Expression {
	
private:
	
	
public:
	
	double add();
	double multiply();
	double divide();
	double subtract();
	double exponentiate();
    
	
};

#endif