/**
* Common types and utility functions used across the entire codebase
*/

#pragma once
 
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

#include "esmreader/bufferstream.h"

/* Types */

typedef unsigned int FormId;

struct RGBA
{
	unsigned char R, G, B, A;

	RGBA(unsigned char R, unsigned char G, unsigned char B, unsigned char A)
		: R(R), G(G), B(B), A(A)
	{
	}
};

/**
* Utility methods, declared in utility.cpp
*/

int TagInt(char tag[4]);