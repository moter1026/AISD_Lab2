﻿# CMakeList.txt: проект CMake для Lab1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
project(Lab2 CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Lab2 "AISD Lab2.cpp" "AISD Lab2.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
