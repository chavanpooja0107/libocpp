// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest
#ifndef OCPP_COMMON_CHARGE_POINT_HPP
#define OCPP_COMMON_CHARGE_POINT_HPP

#include <boost/shared_ptr.hpp>

#include <ocpp/common/evse_security.hpp>
#include <ocpp/common/evse_security_impl.hpp>
#include <ocpp/common/message_queue.hpp>
#include <ocpp/common/ocpp_logging.hpp>

namespace ocpp {

/// \brief Common base class for OCPP1.6 and OCPP2.0.1 charging stations
class ChargingStationBase {

protected:
    std::shared_ptr<EvseSecurity> evse_security;
    std::shared_ptr<MessageLogging> logging;

    boost::shared_ptr<boost::asio::executor_work_guard<boost::asio::io_context::executor_type>> work;
    boost::asio::io_context io_context;
    std::thread io_context_thread;

public:
    /// \brief Constructor for ChargingStationBase
    /// \param evse_security Pointer to evse_security that manages security related operations; if nullptr
    /// security_configuration must be set
    /// \param security_configuration specifies the file paths that are required to set up the internal evse_security
    /// implementation
    explicit ChargingStationBase(const std::shared_ptr<EvseSecurity> evse_security,
                                 const std::optional<SecurityConfiguration> security_configuration = std::nullopt);
    virtual ~ChargingStationBase();
}

} // namespace ocpp

#endif // OCPP_COMMON
