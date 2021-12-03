cmake_minimum_required(VERSION 3.7)

project(vgui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options (-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options (-fcolor-diagnostics)
endif ()

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_SOURCE_DIR}/sources/App.cpp
    ${CMAKE_SOURCE_DIR}/sources/Bitmap.cpp
    ${CMAKE_SOURCE_DIR}/sources/BitmapTGA.cpp
    ${CMAKE_SOURCE_DIR}/sources/Border.cpp
    ${CMAKE_SOURCE_DIR}/sources/BorderLayout.cpp
    ${CMAKE_SOURCE_DIR}/sources/BorderPair.cpp
    ${CMAKE_SOURCE_DIR}/sources/BuildGroup.cpp
    ${CMAKE_SOURCE_DIR}/sources/Button.cpp
    ${CMAKE_SOURCE_DIR}/sources/ButtonGroup.cpp
    ${CMAKE_SOURCE_DIR}/sources/CheckButton.cpp
    ${CMAKE_SOURCE_DIR}/sources/Color.cpp
    ${CMAKE_SOURCE_DIR}/sources/ConfigWizard.cpp
    ${CMAKE_SOURCE_DIR}/sources/Cursor.cpp
    ${CMAKE_SOURCE_DIR}/sources/DataInputStream.cpp
    ${CMAKE_SOURCE_DIR}/sources/Desktop.cpp
    ${CMAKE_SOURCE_DIR}/sources/DesktopIcon.cpp
    ${CMAKE_SOURCE_DIR}/sources/EditPanel.cpp
    ${CMAKE_SOURCE_DIR}/sources/EtchedBorder.cpp
    ${CMAKE_SOURCE_DIR}/sources/FileInputStream.cpp
    ${CMAKE_SOURCE_DIR}/sources/FlowLayout.cpp
    ${CMAKE_SOURCE_DIR}/sources/FocusNavGroup.cpp
    ${CMAKE_SOURCE_DIR}/sources/Font.cpp
    ${CMAKE_SOURCE_DIR}/sources/Frame.cpp
    ${CMAKE_SOURCE_DIR}/sources/GridLayout.cpp
    ${CMAKE_SOURCE_DIR}/sources/handlers
    ${CMAKE_SOURCE_DIR}/sources/HeaderPanel.cpp
    ${CMAKE_SOURCE_DIR}/sources/Image.cpp
    ${CMAKE_SOURCE_DIR}/sources/ImagePanel.cpp
    ${CMAKE_SOURCE_DIR}/sources/IntLabel.cpp
    ${CMAKE_SOURCE_DIR}/sources/Label.cpp
    ${CMAKE_SOURCE_DIR}/sources/Menu.cpp
    ${CMAKE_SOURCE_DIR}/sources/MenuItem.cpp
    ${CMAKE_SOURCE_DIR}/sources/Panel.cpp
    ${CMAKE_SOURCE_DIR}/sources/PopupMenu.cpp
    ${CMAKE_SOURCE_DIR}/sources/ProgressBar.cpp
    ${CMAKE_SOURCE_DIR}/sources/RadioButton.cpp
    ${CMAKE_SOURCE_DIR}/sources/RaisedBorder.cpp
    ${CMAKE_SOURCE_DIR}/sources/Scheme.cpp
    ${CMAKE_SOURCE_DIR}/sources/ScrollPanel.cpp
    ${CMAKE_SOURCE_DIR}/sources/Slider.cpp
    ${CMAKE_SOURCE_DIR}/sources/StackLayout.cpp
    ${CMAKE_SOURCE_DIR}/sources/String.cpp
    ${CMAKE_SOURCE_DIR}/sources/SurfaceBase.cpp
    ${CMAKE_SOURCE_DIR}/sources/Surface.cpp
    ${CMAKE_SOURCE_DIR}/sources/TablePanel.cpp
    ${CMAKE_SOURCE_DIR}/sources/TabPanel.cpp
    ${CMAKE_SOURCE_DIR}/sources/TaskBar.cpp
    ${CMAKE_SOURCE_DIR}/sources/TextEntry.cpp
    ${CMAKE_SOURCE_DIR}/sources/TextGrid.cpp
    #${CMAKE_SOURCE_DIR}/sources/TextImage.cpp
    ${CMAKE_SOURCE_DIR}/sources/TextPanel.cpp
    ${CMAKE_SOURCE_DIR}/sources/ToggleButton.cpp
    ${CMAKE_SOURCE_DIR}/sources/TreeFolder.cpp
    ${CMAKE_SOURCE_DIR}/sources/WizardPanel.cpp)
    
target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/include)