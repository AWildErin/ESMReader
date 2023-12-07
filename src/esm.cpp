#include "esmreader/esm.h"
#include "esmreader/records/tes4record.h"

ESM::ESM()
{
	// Hook up all the records into our record factory
}

ESM::~ESM()
{
}

/// @todo can we do this a bit better?
bool ESM::Open(const std::string& filePath)
{
	std::ifstream file(filePath, std::ios::binary | std::ios::ate);
	if (!file.is_open())
		return false;

	int length = file.tellg();
	std::vector<char> buffer(length);

	file.seekg(0, std::ios::beg);
	file.read(&buffer[0], length);
	file.close();

	BufferStream Stream(reinterpret_cast<std::byte*>(buffer.data()), length);

	// The first record is always going to be TES4
	// @todo introduce some checking here
	PluginTES4Record.ParseRecord(Stream);

	while (Stream.tell() != length)
	{
		int start = Stream.tell();

		BaseGroup grup;
		grup.ParseGroup(Stream);

		// @todo Can we do this better?
		char tag[4] = { (char)grup.Label[0], (char)grup.Label[1], (char)grup.Label[2], (char)grup.Label[3] };
		int tagId = TagInt(tag);

		Groups[tagId] = grup;
	}

	BaseGroup WRLD = Groups['WRLD'];

	return true;
}
