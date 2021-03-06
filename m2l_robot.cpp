////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Copyright (c) 2019 Leonardo Consoni <consoni_2519@hotmail.com>            //
//                                                                            //
//  This file is part of Robot-Control-CT.                                    //
//                                                                            //
//  Robot-Control-CT is free software: you can redistribute it and/or modify  //
//  it under the terms of the GNU Lesser General Public License as published  //
//  by the Free Software Foundation, either version 3 of the License, or      //
//  (at your option) any later version.                                       //
//                                                                            //
//  Robot-Control-CT is distributed in the hope that it will be useful,       //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of            //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              //
//  GNU Lesser General Public License for more details.                       //
//                                                                            //
//  You should have received a copy of the GNU Lesser General Public License  //
//  along with Robot-Control-CT. If not, see <http://www.gnu.org/licenses/>.  //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "interface/robot_control.h"

#include <Eigen/Core>
#include <Eigen/StdVector>

#include "gen/m2l/cpp/declarations.h"
#include "gen/m2l/cpp/jsim.h"
#include "gen/m2l/cpp/jacobians.h"
#include "gen/m2l/cpp/traits.h"
#include "gen/m2l/cpp/forward_dynamics.h"
#include "gen/m2l/cpp/inertia_properties.h"
#include "gen/m2l/cpp/inverse_dynamics.h"
#include "gen/m2l/cpp/transforms.h"
#include "gen/m2l/cpp/link_data_map.h"

// define namespace and base
#define ROBCOGEN_NS M2L
#define TARGET_NS M2LRobot
// define the links
#define CT_BASE base0
#define CT_L0 link1
#define CT_L1 link2
// define single end effector (could also be multiple)
#define CT_N_EE 1
#define CT_EE0 ee
#define CT_EE0_IS_ON_LINK 1
#define CT_EE0_FIRST_JOINT 0
#define CT_EE0_LAST_JOINT 1

#include "ct/rbd/robot/robcogen/robcogenHelpers.h"

// obtain the state dimension
//const size_t STATE_DIM = FixBaseFDSystem<M2LRobot::Dynamics>::STATE_DIM;
// create an instance of the system
//std::shared_ptr<core::System<STATE_DIM>> dynamics(new FixBaseFDSystem<M2LRobot::Dynamics>);

#define DOFS_NUMBER 2
#define DELAY_SETPOINTS_NUMBER 1//5

const double MIN_WAVE_IMPEDANCE = 1.0;

const char* DOF_NAMES[ DOFS_NUMBER ] = { "angle1", "angle2" };

static struct
{
//   double setpointsTable[ DOFS_NUMBER ][ DELAY_SETPOINTS_NUMBER ];
//   double lastInputWavesList[ DOFS_NUMBER ];
//   double lastFilteredWavesList[ DOFS_NUMBER ];
//   size_t setpointCount;
//   enum RobotState state;
//   double elapsedTime;
//   Log samplingLog;
}
controlData;


DECLARE_MODULE_INTERFACE( ROBOT_CONTROL_INTERFACE );


bool InitController( const char* configurationString )
{
//   memset( &controlData, 0, sizeof(controlData) );
//   
//   Log_SetDirectory( "" );
//   controlData.samplingLog = Log_Init( "motor_sampling", 8 );
//   
//   controlData.elapsedTime = 0.0;
//   
//   controlData.state = ROBOT_PASSIVE;
  
  return true;
}

void EndController()
{
//   Log_End( controlData.samplingLog );
}

size_t GetJointsNumber()
{
//   return DOFS_NUMBER;
}

const char** GetJointNamesList()
{
//   return (const char**) DOF_NAMES;
}

size_t GetAxesNumber()
{
//   return DOFS_NUMBER;
}

const char** GetAxisNamesList()
{
//   return (const char**) DOF_NAMES;
}

