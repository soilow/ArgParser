add_library(argument Argument.cpp Argument.h)
add_library(stringargument StringArgument.cpp StringArgument.h)
add_library(intargument IntArgument.cpp IntArgument.h)
add_library(argparser ArgParser.cpp ArgParser.h)
add_library(flagargument FlagArgument.cpp FlagArgument.h)

target_link_libraries(argparser argument stringargument intargument flagargument)
