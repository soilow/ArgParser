#include "ArgParser.h"

using namespace ArgumentParser;

// ArgParser class
ArgParser::ArgParser(const std::string& parser_name) {
    parser_name_ = parser_name;
}

StringArgument& ArgParser::AddStringArgument(char short_argument) {
    StringArgument new_argument(short_argument);

    string_arguments_.emplace_back(new_argument);

    return string_arguments_.back();
}

StringArgument& ArgParser::AddStringArgument(const std::string& long_argument) {
    StringArgument new_argument(long_argument);

    string_arguments_.emplace_back(new_argument);

    return string_arguments_.back();
}

StringArgument& ArgParser::AddStringArgument(const std::string& long_argument, const std::string& description) {
    StringArgument new_argument(long_argument, description);

    string_arguments_.emplace_back(new_argument);

    return string_arguments_.back();
}

StringArgument& ArgParser::AddStringArgument(char short_argument, const std::string& long_argument) {
    StringArgument new_argument(short_argument, long_argument);

    string_arguments_.emplace_back(new_argument);

    return string_arguments_.back();
}

StringArgument& ArgParser::AddStringArgument(char short_argument, const std::string& long_argument, const std::string& description) {
    StringArgument new_argument(short_argument, long_argument, description);

    string_arguments_.emplace_back(new_argument);

    return string_arguments_.back();
}
IntArgument& ArgParser::AddIntArgument(char short_argument) {
    IntArgument new_argument(short_argument);

    int_arguments_.emplace_back(new_argument);

    return int_arguments_.back();
}

IntArgument& ArgParser::AddIntArgument(const std::string& long_argument) {
    IntArgument new_argument(long_argument);

    int_arguments_.emplace_back(new_argument);

    return int_arguments_.back();
}

IntArgument& ArgParser::AddIntArgument(const std::string& long_argument, const std::string& description) {
    IntArgument new_argument(long_argument, description);

    int_arguments_.emplace_back(new_argument);

    return int_arguments_.back();
}

IntArgument& ArgParser::AddIntArgument(char short_argument, const std::string& long_argument) {
    IntArgument new_argument(short_argument, long_argument);

    int_arguments_.emplace_back(new_argument);

    return int_arguments_.back();
}

IntArgument& ArgParser::AddIntArgument(char short_argument, const std::string& long_argument, const std::string& description) {
    IntArgument new_argument(short_argument, long_argument, description);

    int_arguments_.emplace_back(new_argument);

    return int_arguments_.back();
}

FlagArgument& ArgParser::AddFlag(char short_argument) {
    FlagArgument new_argument(short_argument);
    
    flag_arguments_.emplace_back(new_argument);
    
    return flag_arguments_.back();
}

FlagArgument& ArgParser::AddFlag(const std::string& long_argument) {
    FlagArgument new_argument(long_argument);
    
    flag_arguments_.emplace_back(new_argument);
    
    return flag_arguments_.back();
}

FlagArgument& ArgParser::AddFlag(const std::string& long_argument, const std::string& description) {
    FlagArgument new_argument(long_argument, description);
    
    flag_arguments_.emplace_back(new_argument);
    
    return flag_arguments_.back();
}

FlagArgument& ArgParser::AddFlag(char short_argument, const std::string& long_argument) {
    FlagArgument new_argument(short_argument, long_argument);
    
    flag_arguments_.emplace_back(new_argument);
    
    return flag_arguments_.back();
}

FlagArgument& ArgParser::AddFlag(char short_argument, const std::string& long_argument, const std::string& description) {
    FlagArgument new_argument(short_argument, long_argument, description);
    
    flag_arguments_.emplace_back(new_argument);
    
    return flag_arguments_.back();
}

FlagArgument& ArgParser::AddHelp(char short_argument, const std::string& long_argument, const std::string& description) {
    FlagArgument new_argument(short_argument, long_argument, description);
    
    flag_arguments_.emplace_back(new_argument);
    
    return flag_arguments_.back();
}

StringArgument* ArgParser::FindStringArgument(const std::string_view& long_required_argument) {
    for (StringArgument& i: string_arguments_) {
        if (i.GetLongArgument() == long_required_argument) {
            return &i;
        }
    }
    
    return nullptr;
}

StringArgument* ArgParser::FindStringArgument(char short_required_argument) {
    for (StringArgument& i: string_arguments_) {
        if (i.GetShortArgument() == short_required_argument) {
            return &i;
        }
    }

    return nullptr;
}

