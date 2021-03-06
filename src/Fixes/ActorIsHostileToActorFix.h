#pragma once

namespace Fixes
{
	class ActorIsHostileToActorFix
	{
	public:
		static void Install()
		{
			constexpr std::size_t size = 0x10;
			REL::Relocation<std::uintptr_t> target{ REL::ID(1022223) };

			REL::safe_fill(target.address(), REL::INT3, size);
			stl::asm_jump(target.address(), size, reinterpret_cast<std::uintptr_t>(&IsHostileToActor));

			logger::info("installed {}"sv, typeid(ActorIsHostileToActorFix).name());
		}

	private:
		static bool IsHostileToActor(RE::BSScript::IVirtualMachine* a_vm, std::uint32_t a_stackID, RE::Actor* a_self, RE::Actor* a_actor)
		{
			if (!a_actor) {
				RE::GameScript::LogFormError(
					a_actor,
					"Cannot call IsHostileToActor with a None actor",
					a_vm,
					a_stackID);
				return false;
			} else {
				return a_self->GetHostileToActor(a_actor);
			}
		}
	};
}
