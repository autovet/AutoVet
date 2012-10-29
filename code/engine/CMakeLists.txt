#Setup directory paths
SET(ROOT ${CMAKE_CURRENT_SOURCE_DIR})
SET(HEADERS ${ROOT}/headers)
SET(SOURCES ${ROOT}/sources)

#Initiate source files
FILE(GLOB VET_ENGINE_SOURCES ${SOURCES}/*.cpp ${SOURCES}/*/*.cpp)
FILE(GLOB VET_ENGINE_HEADERS ${HEADERS}/*.h ${HEADERS}/*/*.h)

#Create library
ADD_LIBRARY(vetengine SHARED ${VET_ENGINE_HEADERS} ${VET_ENGINE_SOURCES})
QT5_USE_MODULES(vetengine Core Sql)

#Install file
INSTALL(TARGETS vetengine DESTINATION .)
