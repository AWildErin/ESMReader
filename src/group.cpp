#include "esmreader/group.h"

void BaseGroup::ParseGroup(BufferStream& buffer)
{
	Offset = buffer.tell();

	buffer.read(Type);
	buffer.read(GroupSize);
	buffer.read(Label);
	buffer.read(GroupType);
	buffer.read(Stamp);
	buffer.read(Unknown1);
	buffer.read(Data, GroupSize - 24);
}