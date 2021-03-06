#include "vm/classpath_class_loader.h"
#include "class_file/parser/java_class_parser.h"
#include "class_file/helper/strings.h"
#include "class_file/exceptions.h"
#include "vm/exceptions.h"

using namespace avm;

ClasspathClassLoader::ClasspathClassLoader(const std::string &classpath)
    :_classpath(classpath) {

}

ClasspathClassLoader::~ClasspathClassLoader() {

}

std::string ClasspathClassLoader::getClassFilePath(const std::string &className) const {
    std::string classFile = Strings::replaceAll(className, ".", "/") + ".class";
    if (!_classpath.empty())
        classFile = _classpath + "/" + classFile;
    return classFile;
}

void ClasspathClassLoader::readClass(const std::string &className,
                                     JavaClass &out) {
    const std::string file = getClassFilePath(className);

    try {
        JavaClassParser parser(file.c_str());
        parser.parse(out);
    } catch (FileOpenFailedException ex) {
        throw ClassNotFoundException(ex.what());
    }
}
