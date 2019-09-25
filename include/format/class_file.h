#ifndef _AVM_CLASS_FILE_H_
#define _AVM_CLASS_FILE_H_

#include "types.h"
#include "constants.h"
#include "field_info.h"

namespace avm {
class ClassFile {
	friend class ClassParser;
public:
	ClassFile();
	virtual ~ClassFile();
public:
	void verbose();
	u4 getMagic() const { return magic; }
	u2 getMinorVersion() const { return minor_version; }
	u2 getMajorVersion() const { return major_version; }
private:
	void ensureConstantPool();
	void ensureInterfaces();
	void ensureFields();
	void printConstantPool();
	void printInterfaces();
private:
	u4 magic;
	u2 minor_version;
	u2 major_version;
	u2 constant_pool_count;
	ConstantInfo* constant_pool;
	u2 access_flags;
	u2 this_class;
	u2 super_class;
	u2 interfaces_count;
	u2* interfaces;
	u2 fields_count;
	FieldInfo* fields;
};
}

#endif
