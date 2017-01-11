//You need to program this file.

#include "../NoEdit/ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Sensor_IMU_Params, Data_Type = Simulator_Sensor_IMU_Data
//Input Port #1: Buffer_Size = 10, Params_Type = Simulator_Sensor_Laser_Params, Data_Type = Simulator_Sensor_Laser_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params * params=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars * vars=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Vars *)varsPtr;
    QVector<Simulator_Sensor_IMU_Params *> inputparams_0; copyQVector(inputparams_1,inputParams[1]);
    QVector<Simulator_Sensor_Laser_Params *> inputparams_1; copyQVector(inputparams_0,inputParams[0]);
    QVector<Simulator_Sensor_IMU_Data *> inputdata_0; copyQVector(inputdata_1,inputData[1]);
    QVector<Simulator_Sensor_Laser_Data *> inputdata_1; copyQVector(inputdata_0,inputData[0]);
	ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Data * outputdata=(ProcessorMulti_Algorithm_Deadreckoning_ProcessorNew_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}


	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    //输入数据
        //inputdata_0.front()->pulse （int）为编码器最近帧脉冲数据，增加即小车向前走
        //inputdata_1.front()->yaw    （double）为IMU最近帧航向角数据，单位为度，顺时针为正方向
        //inputdata_0.front()->timestamp；inputdata_1.front()->timestamp为两传感器传回最近帧的时间戳

        //输入数据对应的外部参数
        //inputparams_0.front()->disPerPulse   (double)编码器单脉冲对应的距离 单位为m
        //inputparams_0.front()->pulseMax	(int)编码器脉冲数最大数据

        //查看ProcessorMulti_Algorithm_Deadreckoning_ParamsData.h与ProcessorMulti_Algorithm_Deadreckoning_Vars.h中外部
        //参数与内部变量头文件，可使用已经定义好的变量或者自行重新定义所需变量，如

        if(vars->isInit==false){
            vars->lastpulsenum=inputdata_0.front()->pulse;
            vars->initOriValue = inputdata_1.front()->yaw;
            vars->lastori=vars->initOriValue;
            vars->isInit=true;
        }
        else{
            //填满output

            //角度为弧度，顺时针为正方向，设机器人初始位置在全局坐标系下的航向角为+90度
            //位置单位为m，设初始位置在全局坐标系下为（0，0，pi/2）

            outputdata->orientation=(inputdata_1.front()->yaw - vars->initOriValue)/180.0*vars->PI + vars->PI/2;

            outputdata->timestamp=inputdata_0.front()->timestamp;

            int pulse = inputdata_0.front()->pulse - vars->lastpulsenum;

            if (pulse > 29000)
                pulse = inputparams_0.front()->pulseMax - pulse;
            else if (pulse < -29000)
                pulse = inputparams_0.front()->pulseMax + pulse;
            else if (pulse < 0 && pulse > -1000){
                pulse = - pulse;
                outputdata->orientation = outputdata->orientation + vars->PI;
            }
            while(outputdata->orientation > vars->PI)
                outputdata->orientation = outputdata->orientation - 2 * vars->PI;
            while(outputdata->orientation <= - vars->PI)
                outputdata->orientation = outputdata->orientation + 2 * vars->PI;

            double theta = outputdata->orientation - vars->lastori;
            outputdata->x = vars->lastx + cos(outputdata->orientation - theta/2) * pulse * inputparams_0.front()->disPerPulse;
            outputdata->y = vars->lasty + sin(outputdata->orientation - theta/2) * pulse * inputparams_0.front()->disPerPulse;

            vars->lastx = outputdata->x;
            //printf("%d",vars->lastx);
            vars->lasty = outputdata->y;
            //printf("%d",vars->lasty);
            vars->lastori = outputdata->orientation;
            vars->lastpulsenum = inputdata_0.front()->pulse;
        }

        //1.分别定义激光点在全局坐标系（GPS），机器人坐标系，激光雷达坐标系中的坐标变量
            double gx, gy;//激光点在全局坐标系中的位置 单位m
            double rx, ry;//激光点在机器人坐标系中的位置 单位m
            double lx, ly;//激光点在激光雷达坐标系中的位置 单位m
            const double PI = 3.1415926;
        //2.若激光点返回测距值为0，则为无效数据，将其滤除。
            if(inputdata_0.front()->data[i] == 0)
                continue;

        //3.计算激光点在激光雷达坐标系下的位置，并根据参数inputparams_0.front()->isReverse判断是否将lx取相反数。
            double dis = inputdata_0.front()->data[i] / inputparams_0.front()->unit;//计算得到单个激光点的距离返回值
            double angle = i * inputparams_0.front()->res * PI / 180.0;//计算得到当前处理激光束在激光雷达坐标系中角度
            lx = dis*cos(angle);
            ly = dis*sin(angle);
            if(inputparams_0.front()->isReverse)
                lx *= -1;

        //4.进行 激光雷达坐标系->机器人坐标系 变换
            //xL,yL,aL定义见课件，其在程序中对应变量为
            //inputparams_0.front()->xL，inputparams_0.front()->yL，inputparams_0.front()->aL
            double laser_aL_rad=inputparams_0.front()->aL* PI / 180.0;//转换为弧度
            rx = inputparams_0.front()->xL / inputparams_0.front()->unit + dis*cos(laser_aL_rad + angle) ;
            ry = inputparams_0.front()->yL / inputparams_0.front()->unit + dis*sin(laser_aL_rad + angle) ;




        //5.进行 机器人坐标系->全局坐标系 变换
            //机器人航向角ori定义见课件，对应变量为inputdata_1.front()->ori
            double orien=inputdata_1.front()->ori;
            gx = inputdata_1.front()->x + dis * cos(angle+orien-PI/2);
            gy = inputdata_1.front()->y + dis * sin(angle+orien-PI/2);

        //6.计算激光点在地图中的位置 单位 pixel
            int mapx, mapy;
            mapx = (gx) / params->mapRes-params->ZeroX;
            mapy = (gy) / params->mapRes-params->ZeroY;

        //7.调用函数计算当前激光束途经的栅格点坐标序列（地图中的像素坐标），存储在std::vector<Location> locationVec中，各栅格点坐标按照激光发射方向排列。
            int location_mapx,location_mapy;
            location_mapx=inputdata_1.front()->x/params->mapRes-params->ZeroX;
            location_mapy=inputdata_1.front()->y/params->mapRes-params->ZeroY;
            std::vector<Location> locationVec;
            Location startPos(location_mapx,location_mapy);
            Location endPos(mapx,mapy);
            CalcShortestDistance(startPos, endPos, locationVec);

        //8.根据OGM地图生成方法制图。
            //地图存储在vars->map[][]中，坐标轴为vars->map[y][x]。
            //定义每个栅格vars->map[y][x]取值上下界。
            double upthres=300;
            double lowthres=-300;
            //逐个更新当前激光束途经的栅格点坐标，params->logodd_free，params->logodd_occu为检测到当前坐标为无障碍/有障碍的更新值。
            std::vector<Location>::iterator d;
            d = locationVec.begin();
            d++;
            for (std::vector<Location>::iterator c=locationVec.begin();c!=locationVec.end();c++){
                d++;
                if((*c).x >= 0 && (*c).x < params->mapWidth && (*c).y >= 0 && (*c).y < params->mapHeight){
                    if(d==locationVec.end())
                        vars->map[(*c).y][(*c).x] += params->logodd_occu;
                    else
                        vars->map[(*c).y][(*c).x] += params->logodd_free;
                    if(vars->map[(*c).y][(*c).x]>300)
                        vars->map[(*c).y][(*c).x] = 300;
                    if(vars->map[(*c).y][(*c).x]<-300)
                        vars->map[(*c).y][(*c).x] = -300;
                }
            }


	return 1;
}

