#pragma once

#include <iostream>
#include <string>

namespace ArgumentParser {

class Argument {
public:
    Argument(char short_argument);
    Argument(const std::string& long_argument);
    Argument(const std::string& long_argument, const std::string& description);
    Argument(char short_argument, const std::string& long_argument);
    Argument(char short_argument, const std::string& long_argument, const std::string& description);

    char GetShortArgument() const;
    std::string GetLongArgument() const;
    std::string GetDescription() const;
    bool GetIsServed() const;
    
    void SetDefaultState();
    bool GetDefaultState() const;
    
    void SetUseMultiValue();
    void SetUseMultiValue(size_t min_args_count);
    bool GetUseMultiValue() const;
    
    size_t GetServedArgsCount() const;
    size_t GetMinArgsCount() const;
    
    void SetUseExternalValue();
    bool GetUseExternalValue() const;
    
    void ServeArgument();
    
private:
    char short_argument_ = '\0';
    std::string long_argument_;
    std::string description_;
    
    bool use_multivalue_ = false;
    size_t served_args_count_ = 0;
    size_t min_args_count_ = 0;
    
    bool use_default_ = false;
    bool use_external_value_ = false;
    bool is_served_ = false;
};

} // namespace ArgumentParser