void SetControlState( enum RobotState newControlState )
{
//   fprintf( stderr, "Setting robot control phase: %x\n", newControlState );
//   
//   if( newControlState == ROBOT_PREPROCESSING ) controlData.elapsedTime = 0.0;
//   
//   controlData.state = newControlState;
}

void ControlJoint( RobotVariables* ref_jointMeasures, RobotVariables* ref_axisMeasures, RobotVariables* ref_jointSetpoints, RobotVariables* ref_axisSetpoints )
{
//   ref_axisMeasures->acceleration = ref_jointMeasures->acceleration;
//   ref_axisMeasures->velocity = ref_jointMeasures->velocity;
//   ref_axisMeasures->position = ref_jointMeasures->position;
//   ref_axisMeasures->force = ref_jointMeasures->force;
//   ref_axisMeasures->stiffness = ref_jointMeasures->stiffness;
//   ref_axisMeasures->damping = ref_jointMeasures->damping;
//   
//   ref_jointSetpoints->velocity = ref_axisSetpoints->velocity;                           // xdot_d
//   ref_jointSetpoints->position = ref_axisSetpoints->position;                           // x_d
//   ref_jointSetpoints->acceleration = ref_axisSetpoints->acceleration;
//   ref_jointSetpoints->force = ref_axisSetpoints->force;
//   ref_jointSetpoints->stiffness = ref_axisSetpoints->stiffness;                         // K = lamda^2 * m
//   ref_jointSetpoints->damping = ref_axisSetpoints->damping;                             // B = D = lamda * m
//   
//   double positionError = ref_jointSetpoints->position - ref_jointMeasures->position;    // e_p = x_d - x
//   double velocityError = ref_jointSetpoints->velocity - ref_jointMeasures->velocity;    // e_v = xdot_d - xdot
//   
//   // F_actuator = K * e_p + B * e_v - D * x_dot
//   double controlForce = ref_jointSetpoints->stiffness * positionError - ref_jointSetpoints->damping * velocityError;
//   double dampingForce = ref_jointSetpoints->damping * ref_jointMeasures->velocity;
//   ref_jointSetpoints->force += controlForce - dampingForce;
  //ref_jointSetpoints->force = 1.0 * positionError + 0.2 * velocityError; 
  
  //fprintf( stderr, "position=%.5f, setpoint=%.5f, control force=%.5f\n", ref_jointMeasures->position, ref_jointSetpoints->position, ref_jointSetpoints->force );
}

void RunControlStep( RobotVariables** jointMeasuresList, RobotVariables** axisMeasuresList, RobotVariables** jointSetpointsList, RobotVariables** axisSetpointsList, double timeDelta )
{
//   axisSetpointsList[ 0 ]->position = 0.0;//jointMeasuresList[ 1 ]->position;
//   axisSetpointsList[ 1 ]->position = 0.0;//jointMeasuresList[ 0 ]->position;
//   axisSetpointsList[ 0 ]->velocity = 0.0;//jointMeasuresList[ 1 ]->velocity;
//   axisSetpointsList[ 1 ]->velocity = 0.0;//jointMeasuresList[ 0 ]->velocity;
//   
//   ControlJoint( jointMeasuresList[ 0 ], axisMeasuresList[ 0 ], jointSetpointsList[ 0 ], axisSetpointsList[ 0 ] );
//   ControlJoint( jointMeasuresList[ 1 ], axisMeasuresList[ 1 ], jointSetpointsList[ 1 ], axisSetpointsList[ 1 ] );
//   
//   fprintf( stderr, "position 1=%.5f, position 2=%.5f\n", axisMeasuresList[ 0 ]->position, axisMeasuresList[ 1 ]->position );
//   
//   controlData.elapsedTime += timeDelta;
  
  //if( controlData.state != ROBOT_OPERATION && controlData.state != ROBOT_PREPROCESSING ) jointSetpointsList[ 0 ]->force = jointSetpointsList[ 1 ]->force = 0.0;
}
