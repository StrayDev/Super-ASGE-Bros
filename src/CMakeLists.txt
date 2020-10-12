## local variable for managing the game target
set(GAME ${PROJECT_NAME})

## glob is useful but not reliant in compilation so just use it for headers ##
file(GLOB_RECURSE HEADER_LIST
        LIST_DIRECTORIES FALSE
        CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/src/game/*.hpp
        ${CMAKE_SOURCE_DIR}/src/game/*.h)

## the ASGE Game, which spawns the Game window ##
add_executable(
        ${GAME} ${HEADER_LIST}
        ## source code files for app here ##
        game/core/main.cpp
        game/core/game.cpp game/core/input.cpp
        game/core/input.h game/gamestates/gamestate.cpp
        game/components/component.cpp
        game/components/component.h
        game/gameobjects/gameobject.cpp
        game/gameobjects/gameobject.h
        game/gamestates/gamestate.h
        game/gamestates/menu.cpp
        game/gamestates/menu.h
        game/gamestates/startup.cpp
        game/gamestates/startup.h
        game/gamestates/playing.cpp
        game/gamestates/playing.h
        game/levels/grid.cpp
        game/levels/grid.h
        game/levels/leveldata.cpp
        game/levels/leveldata.h
        game/math/vector2.cpp
        game/math/vector2.h
        game/components/transform.cpp game/components/transform.h game/core/gamedata.cpp game/core/gamedata.h game/components/RenderComponent.cpp game/components/RenderComponent.h game/components/spriterenderer.cpp game/components/spriterenderer.h game/core/savesystem.cpp game/core/savesystem.h game/levels/cell.cpp game/levels/cell.h)

## configure the target ##
configure_target(${GAME} ${CMAKE_CURRENT_SOURCE_DIR} "${HEADER_LIST}")

## link against ASGE and pthreads ##
add_asge_dependency(${GAME})
target_link_libraries(${GAME} PRIVATE ${CMAKE_DL_LIBS} pthread)

## game data ##
add_gamedata(${GAME} ${CMAKE_SOURCE_DIR}/data)
