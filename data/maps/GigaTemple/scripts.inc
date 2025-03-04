GigaTemple_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, GigaTemple_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, GigaTemple_OnTransition
	.byte 0

GigaTemple_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, GigaTemple_EventScript_TryRemoveLegend
	end

GigaTemple_EventScript_TryRemoveLegend::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

GigaTemple_OnTransition::
	call_if_unset FLAG_DEFEATED_REGIGIGAS, GigaTemple_EventScript_ShowRegigigas
	end

GigaTemple_EventScript_ShowRegigigas::
	clearflag FLAG_HIDE_REGIGIGAS
	return

GigaTemple_EventScript_Regigigas::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GigaTemple_EventScript_DefeatedRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GigaTemple_EventScript_RanFromRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GigaTemple_EventScript_RanFromRegigigas
	setflag FLAG_DEFEATED_REGIGIGAS
	release
	end

GigaTemple_EventScript_DefeatedRegigigas::
	setflag FLAG_DEFEATED_REGIGIGAS
	goto Common_EventScript_RemoveStaticPokemon
	end

GigaTemple_EventScript_RanFromRegigigas::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end
