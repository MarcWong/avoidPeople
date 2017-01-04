//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_VISUALIZATION_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_VISUALIZATION_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Visualization_Vars VisualizationMono_Algorithm_Visualization_Vars
	\ingroup VisualizationMono_Algorithm_Visualization
	\brief VisualizationMono_Algorithm_Visualization_Vars defines the Vars in VisualizationMono_Algorithm_Visualization.
*/

/*! \addtogroup VisualizationMono_Algorithm_Visualization_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Visualization_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Visualization
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Algorithm_Visualization_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Visualization_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Visualization.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Visualization_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Visualization_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Visualization_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Visualization_Vars() 
	{
		
	}
	/*! \fn ~VisualizationMono_Algorithm_Visualization_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Visualization_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Visualization_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QLabel *mapview;
};

/*! @}*/ 

#endif
