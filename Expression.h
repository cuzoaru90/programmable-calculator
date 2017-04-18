/*
 *  Expression.h
 *  proj 5
 *
 *  Created by Chuk Uzoaru on 12/4/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H


#include <iostream>
#include "math.h"

using namespace std;



class Expression {
	
public:
	
	void setArgument(double x);
	void setReceiver(double y);
	
    Expression();
    
	
protected:
	double receiver, argument;
	
};

#endif