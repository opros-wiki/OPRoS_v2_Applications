#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>

#include <iostream>
#include <stdio.h>

#include "joint_effort_cmd.pb.h"
#include "joint_status.pb.h"

#define NUM_JOINTS 4

//gazebo --verbose ~/Untitled\ Folder/test_gazebo/simple_arm.world

namespace gazebo
{ 
	typedef const boost::shared_ptr<const my_msgs::msgs::JointEffortCmdRequest> JointEffortCmdRequestPtr;
	class JointControlTestPlugin : public ModelPlugin
	{
	public:
		JointControlTestPlugin()
		{
			for(int i = 0; i < NUM_JOINTS; i++)
			{
				_jointPositions[i] = 0;
				_jointVelocities[i] = 0;
				_jointEfforts[i] = 0;
			}
		}		

		void Load(physics::ModelPtr model, sdf::ElementPtr sdf)
		{
			printf("TEST");

			_model = model;

			_node = transport::NodePtr(new transport::Node());
			_node->Init(_model->GetWorld()->GetName());			

			_joints[0] = _model->GetJoint("arm_shoulder_pan_joint");
			_joints[1] = _model->GetJoint("arm_elbow_pan_joint");
			_joints[2] = _model->GetJoint("arm_wrist_lift_joint");
			_joints[3] = _model->GetJoint("arm_wrist_roll_joint");

			_effortSub = _node->Subscribe(std::string("~/") + _model->GetName() + "/cmd", &JointControlTestPlugin::OnJointEffortCmd, this);
			_jointPub = _node->Advertise<my_msgs::msgs::JointStatusResponse>(std::string("~/") + _model->GetName() + "/joint_status");

			this->_updateConnection = event::Events::ConnectWorldUpdateBegin(
          		boost::bind(&JointControlTestPlugin::OnUpdate, this, _1));				
		}

		void Init()
		{			
		}

	private:
		
		void OnJointEffortCmd(JointEffortCmdRequestPtr &msg)
		{
			for(int i = 0; i < msg->name().size(); i++)
			{
				if(msg->name(i) == "arm_shoulder_pan_joint")
					_jointEffortCmd[0] = msg->effort(i);
				else if(msg->name(i) == "arm_elbow_pan_joint")
					_jointEffortCmd[1] = msg->effort(i);
				else if(msg->name(i) == "arm_wrist_lift_joint")
					_jointEffortCmd[2] = msg->effort(i);
				else if(msg->name(i) == "arm_wrist_roll_joint")
					_jointEffortCmd[3] = msg->effort(i);
			}			
		}
				

		void OnUpdate(const common::UpdateInfo & /*_info*/)
		{
			common::Time currTime = _model->GetWorld()->GetSimTime();
  			common::Time stepTime = currTime - _prevUpdateTime;

  			
  			// Apply Joint Effort Command
  			for(int i = 0; i < NUM_JOINTS; i++)
  			{
  				_joints[i]->SetForce(0, _jointEffortCmd[i]);
  			}

  			
  			// Response
  			my_msgs::msgs::JointStatusResponse response; 

 			for(int i = 0; i < NUM_JOINTS; i++)
  			{
  				my_msgs::msgs::JointStatusResponse_JointStatus* status = response.add_joint();
  				
  				status->set_name(_joints[i]->GetName());
  				status->set_position(_joints[i]->GetAngle(0).Degree());
  				status->set_velocity(_joints[i]->GetVelocity(0));
  				status->set_effort(_joints[i]->GetForce(0));  				
  			}

  			/*	

  				response.position().push_back()
  				_jointPositions[i] = _joints[i]->GetAngle(0).Radian();

  				response.velocity().push_back(_joints[i]->GetVelocity(0))
  				_jointVelocities[i] = _joints[i]->GetVelocity(0);

  				response.effort().push_back(_joints[i]->GetForce(0))
  				_jointEfforts[i] = _joints[i]->GetForce(0);
  				*/   			

   			//_jointPub->WaitForConnection();
   			_jointPub->Publish(response);   			
		}


	private:
		physics::ModelPtr _model;

		physics::JointPtr _joints[NUM_JOINTS];
		double _jointPositions[NUM_JOINTS];
		double _jointVelocities[NUM_JOINTS];
		double _jointEfforts[NUM_JOINTS];

		transport::SubscriberPtr _effortSub;
		transport::PublisherPtr _jointPub;
		double _jointEffortCmd[NUM_JOINTS];

		transport::NodePtr _node;		
		event::ConnectionPtr _updateConnection;

		common::Time _prevUpdateTime;
	};

  // Register this plugin with the simulator
GZ_REGISTER_MODEL_PLUGIN(JointControlTestPlugin)
}
