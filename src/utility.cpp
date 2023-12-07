#include "esmreader/Types.h"

int TagInt(char tag[4])
{
	return tag[3] + (tag[2] << 8) + (tag[1] << 16) + (tag[0] << 24);
}