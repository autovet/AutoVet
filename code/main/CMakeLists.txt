#Setup directory paths
SET(ROOT ${CMAKE_CURRENT_SOURCE_DIR})
SET(SOURCES ${ROOT}/sources)

#Initiate source files
FILE(GLOB VET_MAIN_SOURCES ${SOURCES}/*.cpp)

#Create executable
SET(ISWINRELEASE 0)
IF(CMAKE_BUILD_TYPE STREQUAL "Release")
	IF(WIN32)
		SET(ISWINRELEASE 1)
	ENDIF()
ENDIF()

IF(${ISWINRELEASE})
	#Ensures that the console is not shown in Windows
	ADD_EXECUTABLE(autovet WIN32 ${VET_MAIN_SOURCES})
ELSE()
	ADD_EXECUTABLE(autovet ${VET_MAIN_SOURCES})
ENDIF()

TARGET_LINK_LIBRARIES(autovet vetengine)
QT5_USE_MODULES(autovet Core Gui Widgets)

#Install file
INSTALL(TARGETS autovet RUNTIME DESTINATION .)
