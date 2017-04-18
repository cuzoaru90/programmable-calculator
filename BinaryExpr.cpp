/*
 *  BinaryExpr.cpp
 *  proj 5
 *
 *  Created by Chuk Uzoaru on 12/4/13.
 *  Copyright 2013 University of Illinois at Chicago. All rights reserved.
 *
 */

#include "BinaryExpr.h"


double BinaryExpr::add(){
	return (receiver + argument);
}

double BinaryExpr::multiply(){		
	return (receiver * argument);		
}

double BinaryExpr::subtract(){	
	return (receiver - argument);		
}

double BinaryExpr::divide(){	
	return (receiver / argument);
}

double BinaryExpr::exponentiate(){	
	return pow(receiver, argument);
}