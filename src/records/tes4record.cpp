#include "esmreader/records/tes4record.h"

TES4Record::TES4Record()
{
}

// @todo Remove this macro and figure out a better way to
// register and detect both kinds of records
#define READ_RECORD(str, var)		\
if (strncmp(tag, str, 4) == 0)		\
{									\
	buffer.seek(buffer.tell() - 4);	\
	var.ParseRecord(buffer);		\
}							

void TES4Record::ReadRecord(BufferStream& buffer)
{
	while (buffer.tell() <= Header.DataSize)
	{
		char tag[4];
		buffer.read(tag);

		READ_RECORD("HEDR", HEDR);
		READ_RECORD("CNAM", CNAM);
		READ_RECORD("SNAM", SNAM);
		READ_RECORD("MAST", MAST);
	}

	int test = 0;
}

void TES4Record::HEDRSubRecord::ReadRecord(BufferStream& buffer)
{
	buffer.read(Version);
	buffer.read(NumRecords);
	buffer.read(NextObjectId);
}
