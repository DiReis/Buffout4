#include "Compatibility/Compatibility.h"

#include "Compatibility/F4EE.h"

namespace Compatibility
{
	void Install()
	{
		if (*Settings::F4EE) {
			F4EE::Install();
		}
	}
}
