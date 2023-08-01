cmake_minimum_required(VERSION 3.16)

project(ChessEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appChessEngine
    main.cpp
    chesspiece.h chesspiece.cpp
    king.h king.cpp
    pawn.h pawn.cpp
    castle.h castle.cpp
    bishop.h bishop.cpp
    player.h player.cpp
    queen.h queen.cpp
    knight.h knight.cpp
    analyzer.h analyzer.cpp
    computerplayer.h computerplayer.cpp
    chessboard.h chessboard.cpp
)

qt_add_qml_module(appChessEngine
    URI ChessEngine
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(appChessEngine PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appChessEngine
    PRIVATE Qt6::Quick
)

install(TARGETS appChessEngine
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
