// Copyright 2011 Software Freedom Conservancy
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

// Defines a command for use in the JSON Wire Protocol. The protocol is
// defined at http://code.google.com/p/selenium/wiki/JsonWireProtocol.

#ifndef WEBDRIVER_SERVER_COMMAND_H_
#define WEBDRIVER_SERVER_COMMAND_H_

#include <map>
#include <string>
#include "json.h"

namespace webdriver {

typedef std::map<std::string, Json::Value> ParametersMap;

class Command {
 public:
  Command(void);
  virtual ~Command(void);
  std::string Serialize(void);
  void Deserialize(const std::string& json);

  std::string command_type(void) const { return this->command_type_; }
  ParametersMap command_parameters(void) const {
    return this->command_parameters_;
  }

 private:
  // The type of command this represents.
  std::string command_type_;
  // Session ID for this command.
  std::string session_id_;
  // Command parameters passed as JSON in the body of the request.
  ParametersMap command_parameters_;

  DISALLOW_COPY_AND_ASSIGN(Command);
};

}  // namespace webdriver

#endif  // WEBDRIVER_SERVER_COMMAND_H_
