cmake_minimum_required(VERSION 3.16)

project(ChessEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appChessEngine
    main.cpp
    application.qrc
    Pieces/chesspiece.h Pieces/chesspiece.cpp
    Pieces/king.h Pieces/king.cpp
    Pieces/pawn.h Pieces/pawn.cpp
    Pieces/castle.h Pieces/castle.cpp
    Pieces/bishop.h Pieces/bishop.cpp
    GameLogic/player.h GameLogic/player.cpp
    Pieces/queen.h Pieces/queen.cpp
    Pieces/knight.h Pieces/knight.cpp
    Analyzer/analyzer.h Analyzer/analyzer.cpp
    GameLogic/computerplayer.h GameLogic/computerplayer.cpp
    GameLogic/chessboard.h GameLogic/chessboard.cpp
)

qt_add_qml_module(appChessEngine
    URI ChessEngine
    VERSION 1.0
    QML_FILES UserInterface/Main.qml UserInterface/ChessMode.qml UserInterface/Settings.qml
    UserInterface/BoardView.qml UserInterface/StartMenu.qml UserInterface/GameMenu.qml
    UserInterface/Player.qml
    SOURCES GameLogic/chessboard.h GameLogic/chessboard.cpp
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
