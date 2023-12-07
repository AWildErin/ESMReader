#pragma once

#include "esmreader/subrecords/basesubrecord.h"

/**
* Null-terminated string record.
* 
* @todo Make String private with getter setter
*/
class StringSubRecord : public BaseSubRecord
{
public:
	std::string String;

protected:
	void ReadRecord(BufferStream& buffer) override;
};