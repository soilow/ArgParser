#include "Argument.h"

namespace ArgumentParser {

Argument::Argument(char short_argument) {
    short_argument_ = short_argument;
}

Argument::Argument(const std::string& long_argument) {
    long_argument_ = long_argument;
}

Argument::Argument(const std::string& long_argument, const std::string& description)
    : long_argument_(long_argument) {
    description_ = description;
}

Argument::Argument(char short_argument, const std::string& long_argument)
    : short_argument_(short_argument),
      long_argument_(long_argument)
{}

Argument::Argument(char short_argument, const std::string& long_argument, const std::string& description)
    : short_argument_(short_argument),
      long_argument_(long_argument),
      description_(description)
{}

char Argument::GetShortArgument() const { return short_argument_; }
std::string Argument::GetLongArgument() const { return long_argument_; }
std::string Argument::GetDescription() const { return description_; }
bool Argument::GetIsServed() const { return is_served_; }

void Argument::SetDefaultState() { use_default_ = true; }
bool Argument::GetDefaultState() const { return use_default_; }

bool Argument::GetUseMultiValue() const { return use_multivalue_; }
void Argument::SetUseMultiValue() { use_multivalue_ = true; }
void Argument::SetUseMultiValue(size_t args_count) {
    use_multivalue_ = true;
    min_args_count_ = args_count;
}

size_t Argument::GetServedArgsCount() const { return served_args_count_; }
size_t Argument::GetMinArgsCount() const { return min_args_count_; }

void Argument::SetUseExternalValue() { use_external_value_ = true; }
bool Argument::GetUseExternalValue() const { return use_external_value_; }

void Argument::ServeArgument() {
    if (!is_served_) {
        is_served_ = true;
    }
    
    if (use_multivalue_) {
        ++served_args_count_;
    }
}

} // namespace ArgumentParser
