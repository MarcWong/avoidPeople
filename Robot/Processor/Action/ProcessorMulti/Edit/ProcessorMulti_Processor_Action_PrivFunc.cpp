//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_Action_PrivFunc.h"
#include<iostream>
using namespace std;

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_Action_Params * params=(ProcessorMulti_Processor_Action_Params *)paramsPtr;
	ProcessorMulti_Processor_Action_Vars * vars=(ProcessorMulti_Processor_Action_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_Action_Params * params=(ProcessorMulti_Processor_Action_Params *)paramsPtr;
	ProcessorMulti_Processor_Action_Vars * vars=(ProcessorMulti_Processor_Action_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMulti_Processor_Action_Params * params=(ProcessorMulti_Processor_Action_Params *)paramsPtr;
	ProcessorMulti_Processor_Action_Vars * vars=(ProcessorMulti_Processor_Action_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	ProcessorMulti_Processor_Action_Params * params=(ProcessorMulti_Processor_Action_Params *)paramsPtr;
	ProcessorMulti_Processor_Action_Vars * vars=(ProcessorMulti_Processor_Action_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_Action_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_Action_Params * params=(ProcessorMulti_Processor_Action_Params *)paramsPtr;
	ProcessorMulti_Processor_Action_Vars * vars=(ProcessorMulti_Processor_Action_Vars *)varsPtr;
	inputDataSize=QList<int>();
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	E.g.
	inputDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_xtion_Params, Data_Type = SensorTimer_Sensor_xtion_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_Action_Params * params=(ProcessorMulti_Processor_Action_Params *)paramsPtr;
	ProcessorMulti_Processor_Action_Vars * vars=(ProcessorMulti_Processor_Action_Vars *)varsPtr;
	QVector<SourceDrainMono_Sensor_EncoderIMU_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorTimer_Sensor_xtion_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<SourceDrainMono_Sensor_EncoderIMU_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorTimer_Sensor_xtion_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Processor_Action_Data * outputdata=(ProcessorMulti_Processor_Action_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
#define DESTINATION_X 100
#define DESTINATION_Y 100
#define RADIUS 5

    double x = inputdata_0.front()->x;
    double y = inputdata_0.front()->y;
    double theta = inputdata_0.front()->orientation;
    bool get_box = false; //mark whether the robot has got the box

    cv::Mat color = inputdata_1.front()->cvColorImg;
    cv::Mat depth = inputdata_1.front()->cvDepthImg;
    //qDebug() << "rows: " << color.rows << endl << "cols: " << color.cols << endl;
    for(int i = 0; i < color.rows; ++i)
    {
        uchar* pixel = color.ptr<uchar>(i);
        int tmp = 0;
        for(int j = 0; j <= color.cols*3; j += 3)
        {
            //qDebug() << pixel[j];
            //++tmp;
            //qDebug() << tmp;
            if(!((pixel[j+1] > pixel[j])&&(pixel[j+1] > pixel[j+2])) || ((pixel[j] > 100)&&(pixel[j+2] > 100)))
            {
                pixel[j] = 0;
                pixel[j+1] = 0;
                pixel[j+2] = 0;
            }
        }
        //break;
    }
    int ctr_x = -1;
    int ctr_y = -1;
    int x_sum = 0;
    int y_sum = 0;
    int ptr_num = 0;
    for(int i = 0; i < color.rows; ++i)
    {
        uchar* pixel = color.ptr<uchar>(i);
        for(int j = 0; j < color.cols*3; j += 3)
        {
            if(!((pixel[j] == 0)&&(pixel[j+1] == 0)&&(pixel[j+2] == 0)))
            {
                x_sum += j/3;
                y_sum += i;
                ++ptr_num;
            }
        }
    }
    ctr_x = x_sum / ptr_num;
    ctr_y = y_sum / ptr_num;
    uchar* pixel = color.ptr<uchar>(ctr_y);
    pixel[ctr_x * 3 + 2] = 255;
    pixel[ctr_x * 3 + 1] = 0;
    pixel[ctr_x * 3] = 0;
    short steer;
    short speed;

    //get the center and nearby four points' distance
    uchar* pixel_d = depth.ptr<uchar>(ctr_y);
    double distance = pixel_d[ctr_x];
    int point_num = 1;
    if(ctr_x+1 < color.cols)
    {
        if(!((pixel_d[(ctr_x+1)*3 + 1] > pixel[(ctr_x+1)*3])&&(pixel[(ctr_x+1)*3 + 1] > pixel[(ctr_x+1)*3 + 2])) || ((pixel[(ctr_x+1)*3] > 100)&&(pixel[(ctr_x+1)*3 + 2] > 100)))
        {
            distance += pixel_d[ctr_x+1];
            ++point_num;
        }
    }
    if(ctr_x-1 >= 0)
    {
        if(!((pixel_d[(ctr_x-1)*3 + 1] > pixel[(ctr_x-1)*3])&&(pixel[(ctr_x-1)*3 + 1] > pixel[(ctr_x-1)*3 + 2])) || ((pixel[(ctr_x-1)*3] > 100)&&(pixel[(ctr_x-1)*3 + 2] > 100)))
        {
            distance += pixel_d[ctr_x-1];
            ++point_num;
        }
    }
    if(ctr_y-1 >= 0)
    {
        pixel_d = depth.ptr<uchar>(ctr_y-1);
        if(!((pixel_d[ctr_x*3 + 1] > pixel[ctr_x*3])&&(pixel[ctr_x*3 + 1] > pixel[ctr_x*3 + 2])) || ((pixel[ctr_x*3] > 100)&&(pixel[ctr_x*3 + 2] > 100)))
            {
                distance += pixel_d[ctr_x];
                ++point_num;
            }
    }
    if(ctr_y+1 < depth.rows)
    {
        pixel_d = depth.ptr<uchar>(ctr_y+1);
        if(!((pixel_d[ctr_x*3 + 1] > pixel[ctr_x*3])&&(pixel[ctr_x*3 + 1] > pixel[ctr_x*3 + 2])) || ((pixel[ctr_x*3] > 100)&&(pixel[ctr_x*3 + 2] > 100)))
            {
                distance += pixel_d[ctr_x];
                ++point_num;
            }
    }
    distance = distance / point_num;
    std::cout << distance;

    //in different occasions, calculate the speed and steer
    if((get_box == true) && ((x - DESTINATION_X)*(x - DESTINATION_X) + (y - DESTINATION_Y)*(y - DESTINATION_Y) <= RADIUS * RADIUS))
    {
        //the robot has arrived the destination
        speed = 0;
        steer = 0;
    }
    else if(ctr_x < color.rows / 2)
    {
        speed = 5;
        steer = 10;

    }
    else if(ctr_x > color.rows / 2)
    {
        speed = 5;
        steer = -10;
    }
    else if(ctr_x = color.rows / 2)
    {
        speed = 5;
        steer = 0;
    }

    //naive test
    //speed = 5;
    //steer = 0;

    char dataput[10];
    dataput[0] = 0xF8;
    dataput[1] = 4;
    *(short*)&dataput[2] = steer;
    *(short*)&dataput[4] = speed;
    dataput[6] = 0x8F;
    outputdata->datagram.append(dataput, 7);
    std::cout<<"steer:"<<steer<<"\t"<<"speed:"<<speed<<std::endl;
	return 1;
}
