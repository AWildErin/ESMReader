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

	PluginTES4Record.ParseRecord(Stream);

	return true;
}
