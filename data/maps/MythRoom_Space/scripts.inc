MythRoom_Space_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MythRoom_Space_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MythRoom_Space_OnTransition
	.byte 0

MythRoom_Space_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MythRoom_Space_EventScript_TryRemoveLegend
	end

MythRoom_Space_EventScript_TryRemoveLegend::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MythRoom_Space_OnTransition::
	call_if_unset FLAG_DEFEATED_PALKIA, MythRoom_Space_EventScript_ShowPalkia
	end

MythRoom_Space_EventScript_ShowPalkia::
	clearflag FLAG_HIDE_PALKIA
	return

MythRoom_Space_EventScript_Palkia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_PALKIA, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MythRoom_Space_EventScript_DefeatedPalkia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MythRoom_Space_EventScript_RanFromPalkia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MythRoom_Space_EventScript_RanFromPalkia
	setflag FLAG_DEFEATED_PALKIA
	giveitem ITEM_LUSTROUS_GLOBE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	release
	end

MythRoom_Space_EventScript_DefeatedPalkia::
	setflag FLAG_DEFEATED_PALKIA
	goto Common_EventScript_RemoveStaticPokemon
	end

MythRoom_Space_EventScript_RanFromPalkia::
	setvar VAR_0x8004, SPECIES_PALKIA
	goto Common_EventScript_LegendaryFlewAway
	end
