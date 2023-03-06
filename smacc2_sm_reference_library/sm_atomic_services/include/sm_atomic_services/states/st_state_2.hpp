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

#include <smacc2/smacc.hpp>
#include <smacc2/client_behaviors/cb_call_service.hpp>

namespace sm_atomic_services
{
    using smacc2::client_behaviors::CbServiceCall;
// STATE DECLARATION
struct State2 : smacc2::SmaccState<State2, SmAtomicServices>
{
    using SmaccState::SmaccState;

// TRANSITION TABLE
    typedef mpl::list<

    Transition<EvServiceRequestReceieved<CbServiceServer, OrServices>, State1, SUCCESS>

    >reactions;


// STATE FUNCTIONS
    static void staticConfigure()
    {
        // the state reacts on a service request
        configure_orthogonal<OrServices, CbServiceServer>();

        // to evaluate the previous client behavior we test here the call to that service
        configure_orthogonal<OrServices, CbServiceCall<std_srvs::srv::Empty>>("/service");

    }

    void runtimeConfigure()
    {
        RCLCPP_INFO(getLogger(),"Entering State2");
    }

    void onEntry()
    {
        RCLCPP_INFO(getLogger(),"On Entry!");
    }

    void onExit()
    {
        RCLCPP_INFO(getLogger(),"On Exit!");
    }

};
}
