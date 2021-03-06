#include "gtest/gtest.h"

#include <iostream>
#include "class_file/parser/java_class_parser.h"

using namespace avm;

TEST(ClassParser, parseSimpleFields) {
    JavaClassParser parser("res/com/test/Simple.class");
    JavaClass javaClass;
    parser.parse(javaClass);

    ASSERT_EQ(0, javaClass.getFieldsCount());

    JavaClassParser parser1("res/com/test/SingleField.class");
    JavaClass javaClass1;
    parser1.parse(javaClass1);

    ASSERT_EQ(1, javaClass1.getFieldsCount());
    const FieldInfo *field = javaClass1.getFieldAt(0);
    ASSERT_TRUE(field->isPublic());
    ASSERT_TRUE(field->isStatic());
    ASSERT_FALSE(field->isEnum());

    ASSERT_EQ(4, field->getNameIndex());
    ASSERT_EQ(5, field->getDescriptorIndex());
}

TEST(ClassParser, parseFieldConstantValue) {
    JavaClassParser parser1("res/com/test/SingleField.class");
    JavaClass javaClass1;
    parser1.parse(javaClass1);
    const FieldInfo *field = javaClass1.getFieldAt(0);

    ASSERT_EQ(1, field->getAttributesCount());
    const AttributeInfo* attr = field->getAttributeAt(0);
    ASSERT_EQ(CONSTANT_VALUE, attr->getType());
    ASSERT_EQ(7, ((ConstantValue*)attr)->getValueIndex());
}