IntArgument* ArgParser::FindIntArgument(const std::string_view& long_required_argument) {
    for (IntArgument& i: int_arguments_) {
        if (i.GetLongArgument() == long_required_argument) {
            return &i;
        }
    }
}

IntArgument* ArgParser::FindIntArgument(char short_required_argument) {
    for (IntArgument& i: int_arguments_) {
        if (i.GetShortArgument() == short_required_argument) {
            return &i;
        }
    }

    return nullptr;
}

FlagArgument* ArgParser::FindFlagArgument(const std::string_view& long_required_argument) {
    for (FlagArgument& i: flag_arguments_) {
        if (i.GetLongArgument() == long_required_argument) {
            return &i;
        }
    }

    return nullptr;
}

FlagArgument* ArgParser::FindFlagArgument(char short_required_argument) {
    for (FlagArgument& i: flag_arguments_) {
        if (i.GetShortArgument() == short_required_argument) {
            return &i;
        }
    }

    return nullptr;
}

std::string ArgParser::GetStringValue(char short_argument) const {
    for (const StringArgument& i: string_arguments_) {
        if (i.GetShortArgument() == short_argument) {
            return i.GetValue();
        }
    }
    
    std::cout << "Unknown argument: '" << short_argument << "'\n";

    return "";
}

std::string ArgParser::GetStringValue(const std::string& long_argument) const {
    for (const StringArgument& i: string_arguments_) {
        if (i.GetLongArgument() == long_argument) {
            return i.GetValue();
        }
    }
    
    std::cout << "Unknown argument: '" << long_argument << "'\n";

    return "";
}

int ArgParser::GetIntValue(char short_argument) const {
    for (const IntArgument& i: int_arguments_) {
        if (i.GetShortArgument() == short_argument) {
            return i.GetValue();
        }
    }
    
    std::cout << "Unknown argument: '" << short_argument << "'\n";
    
    return 0;
}

int ArgParser::GetIntValue(const std::string& long_argument) const {
    for (const IntArgument& i: int_arguments_) {
        if (i.GetLongArgument() == long_argument) {
            return i.GetValue();
        }
    }
    
    std::cout << "Unknown argument: '" << long_argument << "'\n";
    
    return 0;
}

int ArgParser::GetIntValue(const std::string& long_argument, const int& index) const {
    for (const IntArgument& i: int_arguments_) {
        if (i.GetLongArgument() == long_argument) {
            return i.GetValue(index);
        }
    }
    
    std::cout << "Unknown argument: '" << long_argument << "'\n";
    
    return 0;
}

bool ArgParser::GetFlag(char short_argument) const {
    for (const FlagArgument& i: flag_arguments_) {
        if (i.GetShortArgument() == short_argument) {
            return i.GetValue();
        }
    }
    
    std::cout << "Unknown argument: '" << short_argument << "'\n";
    
    return false;
}

bool ArgParser::GetFlag(const std::string& long_argument) const {
    for (const FlagArgument& i: flag_arguments_) {
        if (i.GetLongArgument() == long_argument) {
            return i.GetValue();
        }
    }
    
    std::cout << "Unknown argument: '" << long_argument << "'\n";
    
    return false;
}


bool ArgParser::Help() const {
    return GetFlag("help");
}

