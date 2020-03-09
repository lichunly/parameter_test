#include "example_component.h"

namespace autobot {
namespace example {


void ExampleTTTComponent::ParameterCallback(const std::shared_ptr<Parameter>& message) {
  AINFO << "Set cb: " << message->DebugString();
}

void ExampleTTTComponent::LocationCallback(const std::shared_ptr<LocalizationEstimate>& message) {
  time_ = message->measurement_time();
}

void ExampleTTTComponent::TFCallback(const std::shared_ptr<TransformStampeds>& message) {
  recv_tip = 1;
  num_++;
}

void ExampleTTTComponent::Callback(const std::shared_ptr<PerceptionObstacles>& message) {
}

void ExampleTTTComponent::ChatterCallback(const std::shared_ptr<Driver>& message) {
  AERROR<< "READ MSG: " << message->msg_id();
  // message_ = *message;
  // message_status = message_.status();
  // message_ranges =  message_.ranges();
  recv_tip = 1;
  // num_++;
}

bool ExampleTTTComponent::Init() {
  AERROR<< "Init MSG  1";  
    chatter_reader_ = node_->CreateReader<Driver>( "/apollo/test", [this](const std::shared_ptr<Driver>& message){
          AINFO << "Received chatter data: run chatter callback.";
         ChatterCallback(message);        
          }); 
    AERROR<< "Init MSG  2";        
    reader_ = node_->CreateReader<PerceptionObstacles>( "/perception/obstacles", [this](const std::shared_ptr<PerceptionObstacles>& message){
          AWARN << "Received obstacles data: run obstacles callback.";
         Callback(message);        
          }); 
    AERROR<< "Init MSG  3";  
    tf_reader_ = node_->CreateReader<TransformStampeds>( "/tf", [this](const std::shared_ptr<TransformStampeds>& message){
          AWARN << "Received TransformStampeds data: run TransformStampeds callback.";
         TFCallback(message);        
          });  
    AERROR<< "Init MSG  4";  
    location_reader_ = node_->CreateReader<LocalizationEstimate>( "/localization/lidar/localization_pose", [this](const std::shared_ptr<LocalizationEstimate>& message){
          AWARN << "Received LocalizationEstimate data: run LocalizationEstimate callback.";
         LocationCallback(message);        
          });
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";                     
    AERROR<< "Init ParameterServer/Client";
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";   
    // sleep(5);  
    param_server_ = std::make_shared<ParameterServer>(node_);

    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";       
    // sleep(5);  
    param_client_ = std::make_shared<ParameterClient>(node_, "parameter_test");
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";       
    // sleep(5);  
    param_server_->SetParameter(Parameter("int", 1));
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";
    AINFO<<" ";       
    sleep(5);  
    // param_server_->RegisterSetCallback([this](const std::shared_ptr<Parameter>& message){
    //       AWARN << "Received Parameter data: run Parameter callback.";
    //      ParameterCallback(message);        
    //       });
    param_server_->RegisterSetCallback("int",[this](const std::shared_ptr<Parameter>& message){
          AWARN << "Received Parameter data: run Parameter callback.";
         ParameterCallback(message);        
          });
    // param_server_->GetParameter("int", &parameter);
    // AINFO << "after server set int: " << parameter.AsInt64();
  
        time_ = 0;
        recv_tip = 0;
        num_ = 0;
    AERROR<< "Init End";  
  return true;
}

bool ExampleTTTComponent::Proc() {
  // if(recv_tip == 1){
  //   recv_tip = 0;
  //   // AINFO<< "READ MSG: "<< num_  << "  " << message_.seq();
  // }
  Parameter parameter_;

  ++num_;
  // AINFO<< "Loop :  " << num_;
  // AWARN << "before client set int: " << parameter.AsInt64();
  if(num_%2)
  {
    param_client_->SetParameter(Parameter("int", num_)); 
  }
  else
  {
    param_client_->SetParameter(Parameter("string", "Hello apollo parameter")); 
  }

  if(num_ == 20)
  {
    param_server_->DestroySetCallback();
  }

  if(num_ == 30)
  {
    param_server_->RegisterSetCallback([this](const std::shared_ptr<Parameter>& message){
          AWARN << "Received Parameter data: run Parameter callback.";
         ParameterCallback(message);        
          });
  }

  // AWARN << "after client set int: " << parameter.AsInt64();
  // param_client_->GetParameter("int", &parameter_);
  // AWARN << "after client get int: " << parameter_.AsInt64();
  // param_server_->GetParameter("int", &parameter);
  // AWARN << "after server get int: " << parameter.AsInt64();
  return true;
}

}  // namespace example
}  // namespace autobot
