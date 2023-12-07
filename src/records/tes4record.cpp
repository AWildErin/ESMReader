#include "esmreader/records/tes4record.h"

TES4Record::TES4Record()
{
}

void TES4Record::ParseSubRecord(int recordId, BufferStream& buffer)
{
	switch (recordId)
	{
	case 'HEDR':
	{
		HEDR.ParseRecord(buffer);
		break;
	}
	case 'CNAM':
	{
		CNAM.ParseRecord(buffer);
		break;
	}
	case 'SNAM':
	{
		SNAM.ParseRecord(buffer);
		break;
	}
	case 'MAST':
	{
		StringSubRecord LocalMast;
		LocalMast.ParseRecord(buffer);
		MAST.push_back(LocalMast);
		break;
	}
	// This will skip DATA blocks, which in FO3/NV we don't care about
	// @todo For morrowind we need to parse this block
	default:
		// Skip record tag as we step back in BaseRecord::ReadRecord
		buffer.skip(4);
		buffer.skip(buffer.read<uint16_t>());
		break;
	}
}

void TES4Record::HEDRSubRecord::ReadRecord(BufferStream& buffer)
{
	buffer.read(Version);
	buffer.read(NumRecords);
	buffer.read(NextObjectId);
}
