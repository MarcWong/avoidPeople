//You need to program this file.

#include "../NoEdit/ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Sensor_Encoder_Params, Data_Type = Simulator_Sensor_Encoder_Data
//Input Port #1: Buffer_Size = 10, Params_Type = Simulator_Sensor_IMU_Params, Data_Type = Simulator_Sensor_IMU_Data
//Input Port #2: Buffer_Size = 10, Params_Type = Simulator_Sensor_Laser_Params, Data_Type = Simulator_Sensor_Laser_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Vars *)varsPtr;
	QVector<Simulator_Sensor_Encoder_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<Simulator_Sensor_IMU_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<Simulator_Sensor_Laser_Params *> inputparams_2; copyQVector(inputparams_2,inputParams[2]);
	QVector<Simulator_Sensor_Encoder_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<Simulator_Sensor_IMU_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	QVector<Simulator_Sensor_Laser_Data *> inputdata_2; copyQVector(inputdata_2,inputData[2]);
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Data * outputdata=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNewNew_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	if(inputdata_2.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/

    //0:encoder
    //1:IMU
    //2:Laser


    //0.encoder
    //inputdata_0.front()->pulse （int）为编码器最近帧脉冲数据，增加即小车向前走
    //inputparams_0.front()->disPerPulse   (double)编码器单脉冲对应的距离 单位为m
    //inputparams_0.front()->pulseMax	(int)编码器脉冲数最大数据


    //1.IMU
    //inputdata_1.front()->yaw    （double）为IMU最近帧航向角数据，单位为度，顺时针为正方向
    double yaw = inputdata_1.front()->yaw;

    //laser
    short* data =inputdata_2.front()->data;
    /*usage: for (int i = 0; i < 181; i++)
        {
         double distance = data[i] / inputparams_2.front()->unit
         double angle = i*inputparams_2.front()->res * 3.1415926 / 180.0;
         double lx = dis*cos(angle);
         double ly = dis*sin(angle);
            if(inputparams_2.front()->isReverse)
                lx *= -1;
        double laser_aL_rad=inputparams_2.front()->aL* PI / 180.0;//转换为弧度
        double rx = inputparams_2.front()->xL / inputparams_2.front()->unit + dis*cos(laser_aL_rad + angle) ;
        double ry = inputparams_2.front()->yL / inputparams_2.front()->unit + dis*sin(laser_aL_rad + angle) ;
        }
    */
    for(int i = 0 ; i < inputparams_2.front()->rng/inputparams_2.front()->res; i++)
    {
    //==============================================================================
    //-----------------Please edit below--------------------------------------------
    //==============================================================================

        //目标：对每条激光束更新全局地图（Occupency Gird Map）
        //下列步骤中需要编程的有3，4，5，8

        //1.分别定义激光点在全局坐标系（GPS），机器人坐标系，激光雷达坐标系中的坐标变量
            double gx, gy;//激光点在全局坐标系中的位置 单位m
            double rx, ry;//激光点在机器人坐标系中的位置 单位m
            double lx, ly;//激光点在激光雷达坐标系中的位置 单位m
            const double PI = 3.1415926;
        //2.若激光点返回测距值为0，则为无效数据，将其滤除。
            if(inputparams_2.front()->data[i] == 0)
                continue;

        //3.计算激光点在激光雷达坐标系下的位置，并根据参数inputparams_0.front()->isReverse判断是否将lx取相反数。
            double dis = inputparams_2.front()->data[i] / inputparams_2.front()->unit;//计算得到单个激光点的距离返回值
            double angle = i * inputparams_2.front()->res * PI / 180.0;//计算得到当前处理激光束在激光雷达坐标系中角度
            lx = dis*cos(angle);
            ly = dis*sin(angle);
            if(inputparams_2.front()->isReverse)
                lx *= -1;

        //4.进行 激光雷达坐标系->机器人坐标系 变换
            //xL,yL,aL定义见课件，其在程序中对应变量为
            //inputparams_0.front()->xL，inputparams_0.front()->yL，inputparams_0.front()->aL
            double laser_aL_rad=inputparams_2.front()->aL* PI / 180.0;//转换为弧度
            rx = inputparams_2.front()->xL / inputparams_2.front()->unit + dis*cos(laser_aL_rad + angle) ;
            ry = inputparams_2.front()->yL / inputparams_2.front()->unit + dis*sin(laser_aL_rad + angle) ;
    }
	return 1;
}

