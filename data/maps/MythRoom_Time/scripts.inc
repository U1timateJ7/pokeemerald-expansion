MythRoom_Time_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MythRoom_Time_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MythRoom_Time_OnTransition
	.byte 0

MythRoom_Time_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MythRoom_Time_EventScript_TryRemoveLegend
	end

MythRoom_Time_EventScript_TryRemoveLegend::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MythRoom_Time_OnTransition::
	call_if_unset FLAG_DEFEATED_DIALGA, MythRoom_Time_EventScript_ShowDialga
	end

MythRoom_Time_EventScript_ShowDialga::
	clearflag FLAG_HIDE_DIALGA
	return

MythRoom_Time_EventScript_Dialga::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_DIALGA, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MythRoom_Time_EventScript_DefeatedDialga
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MythRoom_Time_EventScript_RanFromDialga
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MythRoom_Time_EventScript_RanFromDialga
	setflag FLAG_DEFEATED_DIALGA
	giveitem ITEM_ADAMANT_CRYSTAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	release
	end

MythRoom_Time_EventScript_DefeatedDialga::
	setflag FLAG_DEFEATED_DIALGA
	goto Common_EventScript_RemoveStaticPokemon
	end

MythRoom_Time_EventScript_RanFromDialga::
	setvar VAR_0x8004, SPECIES_DIALGA
	goto Common_EventScript_LegendaryFlewAway
	end
