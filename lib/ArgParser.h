#pragma once

#include "Argument.h"
#include "StringArgument.h"
#include "IntArgument.h"
#include "FlagArgument.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <string_view>

namespace ArgumentParser {

class ArgParser {
public:
    ArgParser(const std::string& parser_name_);
    
    StringArgument& AddStringArgument(char short_argument);
    StringArgument& AddStringArgument(const std::string& long_argument);
    StringArgument& AddStringArgument(const std::string& long_argument, const std::string& description);
    StringArgument& AddStringArgument(char short_argument, const std::string& long_argument);
    StringArgument& AddStringArgument(char short_argument, const std::string& long_argument, const std::string& description);
    
    IntArgument& AddIntArgument(char short_argument);
    IntArgument& AddIntArgument(const std::string& long_argument);
    IntArgument& AddIntArgument(const std::string& long_argument, const std::string& description);
    IntArgument& AddIntArgument(char short_argument, const std::string& long_argument);
    IntArgument& AddIntArgument(char short_argument, const std::string& long_argument, const std::string& description);
    
    FlagArgument& AddFlag(char short_argument);
    FlagArgument& AddFlag(const std::string& long_argument);
    FlagArgument& AddFlag(const std::string& long_argument, const std::string& description);
    FlagArgument& AddFlag(char short_argument, const std::string& long_argument);
    FlagArgument& AddFlag(char short_argument, const std::string& long_argument, const std::string& description);
    
    FlagArgument& AddHelp(char short_argument, const std::string& long_argument, const std::string& description);

    std::string GetStringValue(char short_argument) const;
    std::string GetStringValue(const std::string& long_argument) const;
    
    int GetIntValue(char short_argument) const;
    int GetIntValue(const std::string& long_argument) const;
    int GetIntValue(const std::string& argument, const int& index) const;
    
    bool GetFlag(char short_argument) const;
    bool GetFlag(const std::string& long_argument) const;
    
    bool Help() const;
    std::string HelpDescription() const;
    
    bool Parse(int argc, char** argv);
    bool Parse(std::vector<std::string> data);

private:
    std::string parser_name_;
    std::vector<StringArgument> string_arguments_;
    std::vector<IntArgument> int_arguments_;
    std::vector<FlagArgument> flag_arguments_;

    IntArgument* FindIntArgument(const std::string_view& long_required_argument);
    IntArgument* FindIntArgument(char short_required_argument);
    
    StringArgument* FindStringArgument(const std::string_view& long_required_argument);
    StringArgument* FindStringArgument(char short_required_argument);
    
    FlagArgument* FindFlagArgument(const std::string_view& long_required_argument);
    FlagArgument* FindFlagArgument(char short_required_argument);
};

} // namespace ArgumentParser
