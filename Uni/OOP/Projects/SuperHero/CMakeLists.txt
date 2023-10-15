cmake_minimum_required(VERSION 3.26)
project(SuperHero)

set(CMAKE_CXX_STANDARD 14)

include_directories(Engine/Helper/Iterator)
include_directories(Engine/Helper/Iterator/BiDirectional)
include_directories(Engine/Helper/Iterator/Forward)
include_directories(Engine/Helper/Iterator/RandomAccess)
include_directories("Engine/Helper/Smart Pointer")
include_directories(Engine/Helper/String)
include_directories(Engine/Helper/Vector)
include_directories(Engine/Interface/AdminIF)
include_directories(Engine/Interface/BaseIF)
include_directories(Engine/Interface/CombinedIF)
include_directories(Engine/Interface/PlayerIF)
include_directories(Engine/System)
include_directories("Game Element/SuperHero")
include_directories("Game Element/Users/Admin")
include_directories("Game Element/Users/Base")
include_directories("Game Element/Users/Player")

add_executable(SuperHero
        Engine/Helper/Iterator/BiDirectional/BiDirectIter.hpp
        Engine/Helper/Iterator/Forward/ForwardIter.hpp
        Engine/Helper/Iterator/RandomAccess/RABaseIter.hpp
        Engine/Helper/Iterator/RandomAccess/RAReverseIter.hpp
        "Engine/Helper/Smart Pointer/SharedPtr.hpp"
        Engine/Helper/String/Helper.cpp
        Engine/Helper/String/Helper.h
        Engine/Helper/String/MyString.cpp
        Engine/Helper/String/MyString.h
        Engine/Helper/Vector/Vector.hpp
        Engine/Interface/AdminIF/AdminIF.cpp
        Engine/Interface/AdminIF/AdminIF.h
        Engine/Interface/BaseIF/BaseIF.h
        Engine/Interface/CombinedIF/CombinedIF.cpp
        Engine/Interface/CombinedIF/CombinedIF.h
        Engine/Interface/PlayerIF/PlayerIF.cpp
        Engine/Interface/PlayerIF/PlayerIF.h
        Engine/System/Const.h
        Engine/System/System.cpp
        Engine/System/System.h
        "Game Element/SuperHero/SuperHero.cpp"
        "Game Element/SuperHero/SuperHero.h"
        "Game Element/Users/Admin/Admin.cpp"
        "Game Element/Users/Admin/Admin.h"
        "Game Element/Users/Base/User.cpp"
        "Game Element/Users/Base/User.h"
        "Game Element/Users/Player/Player.cpp"
        "Game Element/Users/Player/Player.h"
        New.cpp)
