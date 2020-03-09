#ifndef SRC_EXAMPLE_COMPONENT_H_
#define SRC_EXAMPLE_COMPONENT_H_

#include <memory>
#include <string>

#include "component/timer_component.h"
#include "cyber.h"
#include "proto/examples.pb.h"
#include "time/rate.h"
#include "time/time.h"
// #include "proto/sensor_ultrasonic.pb.h"
#include "proto/perception_obstacle.pb.h"
#include "proto/common_geometry.pb.h"
#include "proto/localization_pose.pb.h"

#include "parameter/parameter_client.h"
#include "parameter/parameter_server.h"


// /localization/lidar/localization_pose                  110 messages: adu.common.localization.LocalizationEstimate


namespace autobot {
namespace example {

using apollo::cyber::Component;
using apollo::cyber::ComponentBase;
using apollo::cyber::Rate;
using apollo::cyber::Time;
using apollo::cyber::TimerComponent;
using apollo::cyber::Writer;
using apollo::cyber::Reader;
using apollo::cyber::examples::proto::Chatter;
using apollo::cyber::examples::proto::Driver;
using adu::common::perception::PerceptionObstacles;
using adu::common::perception::PerceptionObstacle;
using adu::common::TransformStampeds;
using adu::common::localization::LocalizationEstimate;

using apollo::cyber::Parameter;
using apollo::cyber::ParameterClient;
using apollo::cyber::ParameterServer;

class ExampleTTTComponent : public TimerComponent {
 public:
  bool Init() override;


  bool Proc() override;
  void Callback(const std::shared_ptr<PerceptionObstacles>& message);
  void ChatterCallback(const std::shared_ptr<Driver>& message);
  void TFCallback(const std::shared_ptr<TransformStampeds>& message);
  void LocationCallback(const std::shared_ptr<LocalizationEstimate>& message);
  void ParameterCallback(const std::shared_ptr<Parameter>& message); 

 private:
  std::shared_ptr<Reader<Driver>> chatter_reader_ = nullptr;
  std::shared_ptr<Reader<PerceptionObstacles>> reader_ = nullptr;
  std::shared_ptr<Reader<TransformStampeds>> tf_reader_ = nullptr;
  std::shared_ptr<Reader<LocalizationEstimate>> location_reader_ = nullptr;

 std::shared_ptr<ParameterServer> param_server_cb_ = nullptr;
  std::shared_ptr<ParameterServer> param_server_ = nullptr;
  std::shared_ptr<ParameterClient> param_client_ = nullptr;
  Parameter parameter;

  uint64_t seq_ = 0;
  Driver message_;
  // PerceptionObstacles message_;
  double time_;
  int recv_tip;
  int num_;
  int message_status;
  float message_ranges;
};

CYBER_REGISTER_COMPONENT(ExampleTTTComponent);

}  // namespace example
}  // namespace autobot
#endif  // SRC_EXAMPLE_COMPONENT_H_
