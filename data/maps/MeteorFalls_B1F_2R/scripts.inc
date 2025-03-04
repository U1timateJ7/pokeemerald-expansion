MeteorFalls_B1F_2R_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MeteorFalls_B1F_2R_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorFalls_B1F_2R_OnTransition
	.byte 0

MeteorFalls_B1F_2R_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MeteorFalls_B1F_2R_EventScript_TryRemoveOgerpon
	end

MeteorFalls_B1F_2R_EventScript_TryRemoveOgerpon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MeteorFalls_B1F_2R_OnTransition::
	call_if_unset FLAG_DEFEATED_OGERPON, MeteorFalls_B1F_2R_EventScript_ShowOgerpon
	end

MeteorFalls_B1F_2R_EventScript_ShowOgerpon::
	clearflag FLAG_HIDE_OGERPON
	return

MeteorFalls_B1F_2R_EventScript_Ogerpon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_OGERPON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_OGERPON, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MeteorFalls_B1F_2R_EventScript_DefeatedOgerpon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MeteorFalls_B1F_2R_EventScript_RanFromOgerpon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MeteorFalls_B1F_2R_EventScript_RanFromOgerpon
	setflag FLAG_DEFEATED_OGERPON
	giveitem ITEM_CORNERSTONE_MASK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_WELLSPRING_MASK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_HEARTHFLAME_MASK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	release
	end

MeteorFalls_B1F_2R_EventScript_DefeatedOgerpon::
	setflag FLAG_DEFEATED_OGERPON
	goto Common_EventScript_RemoveStaticPokemon
	end

MeteorFalls_B1F_2R_EventScript_RanFromOgerpon::
	setvar VAR_0x8004, SPECIES_OGERPON
	goto Common_EventScript_LegendaryFlewAway
	end
