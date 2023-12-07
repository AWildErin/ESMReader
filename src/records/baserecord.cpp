#include "esmreader/records/baserecord.h"

BaseRecord::BaseRecord()
{
}

BaseRecord::~BaseRecord()
{
}

void BaseRecord::ParseRecord(BufferStream& buffer)
{
	// Save a reference to our ESM buffer
	ESMBuffer = buffer;

	ReadHeader(buffer);

	// Create a buffer from the Record data specifically
	BufferStream recordBuffer(Header.Data.data(), Header.DataSize);

	ReadRecord(recordBuffer);
}

void BaseRecord::ReadHeader(BufferStream& buffer)
{
	buffer.read(Header.Type);
	buffer.read(Header.DataSize);
	buffer.read(Header.Flags);
	buffer.read(Header.Id);
	buffer.read(Header.Revision);
	buffer.read(Header.Version);
	buffer.read(Header.Unk1);
	buffer.read(Header.Data, Header.DataSize);
}
