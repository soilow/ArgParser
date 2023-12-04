#include "FlagArgument.h"

namespace ArgumentParser {

// FlagArgument class
FlagArgument::FlagArgument(char short_argument) : Argument(short_argument) {}
FlagArgument::FlagArgument(const std::string& long_argument) : Argument(long_argument) {}
FlagArgument::FlagArgument(const std::string& long_argument, const std::string& description) : Argument(long_argument, description) {}
FlagArgument::FlagArgument(char short_argument, const std::string& long_argument) : Argument(short_argument, long_argument) {}
FlagArgument::FlagArgument(char short_argument, const std::string& long_argument, const std::string& description) : Argument(short_argument, long_argument, description) {}

bool FlagArgument::GetValue() const { return value_; }

void FlagArgument::SetFlag() {
    if (GetUseExternalValue()) {
        *external_value_ = true;
        value_ = *external_value_;
    } else {
        value_ = true;
    }
}
void FlagArgument::SetFlag(const bool& insertion_value) {
    if (GetUseExternalValue()) {
        *external_value_ = insertion_value;
        value_ = *external_value_;
    } else {
        value_ = insertion_value;
    }
}
void FlagArgument::UseExternalValue(bool& reserved) {
    SetUseExternalValue();
    external_value_ = &reserved;
}

void FlagArgument::InsertFlagValue() {
    this->SetFlag();
}

void FlagArgument::InsertFlagValue(bool insertion_value) {
    this->SetFlag(insertion_value);
}

FlagArgument& FlagArgument::StoreValue(bool& reserved) {
    this->UseExternalValue(reserved);
    
    return *this;
}

FlagArgument& FlagArgument::Default(bool default_value) {
    this->InsertFlagValue(default_value);
    this->SetDefaultState();

    return *this;
}

} // namespace ArgumentParser

