#pragma once

#include "Argument.h"
#include <iostream>
#include <string>

namespace ArgumentParser {

class FlagArgument : public Argument {
public:
    FlagArgument(char short_argument);
    FlagArgument(const std::string& long_argument);
    FlagArgument(const std::string& long_argument, const std::string& description);
    FlagArgument(char short_argument, const std::string& long_argument);
    FlagArgument(char short_argument, const std::string& long_argument, const std::string& description);
    
    bool GetValue() const;
    
    void SetFlag();
    void SetFlag(const bool& insertion_value);
    
    void UseExternalValue(bool& reserved);
    
    void InsertFlagValue();
    void InsertFlagValue(bool insertion_value);
    
    
    FlagArgument& StoreValue(bool& reserved);
    FlagArgument& Default(bool default_value);
    
private:
    bool value_ = false;
    
    bool* external_value_ = nullptr;
};

} // namespace ArgumentParser
