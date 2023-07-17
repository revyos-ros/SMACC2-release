// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*****************************************************************************************************************
 *
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/

#include <nav2z_client/client_behaviors/cb_abort_navigation.hpp>
#include <nav2z_client/common.hpp>
#include <nav2z_client/components/goal_checker_switcher/cp_goal_checker_switcher.hpp>
#include <nav2z_client/components/odom_tracker/cp_odom_tracker.hpp>
#include <nav2z_client/components/pose/cp_pose.hpp>
#include <nav2z_client/nav2z_client.hpp>

#include <rclcpp/parameter_client.hpp>

namespace cl_nav2z
{
CbStopNavigation::CbStopNavigation() {}

void CbStopNavigation::onEntry()
{
  // this->sendGoal(goal);

  // this->cancelGoal();

  cl_nav2z::Pose * poseComponent;
  this->requiresComponent(poseComponent);

  this->setGoal(poseComponent->toPoseMsg());

  CbNavigateGlobalPosition::onEntry();

  // this->sendGoal(goal);
}

void CbStopNavigation::onExit() {}

}  // namespace cl_nav2z
