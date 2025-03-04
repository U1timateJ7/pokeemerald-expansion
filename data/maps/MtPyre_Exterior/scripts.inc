MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtPyre_Exterior_OnLoad
	.byte 0

MtPyre_Exterior_OnTransition:
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_OnLoad:
	goto_if_unset FLAG_IS_CHAMPION, MtPyre_Exterior_EventScript_ConcealMythRoom
	goto_if_set FLAG_IS_CHAMPION, MtPyre_Exterior_EventScript_RevealPhoebe
	end

MtPyre_Exterior_EventScript_ConcealMythRoom::
	setflag FLAG_HIDE_PHOEBE
	setmetatile 15, 25, METATILE_General_RockWall, TRUE
	setmetatile 15, 26, METATILE_General_RockWall_SandBase, TRUE
	end

MtPyre_Exterior_EventScript_RevealPhoebe::
	clearflag FLAG_HIDE_PHOEBE
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit::
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	doweather
	end

MtPyre_Exterior_EventScript_Phoebe::
	msgbox MtPyre_Exterior_Text_StrangeEnergy, MSGBOX_NPC
	end

MtPyre_Exterior_Text_StrangeEnergy:
	.string "There seems to be a strange energy\n"
	.string "coming from this cave here.\p"
	.string "Could you go inside and see what's\n"
	.string "there?$"

