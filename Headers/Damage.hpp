#pragma once

//TODO: Implement damage types (I'm not sure what these will be so I'll just create an enum with a default value)
enum dmg_type { DEF_DMG };

class Damage
{
public:
	Damage() { type = DEF_DMG; };

	//additional constructor with type?

private:
	dmg_type type;
};