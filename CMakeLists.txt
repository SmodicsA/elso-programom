cmake_minimum_required(VERSION 3.19)
project(HelloWorldConsole LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(HelloWorldConsole
    main.cpp
)

target_link_libraries(HelloWorldConsole
    PRIVATE
        Qt::Core
)

install(TARGETS HelloWorldConsole
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Csak Windows-on fusson le, és csak Release módban
if(WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
    # Megkeressük a windeployqt programot
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_DEPLOY_PREFIX}/bin")

    if(WINDEPLOYQT_EXECUTABLE)
        # Olyan helyre tesszük a DLL-eket, ahol az EXE valójában létrejön
        add_custom_command(TARGET HelloWorldConsole POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} --dir "$<TARGET_FILE_DIR:HelloWorldConsole>" "$<TARGET_FILE:HelloWorldConsole>"
            COMMENT "Automatikus Qt DLL masolas folyamatban..."
        )
    endif()
endif()