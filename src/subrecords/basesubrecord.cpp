#include "esmreader/subrecords/basesubrecord.h"

void BaseSubRecord::ParseRecord(BufferStream& buffer)
{
	buffer.read(Type);
	buffer.read(DataSize);

	ReadRecord(buffer);
}
