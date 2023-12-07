#pragma once

enum GroupType : uint32_t
{
	TopLevel = 0,
	WorldChildren,
	InteriorCellBlock,
	InteriorCellSubBlock,
	ExteriorCellBlock,
	ExteriorCellSubBlock,
	CellChildren,
	TopicChildren,
	CellPersistentChildren,
	CellTemporaryChildren,
	CellVisibleDistantChildren,
};

/**
* Base group class
* 
* @todo Make stuff private
*/
class BaseGroup
{
public:
	void ParseGroup(BufferStream& buffer);

	/** Always 'GRUP' */
	char Type[4];

	/** Size of the group including the header (24 bytes) */
	uint32_t GroupSize;

	/** Type depends on the GroupType */
	std::byte Label[4];

	/** The group type. Determines the data in Label */
	GroupType GroupType;

	/** A date stamp. The first byte is the day of the month, and the second byte is the number of months since some unknown point in time. */
	uint16_t Stamp;

	std::byte Unknown1[6];

	/** The records and subgroups contained within the group. Size is GroupSize - 24 bytes */
	std::vector<std::byte> Data;

	size_t Offset;
};