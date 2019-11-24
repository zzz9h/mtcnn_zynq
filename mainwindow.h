#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//qt header file
#include <QMainWindow>
#include<QFileDialog>
#include<QPixmap>
#include<QImage>
#include<QLabel>
#include <QTimer>
#include <QThread>
//linux header file
#include <string.h>
#include <assert.h>
#include <getopt.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "mtcnn.h"

#define CAMERA_DEVICE "/dev/axivdma_dev0"
#define CAMERA_ov5640_0_DEVICE "/dev/sccb.cam0ov5640"

#define VDMA_BUF_SIZE  32*1024*1024

#define RD_S2MM_VSIZE _IOR('h',1,int)//vsize   480
#define RD_S2MM_HSIZE _IOR('h',2,int)//hsize   640*3 => 24bit  640*4 => 32bit
#define RD_S2MM_FRAME_STRIDE _IOR('h',3,int)//frame stride  640*3 => 24bit 640*4 => 32bit
#define WR_S2MM_VSIZE _IOW('h',4,int)
#define WR_S2MM_HSIZE _IOW('h',5,int)
#define WR_S2MM_FRAME_STRIDE _IOR('h',6,int)
#define START_MM2S_TX _IOR('h',7,int)
#define START_S2MM_RX _IOR('h',8,int)
#define READ_BUFFER  _IOR('h',9,int)
#define WRITE_BUFFER  _IOW('h',10,int)
#define AXIVDMA_TX_STATUS _IOR('h',11,int)
#define AXIVDMA_RX_STATUS _IOR('h',12,int)
#define STOP_AXIVDMA_TX _IOW('h',13,int)
#define STOP_AXIVDMA_RX _IOW('h',14,int)
#define RPARK_PTR_RD _IOR('h',15,int)
#define RPARK_PTR_WR _IOR('h',16,int)
#define RD_MM2S_VSIZE _IOR('h',17,int)
#define RD_MM2S_HSIZE _IOR('h',18,int)
#define RD_MM2S_FRAME_STRIDE _IOR('h',19,int)
#define WR_MM2S_VSIZE _IOW('h',20,int)
#define WR_MM2S_HSIZE _IOW('h',21,int)
#define WR_MM2S_FRAME_STRIDE _IOR('h',22,int)
#define WR_MM2S_WROKMODE _IOW('h',23,int)
#define WR_S2MM_WROKMODE _IOW('h',24,int)
#define RD_MM2S_WROKMODE _IOR('h',25,int)
#define RD_S2MM_WROKMODE _IOR('h',26,int)

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   int CAM0;
   int  cam0_fd;


   unsigned char *CameraBuf;

   void sccb_senddata(unsigned short addr,unsigned char value);
   void ov5640_init_mode_1(void);
   void DDR3toRGB888_0( void *src);
   void cam0_vdma_init();
   void cam0_vdma_stop();
   void Init_Qimage_parameter0(int height,int width);

   void processor_init();
   std::vector<Bbox> process(int& offset_);

private slots:
    void on_pushButton_clicked();
    void slot_timer_0();
    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QImage imageGRY8;
    QImage imageRGB888_0;
    MTCNN *mtcnn = nullptr;
};

#endif // MAINWINDOW_H
