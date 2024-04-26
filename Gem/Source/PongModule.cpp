
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "PongSystemComponent.h"

#include <Pong/PongTypeIds.h>

namespace Pong
{
    class PongModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(PongModule, PongModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(PongModule, AZ::SystemAllocator);

        PongModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PongSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PongSystemComponent>(),
            };
        }
    };
}// namespace Pong

AZ_DECLARE_MODULE_CLASS(Gem_Pong, Pong::PongModule)
