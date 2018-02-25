//
// Created by kiva on 2018/2/26.
//

#include <kivm/classFile.h>
#include <kivm/classFileParser.h>

namespace kivm {

    field_info::field_info() {
        this->attributes = nullptr;
        this->attributes_count = 0;
    }

    field_info::~field_info() {
        ClassFileParser::dealloc_attributes(&attributes, attributes_count);
    }

    void field_info::init(ClassFileStream &stream, cp_info **constant_pool) {
        access_flags = stream.get_u2();
        name_index = stream.get_u2();
        descriptor_index = stream.get_u2();
        attributes_count = stream.get_u2();
        ClassFileParser::read_attributes(&attributes, attributes_count,
                                         stream, constant_pool);
    }

    method_info::method_info() {
        this->attributes = nullptr;
        this->attributes_count = 0;
    }

    method_info::~method_info() {
        ClassFileParser::dealloc_attributes(&attributes, attributes_count);
    }

    void method_info::init(ClassFileStream &stream, cp_info **constant_pool) {
        access_flags = stream.get_u2();
        name_index = stream.get_u2();
        descriptor_index = stream.get_u2();
        attributes_count = stream.get_u2();
        ClassFileParser::read_attributes(&attributes, attributes_count,
                                         stream, constant_pool);
    }
}
