
#include <AzCore/Serialization/SerializeContext.h>

#include "PongSystemComponent.h"

#include <Pong/PongTypeIds.h>

namespace Pong
{
    AZ_COMPONENT_IMPL(PongSystemComponent, "PongSystemComponent",
        PongSystemComponentTypeId);

    void PongSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<PongSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void PongSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("PongService"));
    }

    void PongSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("PongService"));
    }

    void PongSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void PongSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    PongSystemComponent::PongSystemComponent()
    {
        if (PongInterface::Get() == nullptr)
        {
            PongInterface::Register(this);
        }
    }

    PongSystemComponent::~PongSystemComponent()
    {
        if (PongInterface::Get() == this)
        {
            PongInterface::Unregister(this);
        }
    }

    void PongSystemComponent::Init()
    {
    }

    void PongSystemComponent::Activate()
    {
        PongRequestBus::Handler::BusConnect();
    }

    void PongSystemComponent::Deactivate()
    {
        PongRequestBus::Handler::BusDisconnect();
    }
}
