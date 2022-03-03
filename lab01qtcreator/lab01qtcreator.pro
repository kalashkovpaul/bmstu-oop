QT       += core gui opengl openglextensions

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 object_parallel_to_source

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Canvas.cpp \
    MainWindow.cpp \
    edges.cpp \
    error.cpp \
    execute.cpp \
    main.cpp \
    model.cpp \
    read.cpp \
    screen.cpp \
    transform.cpp \
    vector3d.cpp

HEADERS += \
    Canvas.hpp \
    MainWindow.hpp \
    command.hpp \
    edges.hpp \
    error.hpp \
    execute.hpp \
    global.hpp \
    model.hpp \
    read.hpp \
    screen.hpp \
    transform.hpp \
    transformMeta.hpp \
    vector2d.hpp \
    vector3d.hpp

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/archimedean/cuboctahedron.txt \
    data/archimedean/icosidodecahedron.txt \
    data/archimedean/rhombicosidodecahedron.txt \
    data/archimedean/rhombicuboctahedron.txt \
    data/archimedean/rhombitruncated_cuboctahedron.txt \
    data/archimedean/rhombitruncated_icosidodecahedron.txt \
    data/archimedean/snub_cube.txt \
    data/archimedean/snub_dodecahedron.txt \
    data/archimedean/truncated_cube.txt \
    data/archimedean/truncated_dodecahedron.txt \
    data/archimedean/truncated_icosahedron.txt \
    data/archimedean/truncated_octahedron.txt \
    data/archimedean/truncated_tetrahedron.txt \
    data/kepler-poinsot/great_dodecahedron.txt \
    data/kepler-poinsot/great_icosahedron.txt \
    data/kepler-poinsot/great_stellated_dodecahedron.txt \
    data/kepler-poinsot/small_stellated_dodecahedron.txt \
    data/platonic/cube.txt \
    data/platonic/dodecahedron.txt \
    data/platonic/icosahedron.txt \
    data/platonic/octahedron.txt \
    data/platonic/tetrahedron.txt \
    data/self-intersecting snub quasi-regular/great_dirhombicosidodecahedron.txt
