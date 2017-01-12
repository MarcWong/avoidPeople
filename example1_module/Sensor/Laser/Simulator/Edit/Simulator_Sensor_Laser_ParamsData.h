//You need to modify this file.

#ifndef SIMULATOR_SENSOR_LASER_PARAMSDATA_H
#define SIMULATOR_SENSOR_LASER_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Laser_ParamsData Simulator_Sensor_Laser_ParamsData
	\ingroup Simulator_Sensor_Laser
	\brief Simulator_Sensor_Laser_ParamsData defines the ParamsData in Simulator_Sensor_Laser.
*/

/*! \addtogroup Simulator_Sensor_Laser_ParamsData
	@{
*/

/*! \file Simulator_Sensor_Laser_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_Laser
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_Laser_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_Laser_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_Laser_Params 
	\brief The Params of Simulator_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Laser_Params 
{
public:
	/*! \fn Simulator_Sensor_Laser_Params()
		\brief The constructor of Simulator_Sensor_Laser_Params. [required]
		\details ****Please add details below****

	*/
    Simulator_Sensor_Laser_Params()
	{
        rng = 1;
        res = 0.1;
        unit = 0.1;
        nearThres=3;
        farThres=80;
        isReverse=1;
        aL=4.2;
        xL=0.28;
        yL=2.6;
	}
	/*! \fn ~Simulator_Sensor_Laser_Params()
		\brief The destructor of Simulator_Sensor_Laser_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Laser_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    float rng;
    float res;
    float unit;
    int nearThres;
    int farThres;
    bool isReverse;
    double aL,xL,yL;
};

//The Output Data is defined as below
/*! \class Simulator_Sensor_Laser_Data 
	\brief The Data of Simulator_Sensor_Laser.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Laser_Data 
{
public:
	/*! \fn Simulator_Sensor_Laser_Data()
		\brief The constructor of Simulator_Sensor_Laser_Data. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Laser_Data() 
	{

	}
	/*! \fn ~Simulator_Sensor_Laser_Data()
		\brief The destructor of Simulator_Sensor_Laser_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Laser_Data() 
	{

	}
public:
	//*******************Please add variables below*******************
    short *data;
};

/*! \def Simulator_Sensor_Laser_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_Laser_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
