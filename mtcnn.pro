#-------------------------------------------------
#
# Project created by QtCreator 2018-12-04T14:47:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 5640_linux_qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp\
        mtcnn.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
ZYNQ_LIB=/opt/alinx/opencv_zynq_lib
HOST_LIB=/opt/alinx/opencv_host_lib

INCLUDEPATH +=$$ZYNQ_LIB/include
if(contains(DEFINES,zynq)){
    message("compile for zynq")
    QMAKE_LIBDIR_FLAGS +=-L$$ZYNQ_LIB/lib

    LIBS += \
    -lz  \
    -lv4l2\
    -lv4l1\
    -lv4lconvert\
    -lavcodec \
    -lavformat \
    -lavutil \
    -lswscale \
    -lswresample \
    -lx264\
    -lxvidcore\
    -lpng \
    -ljpeg \
    -ltiff \

}else{
    message("compile for host")
    QMAKE_LIBDIR_FLAGS +=-L$$HOST_LIB/lib
}

LIBS += \
    -lopencv_shape \
    -lopencv_stitching \
    -lopencv_objdetect \
    -lopencv_superres \
    -lopencv_videostab \
    -lopencv_calib3d \
    -lopencv_features2d \
    -lopencv_highgui \
    -lopencv_videoio \
    -lopencv_imgcodecs \
    -lopencv_video \
    -lopencv_photo \
    -lopencv_ml \
    -lopencv_imgproc \
    -lopencv_flann \
    -lopencv_core \
    -ldl  \
#INCLUDEPATH += /mnt/workspace/depends/opencv/opencv/include/

INCLUDEPATH += -L/home/zgh/ncnn/build-arm-linux-gnueabihf/install/include/

#LIBS += -L/mnt/workspace/depends/opencv/opencv/lib/ -lopencv_imgcodecs -lopencv_imgproc -lopencv_core -lopencv_highgui \
#	-L/mnt/workspace/depends/opencv/opencv/share/OpenCV/3rdparty/lib/ -lzlib -llibjasper -llibjpeg -fopenmp

LIBS += -L/home/zgh/ncnn/build-arm-linux-gnueabihf/install/lib -lncnn
