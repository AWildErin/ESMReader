#pragma once

#include "esmreader/subrecords/basesubrecord.h"

/**
* Null-terminated string record.
* 
* @todo Make String private with getter setter
*/
class StringSubRecord : public BaseSubRecord
{
public:
	std::string String;

protected:
	void ReadRecord(BufferStream& buffer) override;
};

template<typename T>
class CollectionSubRecord : public BaseSubRecord
{
public:
	T operator[](int i) const { return Vector[i]; }
	constexpr int capacity() const { return Vector.capacity(); }

	void ParseRecord(BufferStream& buffer) override;

protected:
	void ReadRecord(BufferStream& buffer) override;

private:
	std::vector<T> Vector;
};

template<typename T>
inline void CollectionSubRecord<T>::ParseRecord(BufferStream& buffer)
{
	T subRecord;
	subRecord.ParseRecord(buffer);

	Vector.push_back(subRecord);
}

template<typename T>
inline void CollectionSubRecord<T>::ReadRecord(BufferStream& buffer)
{
	// Stubbed but not used. 
	// @todo do we need to do this? The thought was if we keep this as a BaseSubRecord
	// we can easily make it fit in with all the other subrecords if we make arrays
}
