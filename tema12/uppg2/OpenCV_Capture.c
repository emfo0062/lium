/*
 * OpenCV_Capture.c
 *
 *  
 *      Author: sr
 */

#include <stdio.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <glib.h>

#include "highgui.h"
#include "cv.h"


int iShow_WebCam_GTK(void)
{
   int iNx = 800;
   int iNy = 600;


   GdkVisual* pGDKvisual3 = gdk_visual_get_system();


   CvCapture* pCV_cap= cvCaptureFromCAM(-1);
   cvNamedWindow("Webcamera",1);
   IplImage* pColor_img = cvQueryFrame(pCV_cap);
   unsigned char *pucData =0;
   int iStep=0;
   int iChannels=3;
   if(pColor_img != 0){
	   cvShowImage("Webcamera", pColor_img);
	   iNy=pColor_img->height;
	   iNx=pColor_img->width;
	   //iChannels=pColor_img->channels;
	   iStep = iNx;
	   pucData =(unsigned char *) pColor_img->imageData;
	}
	GdkImage* pGDKimage3 = gdk_image_new( GDK_IMAGE_NORMAL, pGDKvisual3, iNx, iNy);
	if (pGDKimage3 == NULL ) {
		fprintf( stderr, "Not able to create gdkimage object\n");
		return -1;
	}


	for (int i=0;i<iNx;i++){
		for(int j=0;j<iNy;j++){
			GdkColor sColor;
			if(pucData){
				sColor.blue = pucData[(j*iStep+i)*iChannels];
				sColor.red = pucData[(j*iStep+i)*iChannels+2];
				sColor.green = pucData[(j*iStep+i)*iChannels+1];
			}
			else {
				int l=i*j;
				sColor.blue = l&0xff;
				sColor.red = (l>>8);
				sColor.green = (l>>16);
			}
			unsigned int ui = sColor.red;
			ui <<=8;
			ui += sColor.green;
			ui <<=8;
			ui += sColor.blue;
			gdk_image_put_pixel( pGDKimage3, i, j,(unsigned int) ui);
		}
	}
//	if(pColor_img)
//		cvReleaseImage(&pColor_img);
	if(pCV_cap)
		cvReleaseCapture( &pCV_cap );

	GtkWidget *pWindow3 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget* pImage3  = gtk_image_new_from_image( pGDKimage3, NULL );

   gtk_container_add(GTK_CONTAINER (pWindow3), pImage3);
   gtk_widget_show_all(pWindow3);
   return 0;
}


/*
GdkPixbuf* convertOpenCvToGtk(IplImage *image)
{
        IplImage *gtkMask;
        //GtkWidget *gtkImg;
        GdkPixbuf *pix;

        gtkMask = cvCreateImage(cvSize(image->width, image->height), image->depth, image->nChannels);//Create another image with the same stuff
        cvCvtColor(image, gtkMask, CV_BGR2RGB);//Copy the IplImage to RGB format
        //Copy the IplImage data to a GdkPixbuf:
        pix = gdk_pixbuf_new_from_data (
                (guchar*)gtkMask->imageData,//Raw image data
                GDK_COLORSPACE_RGB,                     //Colorspace
                0,                                          //Has alpha channel or not
                gtkMask->depth,                         //Bits per pixel
                gtkMask->width,                         //Width of image
                gtkMask->height,                        //Height of image
                gtkMask->widthStep,                     //Row stride
                0,                                           //Not sure what this is
                0                                            //Not sure what this is
        );
        //gtkImg = gtk_image_new_from_pixbuf (pix);
        return pix;//Uncomment the gtkImg lines, change the return type to GtkWidget* and return gtkImg to make this return a GtkImage instead of a GdkPixbuf
}
*/


int iOpenCV_Capture(void)
{
	IplImage* pColor_img=0;
	CvCapture* pCV_cap= cvCaptureFromCAM(-1); // -1 = only one cam or doesn't matter
	if(pCV_cap==0)
		return -1;

	cvNamedWindow("Webcamera",1); // create window
	for(int i=0;i<200;i++) {
		if(pColor_img)
			cvReleaseImage(&pColor_img);
		pColor_img = cvQueryFrame(pCV_cap); // get frame
		if(pColor_img != 0){
			printf("Frame %d    \n",i);
			cvShowImage("Webcamera", pColor_img); // show frame
		}
		else
			break;

		int c = cvWaitKey(10);
		if(c == 32){
			break;
		}
	}
	/* clean up */
	cvReleaseCapture( &pCV_cap );
	cvDestroyWindow("Webcamera");
	return 0;
}

int main(int argc,char *argv[])
{

	gtk_init(&argc, &argv);

	int iRet=iShow_WebCam_GTK();

 	gtk_main ();


   //	iOpenCV_Capture();
   	return 0;
}