std::string ArgParser::HelpDescription() const {
    std::stringstream ss;
    
    ss << parser_name_ << '\n';
    
    for (FlagArgument i: flag_arguments_) {
        if (i.GetLongArgument() == "help") {
            ss << i.GetDescription() << '\n';
        }
    }

    ss << '\n';

    for (const StringArgument& i: string_arguments_) {
        if (i.GetShortArgument() != '\0') {
            ss << "-" << i.GetShortArgument() << "=<string>, ";
        }
        if (i.GetLongArgument() != "") {
            ss << "--" << i.GetLongArgument() << "=<string>, ";
        }
        if (i.GetDescription() != "") {
            ss << i.GetDescription() << " ";
        }
        if (i.GetUseMultiValue()) {
            ss << "[repeated, min args = " << i.GetMinArgsCount() << "] ";
        }
        if (i.GetDefaultState()) {
            ss << "[default = " << i.GetValue() << "] ";
        }

        ss << '\n';
    }

    for (const FlagArgument& i: flag_arguments_) {
        if (i.GetShortArgument() != '\0') {
            if (i.GetShortArgument() == 'h') { continue; }

            ss << "-" << i.GetShortArgument() << ", ";
        }
        if (i.GetLongArgument() != "") {
            if (i.GetLongArgument() == "help") { continue; }

            ss << "-" << i.GetLongArgument() << ", ";
        }
        if (i.GetDescription() != "") {
            ss << i.GetDescription() << " ";
        }
        if (i.GetUseMultiValue()) {
            ss << "[repeated, min args = " << i.GetMinArgsCount() << "] ";
        }
        if (i.GetDefaultState()) {
            ss << "[default = ";

            if (i.GetValue()) {
                ss << "true";
            } else {
                ss << "false";
            }

            ss << "] ";
        }
        
        ss << '\n';
    }

    for (const IntArgument& i: int_arguments_) {
        if (i.GetShortArgument() != '\0') {
            ss << "-" << i.GetShortArgument() << "=<int>, ";
        }
        if (i.GetLongArgument() != "") {
            ss << "--" << i.GetLongArgument() << "=<int>, ";
        }
        if (i.GetDescription() != "") {
            ss << i.GetDescription() << " ";
        }
        if (i.GetUseMultiValue()) {
            ss << "[repeated, min args = " << i.GetMinArgsCount() << "] ";
        }
        if (i.GetDefaultState()) {
            ss << "[default = " << i.GetValue() << "] ";
        }

        ss << '\n';
    }

    ss << "\n";
    ss << "-h, --help, Display this help and exit\n";

    return ss.str();
}


bool ArgParser::Parse(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string_view command (argv[i]);

        if (command.starts_with("--")) {
            // Long argument
            const size_t equals_sign_position = command.find('=');
            std::string_view argument = command.substr(2, equals_sign_position-2);

            if (equals_sign_position == -1) {
                // Process Flag arguments
                if (FlagArgument* required_argument = FindFlagArgument(argument)) {
                    required_argument->InsertFlagValue();
                } else {
                    std::cout << "The '" << argument << "' argument doesn't exist\n";
                    exit(1);
                }

                if (argument == "help") {
                    return true;
                }
            } else {
                // Process String or Int arguments
                std::string_view value = command.substr(equals_sign_position + 1);

                if (isdigit(value[0])) {
                    // Int
                    if (IntArgument* required_argument = FindIntArgument(argument)) {
                        required_argument->InsertIntValue(stoi(std::string(value)));
                    } else {
                        std::cout << "The '" << argument << "' argument doesn't exist\n";
                        exit(1);
                    }
                } else {
                    // String
                    if (StringArgument* required_argument = FindStringArgument(argument)) {
                        required_argument->InsertStringValue(std::string(value));
                    } else {
                        std::cout << "The '" << argument << "' argument doesn't exist\n";
                        exit(1);
                    }
                }
            }
        } else if (command.starts_with("-")) {
            // Short argument
            const size_t equals_sign_position = command.find('=');

            if (equals_sign_position == -1) {
                // Process Flag arguments
                const char* argument = &argv[i][1];

                while (*argument != '\0') {
                    if (FlagArgument* required_argument = FindFlagArgument(*argument)) {
                        required_argument->InsertFlagValue();
                    } else {
                        std::cout << "The '" << *argument << "' argument doesn't exist\n";
                        exit(1);
                    }

                    if (*argument == 'h') {
                        return true;
                    }

                    ++argument;
                }
            } else {
                // Process String or Int arguments
                char argument = argv[i][1];
                std::string_view value = command.substr(equals_sign_position + 1);
                
                if (isdigit(value[0])) {
                    if (IntArgument* required_argument = FindIntArgument(argument)) {
                        required_argument->InsertIntValue(stoi(std::string(value)));
                    } else {
                        std::cout << "The '" << argument << "' argument doesn't exist\n";
                        exit(1);
                    }
                } else {
                    if (StringArgument* required_argument = FindStringArgument(argument)) {
                        required_argument->InsertStringValue(std::string(value));
                    } else {
                        std::cout << "The '" << argument << "' argument doesn't exist\n";
                        exit(1);
                    }
                }
            }
        } else if (isdigit(argv[i][0])) {
            // positional
            IntArgument* positional_arg = &int_arguments_.back();
            
            if (positional_arg->GetPositional()) {
                int value = stoi(std::string(command));
                positional_arg->InsertIntValue(value);
            } else {
                std::cout << "Positional argument undefined.\n";
                exit(1);
            }
        } else {
            std::cout << "Error occured. Please try again.\n";
            exit(1);
        }
    }


    // Error checks

    if (string_arguments_.size() != 0) {
        for (StringArgument& i: string_arguments_) {
            if (!i.GetIsServed()) {
                return false;
            }
        }
    }
    if (int_arguments_.size() != 0) {
        for (IntArgument& i: int_arguments_) {
            if (!i.GetIsServed()) {
                return false;
            }

            if (i.GetMinArgsCount() > i.GetServedArgsCount()) {
                return false;
            }
        }
    }
    
    return true;
}

