MythRoom_Antimatter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MythRoom_Antimatter_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MythRoom_Antimatter_OnTransition
	.byte 0

MythRoom_Antimatter_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MythRoom_Antimatter_EventScript_TryRemoveLegend
	end

MythRoom_Antimatter_EventScript_TryRemoveLegend::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MythRoom_Antimatter_OnTransition::
	call_if_unset FLAG_DEFEATED_GIRATINA, MythRoom_Antimatter_EventScript_ShowGiratina
	end

MythRoom_Antimatter_EventScript_ShowGiratina::
	clearflag FLAG_HIDE_GIRATINA
	return

MythRoom_Antimatter_EventScript_Giratina::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_GIRATINA, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MythRoom_Antimatter_EventScript_DefeatedGiratina
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MythRoom_Antimatter_EventScript_RanFromGiratina
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MythRoom_Antimatter_EventScript_RanFromGiratina
	setflag FLAG_DEFEATED_GIRATINA
	giveitem ITEM_GRISEOUS_CORE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	release
	end

MythRoom_Antimatter_EventScript_DefeatedGiratina::
	setflag FLAG_DEFEATED_GIRATINA
	goto Common_EventScript_RemoveStaticPokemon
	end

MythRoom_Antimatter_EventScript_RanFromGiratina::
	setvar VAR_0x8004, SPECIES_GIRATINA
	goto Common_EventScript_LegendaryFlewAway
	end
