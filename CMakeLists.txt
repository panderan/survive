CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

PROJECT(Calculator)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTOUIC_SEARCH_PATHS ui)
SET(CMAKE_AUTORCC ON)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFALGS} -O0 -Wall -g -ggdb")
SET(CMAKE_C_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFALGS} -O2 -Wall")
SET(CMAKE_C_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})

###################################################################
# FIND_PACKAGE(Qt5Widgets)                                        #
# FIND_PACKAGE(Qt5Gui)                                            #
#                                                                 #
# SET(SRCS                                                        #
#             src/main.cpp                                        #
#             src/calculator.cpp                                  #
#             src/eval/expression_eval.c                          #
#             )                                                   #
# SET(HEADERS                                                     #
#             src/calculator.h                                    #
#             src/eval/expression_eval.h)                         #
# SET(RESOURCES                                                   #
#             resources/res.qrc)                                  #
#                                                                 #
# ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS} ${HEADERS} ${RESOURCES}) #
# INCLUDE_DIRECTORIES(src/eval)                                   #
# TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Widgets Qt5::Gui)    #
###################################################################

ENABLE_TESTING()
ADD_SUBDIRECTORY(test)

