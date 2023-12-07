#pragma once

#include "esmreader/types.h"
#include "esmreader/subrecords/basesubrecord.h"
#include "esmreader/subrecords/common.h"

/**
* Flags used for the record.
* Some flags share the same value, but are unique to certain records.
* Taken from:
* https://tes5edit.github.io/fopdoc/Fallout3/Records.html
*
* @note `_` denotes a separate flag with the same ID
*/
enum RecordFlags
{
    MasterFile                                              = 0x00000001,
    Unknown1                                                = 0x00000002,
    Unknown2                                                = 0x00000004,
    Unknown3                                                = 0x00000008,
    Unknown4                                                = 0x00000010,
    Deleted                                                 = 0x00000020,
    BorderRegion_HasTreeLOD_Constant_HiddenFromLocalMap     = 0x00000040,
    TurnOffFire                                             = 0x00000080,
    Inaccessible                                            = 0x00000100,
    CastsShadows_OnLocalMap_MotionBlur                      = 0x00000200,
    QuestItem_PersistentReference                           = 0x00000400,
    InitiallyDisabled                                       = 0x00000800,
    Ignored                                                 = 0x00001000,
    NoVoiceFilter                                           = 0x00002000,
    Unknown5                                                = 0x00004000,
    VisibleWhenDistant                                      = 0x00008000,
    RandomAnimStart_HighPriorityLOD                         = 0x00010000,
    Dangerous_OffLimits_RadioStation                        = 0x00020000,
    Compressed                                              = 0x00040000,
    CantWait_PlatformSpecificTexture                        = 0x00080000,
    Unknown6                                                = 0x00100000,
    Unknown7                                                = 0x00200000,
    Unknown8                                                = 0x00400000,
    Unknown9                                                = 0x00800000,
    Unknown10                                               = 0x01000000,
    Obstacle_NoAIAcquire                                    = 0x02000000,
    NavMeshGanFilter                                        = 0x04000000,
    NavMeshGenBoundingBox                                   = 0x08000000,
    NonPipboy_ReflectedbyAutoWater                          = 0x10000000,
    ChildCanUse_RefractedByAutoWater                        = 0x20000000,
    NavMeshGenGround                                        = 0x40000000,
    Unknown11                                               = 0x80000000,
};

struct RecordHeader
{
	char Type[4];
	uint32_t DataSize;
    RecordFlags Flags;
	FormId Id;

	uint32_t Revision;
	uint16_t Version;
	uint16_t Unk1;
	std::vector<std::byte> Data;

	uint32_t DecompressedSize;

	/**
	* Collection of subrecords compressed using zlib
    * Length is DataSize - 4
	*/
	std::vector<std::byte> CompressedData;

};

// @todo Store a reference to the ESM we come from in the constructor
class BaseRecord
{
public:
	BaseRecord();
	~BaseRecord();

    // @todo Pass type so we can give it to the header
    void ParseRecord(BufferStream& buffer);

    const RecordHeader GetHeader() { return Header; }
protected:
	virtual void ReadRecord(BufferStream& buffer) = 0;

    RecordHeader Header;

    BufferStream ESMBuffer;
private:
	void ReadHeader(BufferStream& buffer);
};