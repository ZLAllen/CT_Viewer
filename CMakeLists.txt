cmake_minimum_required(VERSION 3.16)
project(CT_Viewer VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Export compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Qt5 configuration (VTK in Debian is built against Qt5)
find_package(Qt5 REQUIRED COMPONENTS 
    Core 
    Gui 
    Widgets
)

# VTK configuration (optional - set path if installed elsewhere)
# Set VTK_DIR to your VTK installation if needed
# Example: cmake -DVTK_DIR=/path/to/vtk/build ..
find_package(VTK QUIET)
if(VTK_FOUND)
    message(STATUS "Found VTK: ${VTK_VERSION}")
else()
    message(WARNING "VTK not found. Install VTK or set VTK_DIR cmake variable.")
endif()

# ITK configuration (optional)
find_package(ITK QUIET)
if(ITK_FOUND)
    message(STATUS "Found ITK: ${ITK_VERSION}")
else()
    message(WARNING "ITK not found. Install ITK or set ITK_DIR cmake variable.")
endif()

# Source files
set(SOURCES
    CT_Viewer/main.cpp
    CT_Viewer/CT_Viewer.cpp
    CT_Viewer/entry_widget.cpp
    CT_Viewer/ct_image.cpp
    CT_Viewer/ct_2d_widget.cpp
    CT_Viewer/ct_3d_widget.cpp
    CT_Viewer/ct_contrast_widget.cpp
    CT_Viewer/ct_details_widget.cpp
    CT_Viewer/actor_list_item.cpp
    CT_Viewer/box_widget_callback.cpp
    CT_Viewer/contrast_barchart_widget.cpp
    CT_Viewer/image_register.cpp
    CT_Viewer/planting_screws.cpp
    CT_Viewer/recent_image_list_widget_item.cpp
    CT_Viewer/reslice_interaction_callback.cpp
    CT_Viewer/ScrewOptionWidget.cpp
    CT_Viewer/uiHelper.cpp
    CT_Viewer/vtkHelper.cpp
)

# UI files
set(UI_FILES
    CT_Viewer/CT_Viewer.ui
    CT_Viewer/entry_widget.ui
    CT_Viewer/ct_contrast_widget.ui
    CT_Viewer/ct_details_widget.ui
    CT_Viewer/actor_list_item.ui
    CT_Viewer/ScrewOptionWidget.ui
)

# Resource files
set(RESOURCE_FILES
    CT_Viewer/CT_Viewer.qrc
)

# Executable
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${UI_FILES}
    ${RESOURCE_FILES}
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CT_Viewer
)

# Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

# VTK libraries (if found)
if(VTK_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${VTK_LIBRARIES})
    target_include_directories(${PROJECT_NAME} PRIVATE ${VTK_INCLUDE_DIRS})
endif()

# ITK libraries (if found)
if(ITK_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ITK_LIBRARIES})
    target_include_directories(${PROJECT_NAME} PRIVATE ${ITK_INCLUDE_DIRS})
endif()

# Install rules (optional)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
