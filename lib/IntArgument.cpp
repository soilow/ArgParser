#include "IntArgument.h"

namespace ArgumentParser {

IntArgument::IntArgument(char short_argument) : Argument(short_argument) {}
IntArgument::IntArgument(const std::string& long_argument) : Argument(long_argument) {}
IntArgument::IntArgument(const std::string& long_argument, const std::string& description) : Argument(long_argument, description) {}
IntArgument::IntArgument(char short_argument, const std::string& long_argument) : Argument(short_argument, long_argument) {}
IntArgument::IntArgument(char short_argument, const std::string& long_argument, const std::string& description) : Argument(short_argument, long_argument, description) {}

int IntArgument::GetValue() const { return value_; }
int IntArgument::GetValue(const int& index) const {
    return external_values_->at(index);
}

bool IntArgument::GetPositional() const { return positional_; }

IntArgument& IntArgument::MultiValue() {
    this->SetUseMultiValue();
    
    return *this;
}

IntArgument& IntArgument::MultiValue(size_t min_args_count) {
    this->SetUseMultiValue(min_args_count);

    return *this;
}

IntArgument& IntArgument::Positional() {
    positional_ = true;
    
    return *this;
}

IntArgument& IntArgument::StoreValue(int& reserved) {
    SetUseExternalValue();
    external_value_ = &reserved;

    return *this;
}

IntArgument& IntArgument::StoreValues(std::vector<int>& values) {
    SetUseExternalValue();
    external_values_ = &values;
    
    return *this;
}


IntArgument& IntArgument::Default(const int& default_value) {
    this->InsertIntValue(default_value);
    this->SetDefaultState();
    
    return *this;
}


void IntArgument::InsertIntValue(const int& insertion_value) {
    if (this->GetUseMultiValue() && this->GetUseExternalValue()) {
        external_values_->push_back(insertion_value);
    } else {
        if (GetUseExternalValue()) {
            *external_value_ = insertion_value;
            value_ = *external_value_;
        } else {
            value_ = insertion_value;
        }
    }
    
    ServeArgument();
}

} // namespace ArgumentParser
