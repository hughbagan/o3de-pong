
#pragma once

#include <AzCore/Component/Component.h>

#include <Pong/PongBus.h>

namespace Pong
{
    class PongSystemComponent
        : public AZ::Component
        , protected PongRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(PongSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        PongSystemComponent();
        ~PongSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PongRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
