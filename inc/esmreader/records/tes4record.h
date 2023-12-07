#pragma once

#include "baserecord.h"

class TES4Record : public BaseRecord
{
	/* TES4 specific sub records */
public:
	class HEDRSubRecord : public BaseSubRecord
	{
	public:
		/** 0.94 in most files; 1.7 in recent versions of Update.esm. */
		float Version;

		/** Number of records and groups (not including TES4 record itself). */
		uint32_t NumRecords;

		/** Next available object ID. */
		FormId NextObjectId;

	protected:
		void ReadRecord(BufferStream& buffer) override;
	};

public:
	TES4Record();

	/** Header */
	HEDRSubRecord HEDR;

	/** Author */
	StringSubRecord CNAM;

	/** Description */
	StringSubRecord SNAM;

	/** Master: The file name of master plugins */
	std::vector<StringSubRecord> MAST;

protected:
	void ParseSubRecord(int recordId, BufferStream& buffer);
};