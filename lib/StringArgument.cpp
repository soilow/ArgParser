#include "StringArgument.h"

namespace ArgumentParser {

StringArgument::StringArgument(char short_argument) : Argument(short_argument) {}
StringArgument::StringArgument(const std::string& long_argument) : Argument(long_argument) {}
StringArgument::StringArgument(const std::string& long_argument, const std::string& description) : Argument(long_argument, description) {}
StringArgument::StringArgument(char short_argument, const std::string& long_argument) : Argument(short_argument, long_argument) {}
StringArgument::StringArgument(char short_argument, const std::string& long_argument, const std::string& description) : Argument(short_argument, long_argument, description) {}

std::string StringArgument::GetValue() const { return value_; }

void StringArgument::InsertStringValue(const std::string& insertion_value) {
    if (GetUseExternalValue()) {
        *external_value_ = insertion_value;
        value_ = *external_value_;
    } else {
        value_ = insertion_value;
    }

    ServeArgument();
}

StringArgument& StringArgument::StoreValue(std::string& reserved) {    
    SetUseExternalValue();
    external_value_ = &reserved;

    return *this;
}

StringArgument& StringArgument::Default(const std::string& default_value) {
    this->InsertStringValue(default_value);
    this->SetDefaultState();

    return *this;
}

StringArgument& StringArgument::MultiValue(size_t min_args_count) {
    this->SetUseMultiValue(min_args_count);

    return *this;
}






} // namespace ArgumentParser
