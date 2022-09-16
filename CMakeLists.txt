cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(bomberman)

# Dependencies
find_package(raylib 4.0.0 QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
	include(FetchContent)
	FetchContent_Declare(
			raylib
			URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
	)
	FetchContent_GetProperties(raylib)
	if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
		set(FETCHCONTENT_QUIET NO)
		FetchContent_Populate(raylib)
		set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
		add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
	endif()
endif()

# Créé des variables avec les fichiers à compiler
set(SRCS
        main.cpp
		ECS/EntityManager.cpp
		MyRaylib.cpp
		HelpDeveloppement/Developpement.cpp
		BomberManInit.cpp
		SpriteInit.cpp
		GameInit.cpp)

set(HEADERS
		ECS/ECS.hpp
		ECS/Entity.hpp
		ECS/Transform.hpp
        ECS/Component.hpp
		ECS/EntityManager.hpp
		ECS/SpriteRenderer.hpp
		ECS/SpriteRendererPlus.hpp
		ECS/ModelRenderer.hpp
		ECS/GeometricRenderer.hpp
		ECS/GeoAnimationRenderer.hpp
		ECS/PlayerComponent.hpp
		ECS/CameraECS.hpp
		MyRaylib.hpp
		HelpDeveloppement/BooleanCondition.hpp
		HelpDeveloppement/Developpement.hpp
		HelpDeveloppement/Gestion.hpp
		HelpDeveloppement/PositionRect.hpp
		HelpDeveloppement/PositionText.hpp
		HelpDeveloppement/RectangleDev.hpp
		HelpDeveloppement/Text.hpp
		BomberMan.hpp
		Menu.hpp)

set(CMAKE_C_STANDARD 11) # Requires C11 standard

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS} ${RESOURCE_FILES})

target_link_libraries(${PROJECT_NAME} raylib)


file(GLOB RESSOURCE_CHESS_IQM
		Models/ChessBoard/IQM/*.iqm)
file(GLOB RESSOURCE_CHESS_PNG
		Models/ChessBoard/PNG/*.png)
file(GLOB RESSOURCE_DRACO_IQM
		Models/skDraco/IQM/*.iqm)
file(GLOB RESSOURCE_DRACO_PNG
		Models/skDraco/PNG/*.png)
file(GLOB RESSOURCE_GREATHALL_IQM
		Models/GreatHall/IQM/*.iqm)
file(GLOB RESSOURCE_GREATHALL_PNG
		Models/GreatHall/PNG/*.png)
file(GLOB RESSOURCE_ASSETS_PNG
		Models/assets/*.png)
file(GLOB RESSOURCE_TRIBUNE_IQM
		Models/Tribune/IQM/*.iqm)
file(GLOB RESSOURCE_TRIBUNE_PNG
		Models/Tribune/PNG/*.png)
file(GLOB RESSOURCE_PNJ0_IQM
		Models/GenMale/Gryffinder/0/IQM/*.iqm)
file(GLOB RESSOURCE_PNJ0_PNG
		Models/GenMale/Gryffinder/0/PNG/*.png)
file(GLOB RESSOURCE_PNJ1_IQM
		Models/GenMale/Gryffinder/1/IQM/*.iqm)
file(GLOB RESSOURCE_PNJ1_PNG
		Models/GenMale/Gryffinder/1/PNG/*.png)
file(GLOB RESSOURCE_DUMBLEDORE_IQM
		Models/Dumbledore/IQM/*.iqm)
file(GLOB RESSOURCE_DUMBLEDORE_PNG
		Models/Dumbledore/PNG/*.png)
file(GLOB RESSOURCE_MCGONAGAL_IQM
		Models/McGonagal/IQM/*.iqm)
file(GLOB RESSOURCE_MCGONAGAL_PNG
		Models/McGonagal/PNG/*.png)
file(GLOB ENTITIESDATANEWGAME
		EntitiesDataNewGame/*)

file(COPY ${RESSOURCE_ASSETS_PNG} DESTINATION "Models/assets/.")
file(COPY ${RESSOURCE_CHESS_IQM} DESTINATION "Models/ChessBoard/IQM/.")
file(COPY ${RESSOURCE_CHESS_PNG} DESTINATION "Models/ChessBoard/PNG/.")
file(COPY ${RESSOURCE_DRACO_IQM} DESTINATION "Models/skDraco/IQM/.")
file(COPY ${RESSOURCE_DRACO_PNG} DESTINATION "Models/skDraco/PNG/.")
file(COPY ${RESSOURCE_GREATHALL_IQM} DESTINATION "Models/GreatHall/IQM/.")
file(COPY ${RESSOURCE_GREATHALL_PNG} DESTINATION "Models/GreatHall/PNG/.")
file(COPY ${RESSOURCE_TRIBUNE_IQM} DESTINATION "Models/Tribune/IQM/.")
file(COPY ${RESSOURCE_TRIBUNE_PNG} DESTINATION "Models/Tribune/PNG/.")
file(COPY ${RESSOURCE_PNJ0_IQM} DESTINATION "Models/GenMale/Gryffinder/0/IQM/.")
file(COPY ${RESSOURCE_PNJ0_PNG} DESTINATION "Models/GenMale/Gryffinder/0/PNG/.")
file(COPY ${RESSOURCE_PNJ1_IQM} DESTINATION "Models/GenMale/Gryffinder/1/IQM/.")
file(COPY ${RESSOURCE_PNJ1_PNG} DESTINATION "Models/GenMale/Gryffinder/1/PNG/.")
file(COPY ${ENTITIESDATANEWGAME} DESTINATION "EntitiesDataNewGame/.")
file(COPY ${RESSOURCE_DUMBLEDORE_PNG} DESTINATION "Models/Dumbledore/PNG/.")
file(COPY ${RESSOURCE_DUMBLEDORE_IQM} DESTINATION "Models/Dumbledore/IQM/.")
file(COPY ${RESSOURCE_MCGONAGAL_PNG} DESTINATION "Models/McGonagal/PNG/.")
file(COPY ${RESSOURCE_MCGONAGAL_IQM} DESTINATION "Models/McGonagal/IQM/.")

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
	target_link_libraries(${PROJECT_NAME} "-framework IOKit")
	target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
	target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrit par les variables SRCS et HEADERS

