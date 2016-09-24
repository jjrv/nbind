// This file is part of nbind, copyright (C) 2014-2016 BusFaster Ltd.
// Released under the MIT license, see LICENSE.

#pragma once

namespace nbind {

class NBindID {

public:

	explicit NBindID(TYPEID id);
	NBindID (const NBindID &other);
	NBindID (NBindID &&other);
	~NBindID();

	NBindID &operator=(const NBindID &) = delete;
	NBindID &operator=(NBindID &&) = delete;

	const void *getStructure() const;
	StructureType getStructureType() const;
	const char *toString();

private:

	union {
		TYPEID id;
		const void *structure;
		const StructureType *structureType;
	};

	const char *name;

};

class cbFunction;

class NBind {

public:

	static void bind_value(const char *name, cbFunction &func);

	static void reflect(
		cbFunction &outPrimitive,
		cbFunction &outType,
		cbFunction &outClass,
		cbFunction &outMethod
	);

	static void queryType(NBindID type, cbFunction &outTypeDetail);

};

} // namespace

#define nbind_debug()
