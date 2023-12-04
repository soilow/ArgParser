#include "Argument.h"

#include <iostream>
#include <string>

namespace ArgumentParser {

class StringArgument : public Argument {
public:
    StringArgument(char short_argument);
    StringArgument(const std::string& long_argument);
    StringArgument(const std::string& long_argument, const std::string& description);
    StringArgument(char short_argument, const std::string& long_argument);
    StringArgument(char short_argument, const std::string& long_argument, const std::string& description);

    std::string GetValue() const;
    void InsertStringValue(const std::string& insertion_value);
    
    StringArgument& StoreValue(std::string& reserved);
    StringArgument& Default(const std::string& default_value);
    StringArgument& MultiValue(size_t min_args_count);
private:
    std::string value_;
    std::string* external_value_ = nullptr;
};

} // namespace ArgumentParser
