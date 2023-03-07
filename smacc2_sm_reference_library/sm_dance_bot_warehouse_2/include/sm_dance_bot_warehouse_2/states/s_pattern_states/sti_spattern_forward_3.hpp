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

namespace sm_dance_bot_warehouse_2
{
namespace s_pattern_states
{

// STATE DECLARATION
struct StiSPatternForward3 : public smacc2::SmaccState<StiSPatternForward3, SS>
{
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef mpl::list<

    Transition<EvCbSuccess<CbNavigateForward, OrNavigation>, StiSPatternRotate4>
    //Transition<EvCbFailure<CbNavigateForward, OrNavigation>, StiSPatternForward3>

    >reactions;

  // STATE FUNCTIONS
  static void staticConfigure()
  {
    configure_orthogonal<OrNavigation, CbNavigateForward>();
    configure_orthogonal<OrNavigation, CbPauseSlam>();
    configure_orthogonal<OrLED, CbLEDOn>();
  }

  void runtimeConfigure()
  {
    double extrasecurityMargin = 0.1;

    auto forwardBehavior =
      this->getClientBehavior<OrNavigation,CbNavigateForward>();

    cl_lidar::ClLidarSensor * lidarClient;
    this->requiresClient(lidarClient);
    auto lidarData = lidarClient->getComponent<CpForwardObstacleDetector>();

    float fwdist = lidarData->getForwardDistance(25);
    if (!std::isnan(fwdist))
      forwardBehavior->setForwardDistance(
        std::min(SS::pitch1_lenght_meters(), (float)(fwdist -extrasecurityMargin))); /*extra security margin for easy dynamic implementation of dynamic-smotion*/

    else
      forwardBehavior->setForwardDistance( SS::pitch1_lenght_meters());
  }
};
}  // namespace s_pattern_states
}  // namespace sm_dance_bot_warehouse_2
