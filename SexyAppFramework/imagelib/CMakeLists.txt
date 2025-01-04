################################################################################
# libjpg external project
################################################################################

include(ExternalProject)

# support for windowsq
find_package(JPEG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE JPEG::JPEG ZLIB::ZLIB PNG::PNG)

target_sources(${PROJECT_NAME} PRIVATE
    "ImageLib.cpp"
    "ImageLib.h"
)
