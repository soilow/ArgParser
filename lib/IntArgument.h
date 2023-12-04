#pragma once

#include "Argument.h"
#include <iostream>
#include <string>
#include <vector>

namespace ArgumentParser {

class IntArgument : public Argument {
public:
    IntArgument(char short_argument);
    IntArgument(const std::string& long_argument);
    IntArgument(const std::string& long_argument, const std::string& description);
    IntArgument(char short_argument, const std::string& long_argument);
    IntArgument(char short_argument, const std::string& long_argument, const std::string& description);
    
    int GetValue() const;
    int GetValue(const int& index) const;
    
    bool GetPositional() const;
    
    void InsertIntValue(const int& insertion_value);
    
    IntArgument& MultiValue();
    IntArgument& MultiValue(size_t min_args_count);
    IntArgument& Positional();
    IntArgument& StoreValue(int& reserved);
    IntArgument& StoreValues(std::vector<int>& values);
    IntArgument& Default(const int& default_value);
private:
    int value_ = 0;
    
    int* external_value_ = nullptr;
    std::vector<int>* external_values_ = nullptr;
    
    bool positional_ = false;
    
};

} // namespace ArgumentParser
