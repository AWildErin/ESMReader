#pragma once

#include "esmreader/types.h"

// @todo Should we maybe just make a records.h that is precompiled?
#include "esmreader/records/tes4record.h"
#include "esmreader/group.h"

// @todo Add game enum so we can allow for multiple games in 1 record
class ESM
{
public:
	ESM();
	~ESM();
	
	/** 
	* Opens the specified ESM File
	* @returns whether or not the file could be opened
	* @todo Maybe we could return an enum value to specify specific errors
	*/
	bool Open(const std::string& filePath);

	const std::string& GetFullPath() { return FullPath; }
	const std::string& GetFileName() { return FileName; }
	const TES4Record& GetTES4Record() { return PluginTES4Record; }
private:
	std::string FullPath;
	std::string FileName;

	TES4Record PluginTES4Record;

	/** key is int value of the Group tag. Example: 'WRLD'. */
	std::map<int, BaseGroup> Groups;
};