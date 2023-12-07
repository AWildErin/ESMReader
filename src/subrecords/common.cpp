#include "esmreader/subrecords/common.h"

void StringSubRecord::ReadRecord(BufferStream& buffer)
{
	buffer.read(String);
}
