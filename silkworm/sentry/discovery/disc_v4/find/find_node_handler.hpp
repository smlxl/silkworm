/*
   Copyright 2023 The Silkworm Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma once

#include <silkworm/infra/concurrency/task.hpp>

#include <boost/asio/ip/udp.hpp>

#include <silkworm/sentry/discovery/node_db/node_db.hpp>

#include "find_node_message.hpp"
#include "message_sender.hpp"

namespace silkworm::sentry::discovery::disc_v4::find {

struct FindNodeHandler {
    static Task<void> handle(
        FindNodeMessage message,
        EccPublicKey sender_public_key,
        boost::asio::ip::udp::endpoint sender_endpoint,
        MessageSender& sender,
        node_db::NodeDb& db);
};

}  // namespace silkworm::sentry::discovery::disc_v4::find