bool ArgParser::Parse(std::vector<std::string> data) {
    for (int i = 1; i < data.size(); i++) {
        std::string_view command (data[i]);

        if (command.starts_with("--")) {
            // Long argument
            const size_t equals_sign_position = command.find('=');
            std::string_view argument = command.substr(2, equals_sign_position-2);

            if (equals_sign_position == -1) {
                // Process Flag arguments
                if (FlagArgument* required_argument = FindFlagArgument(argument)) {
                    required_argument->InsertFlagValue();
                } else {
                    std::cout << "The '" << argument << "' argument doesn't exist\n";
                    exit(1);
                }

                if (argument == "help") {
                    return true;
                }
            } else {
                // Process String or Int arguments
                std::string_view value = command.substr(equals_sign_position + 1);

                if (isdigit(value[0])) {
                    // Int
                    if (IntArgument* required_argument = FindIntArgument(argument)) {
                        required_argument->InsertIntValue(stoi(std::string(value)));
                    } else {
                        std::cout << "The '" << argument << "' argument doesn't exist\n";
                        exit(1);
                    }
                } else {
                    // String
                    if (StringArgument* required_argument = FindStringArgument(argument)) {
                        required_argument->InsertStringValue(std::string(value));
                    } else {
                        std::cout << "The '" << argument << "' argument doesn't exist\n";
                        exit(1);
                    }
                }
            }
        } else if (command.starts_with("-")) {
            // Short argument
            const size_t equals_sign_position = command.find('=');

            if (equals_sign_position == -1) {
                // Process Flag arguments
                const char* argument = &data[i][1];

                while (*argument != '\0') {
                    if (FlagArgument* required_argument = FindFlagArgument(*argument)) {
                        required_argument->InsertFlagValue();
                    } else {
                        std::cout << "The '" << *argument << "' argument doesn't exist\n";
                        exit(1);
                    }

                    if (*argument == 'h') {
                        return true;
                    }

                    ++argument;
                }
            } else {
                // Process String or Int arguments
                char argument = data[i][1];
                std::string_view value = command.substr(equals_sign_position + 1);
                
                if (isdigit(value[0])) {
                    if (IntArgument* required_argument = FindIntArgument(argument)) {
                        required_argument->InsertIntValue(stoi(std::string(value)));
                    } else {
                        std::cout << "The '" << argument << "' argument doesn't exist\n";
                        exit(1);
                    }
                } else {
                    if (StringArgument* required_argument = FindStringArgument(argument)) {
                        required_argument->InsertStringValue(std::string(value));
                    } else {
                        std::cout << "The '" << argument << "' argument doesn't exist\n";
                        exit(1);
                    }
                }
            }
        } else if (isdigit(data[i][0])) {
            // positional
            IntArgument* positional_arg = &int_arguments_.back();
            
            if (positional_arg->GetPositional()) {
                int value = stoi(std::string(command));
                positional_arg->InsertIntValue(value);
            } else {
                std::cout << "Positional argument undefined.\n";
                exit(1);
            }
        } else {
            std::cout << "Error occured. Please try again.\n";
            exit(1);
        }
    }


    // Error checks

    if (string_arguments_.size() != 0) {
        for (StringArgument& i: string_arguments_) {
            if (!i.GetIsServed()) {
                return false;
            }
        }
    }
    if (int_arguments_.size() != 0) {
        for (IntArgument& i: int_arguments_) {
            if (!i.GetIsServed()) {
                return false;
            }

            if (i.GetMinArgsCount() > i.GetServedArgsCount()) {
                return false;
            }
        }
    }
    
    return true;
}
