cmake_minimum_required(VERSION 3.14)
project(lab03)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCES
        main.cpp
        commands/commands.cpp
        exceptions/BaseException.cpp
        exceptions/sceneExceptions.cpp
        exceptions/uploadExceptions.cpp
        Facade/Facade.cpp
        gui/drawers.cpp
        gui/mainwindow.cpp
        managers/CameraManager.cpp
        managers/DrawManager.cpp
        managers/ModelManager.cpp
        managers/UploadManager.cpp
        objects/Camera.cpp
        objects/CompositeObject.cpp
        objects/InvisibleObject.cpp
        objects/Model.cpp
        objects/VisibleObject.cpp
        Scene/Scene.cpp
        transformations/cameraCommands.cpp
        transformations/dimensionalTransformations.cpp
        transformations/Transformation.cpp
        transformations/ITransformation.cpp
        uploaders/Uploader.cpp
        visitors/DrawVisitor.cpp
        exceptions/modelViewExceptions.cpp
        ModelView/ModelView.cpp
        creators/creators.cpp
        exceptions/CreationException.cpp
)

set(HEADERS
        commands/commands.hpp
        containers/Matrix/Matrix.h
        containers/Matrix/Matrix.hpp
        containers/RectangularMatrix/RectangularMatrix.h
        containers/RectangularMatrix/RectangularMatrix.hpp
        containers/Vector/Vector.hpp
        containers/Vector/Vector.hpp
        exceptions/BaseException.hpp
        exceptions/sceneExceptions.hpp
        exceptions/uploadExceptions.hpp
        Facade/Facade.hpp
        gui/drawers.hpp
        gui/mainwindow.hpp
        managers/CameraManager.hpp
        managers/DrawManager.hpp
        managers/ModelManager.hpp
        managers/UploadManager.hpp
        math3D/Edge/Edge.h
        math3D/Edge/Edge.hpp
        math3D/Matrix4x4/Matrix4x4.h
        math3D/Matrix4x4/Matrix4x4.hpp
        math3D/Point3D/Point3D.h
        math3D/Point3D/Point3D.hpp
        math3D/Vector4D/Vector4D.h
        math3D/Vector4D/Vector4D.hpp
        objects/Camera.hpp
        objects/CompositeObject.hpp
        objects/InvisibleObject.hpp
        objects/Model.hpp
        objects/SceneObject.hpp
        objects/VisibleObject.hpp
        Scene/Scene.hpp
        transformations/BaseTransformation.hpp
        transformations/cameraCommands.hpp
        transformations/dimensionalTransformations.hpp
        transformations/ITransformation.hpp
        transformations/Transformation.hpp
        uploaders/BaseUploader.hpp
        uploaders/Uploader.hpp
        visitors/Visitor.hpp
        visitors/DrawVisitor.hpp
        exceptions/modelViewExceptions.hpp
        ModelView/ModelView.hpp
        creators/creators.hpp
        exceptions/CreationException.hpp
)

add_executable(lab03 ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)