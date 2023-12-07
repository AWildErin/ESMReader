#pragma once

#include "esmreader/types.h"

// @todo Add reference to the ESM and base record we came from
class BaseSubRecord
{
public:
	char Type[4];

	/**
	* Size of the data, unless the preceding subrecord has the type XXXX, 
	* in which case this will be 0 and the size of the data field will be 
	* given by the preceding subrecord’s data, interpreted as a 32-bit unsigned integer.
	*/
	uint16_t DataSize;

	/** @note Unused due to how we read data, we read it all sequentially, so this is useless */
	// @todo Use a buffer for this that we can pass to ReadRecord
	std::vector<std::byte> Data;

	// @todo Pass type so we can give it to the header
	void ParseRecord(BufferStream& buffer);

protected:
	virtual void ReadRecord(BufferStream& buffer) = 0;
};