Route100_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route100_OnLoad
	.byte 0

Route100_OnLoad:
	special CheckHasAllRegis
	goto_if_unset FLAG_HAS_ALL_REGIS, Route100_EventScript_ConcealGigaTemple
	end

Route100_EventScript_ConcealGigaTemple::
	setmetatile 12, 15, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 12, 16, METATILE_General_RockWall_GrassBase, TRUE
	end
