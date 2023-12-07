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

void BaseRecord::ReadRecord(BufferStream& buffer)
{
	// @todo Lets not backtrack the buffer each record, we should just pass it
	// into the read method
	while (buffer.tell() <= Header.DataSize)
	{
		char tag[4];
		buffer.read(tag);

		std::cout << "Found " << tag[0] << tag[1] << tag[2] << tag[3] << "\n";

		int tagId = tag[3] + (tag[2] << 8) + (tag[1] << 16) + (tag[0] << 24);
		buffer.seek(buffer.tell() - 4);

		ParseSubRecord(tagId, buffer);
	}
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
