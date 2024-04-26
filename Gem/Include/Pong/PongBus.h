
#pragma once

#include <Pong/PongTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Pong
{
    class PongRequests
    {
    public:
        AZ_RTTI(PongRequests, PongRequestsTypeId);
        virtual ~PongRequests() = default;
        // Put your public methods here
    };

    class PongBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using PongRequestBus = AZ::EBus<PongRequests, PongBusTraits>;
    using PongInterface = AZ::Interface<PongRequests>;

} // namespace Pong
