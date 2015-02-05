#include <sstream>
#include <string>
#include "Version.h"
#include "LibcellmlConfig.h"

const std::string libcellml::getVersion() {
    std::ostringstream os;
    os << LIBCELLML_VERSION_MAJOR << "." << LIBCELLML_VERSION_MINOR << std::endl;
    return os.str();
}
