AncientCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AncientCave_Time_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AncientCave_Time_OnTransition
	.byte 0

AncientCave_Time_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AncientCave_Time_EventScript_TryRemoveLegend
	end

AncientCave_Time_EventScript_TryRemoveLegend::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AncientCave_Time_OnTransition::
	call_if_unset FLAG_DEFEATED_KORAIDON, AncientCave_Time_EventScript_ShowKoraidon
	end

AncientCave_Time_EventScript_ShowKoraidon::
	clearflag FLAG_HIDE_KORAIDON
	return

AncientCave_Time_EventScript_Koraidon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KORAIDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KORAIDON, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AncientCave_Time_EventScript_DefeatedKoraidon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AncientCave_Time_EventScript_RanFromKoraidon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AncientCave_Time_EventScript_RanFromKoraidon
	setflag FLAG_DEFEATED_KORAIDON
	release
	end

AncientCave_Time_EventScript_DefeatedKoraidon::
	setflag FLAG_DEFEATED_KORAIDON
	goto Common_EventScript_RemoveStaticPokemon
	end

AncientCave_Time_EventScript_RanFromKoraidon::
	setvar VAR_0x8004, SPECIES_KORAIDON
	goto Common_EventScript_LegendaryFlewAway
	end
