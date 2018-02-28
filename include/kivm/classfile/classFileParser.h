//
// Created by kiva on 2018/2/25.
//

#pragma once

#include <kivm/classfile/classFile.h>
#include <kivm/classfile/classFileStream.h>

namespace kivm {
    class ClassFileParser {
    public:
        static ClassFile *alloc();

        static void dealloc(ClassFile *class_file);

    private:
        ClassFile *_classFile;
        ClassFileStream _classFileStream;
        FILE *_file;

        u1 *_content;

        ClassFile *parse();

        void parse_constant_pool(ClassFile *classFile);

        void parse_interfaces(ClassFile *classFile);

        void parse_fields(ClassFile *classFile);

        void parse_methods(ClassFile *classFile);

        void parse_attributes(ClassFile *classFile);

    public:
        explicit ClassFileParser(const char *filePath);

        ~ClassFileParser();

        ClassFile *classFile();
    };
}