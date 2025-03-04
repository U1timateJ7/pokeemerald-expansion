DraconicHollow_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, DraconicHollow_OnResume
	map_script MAP_SCRIPT_ON_LOAD, DraconicHollow_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DraconicHollow_OnTransition
	.byte 0

DraconicHollow_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DraconicHollow_EventScript_TryRemoveRegidrago
	end

DraconicHollow_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

DraconicHollow_OnLoad:
	call_if_unset FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED, DraconicHollow_EventScript_HideRegiEntrance
	end

DraconicHollow_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

DraconicHollow_OnTransition:
	setflag FLAG_LANDMARK_DESERT_RUINS
	call_if_unset FLAG_DEFEATED_REGIDRAGO, DraconicHollow_EventScript_ShowRegidrago
	end

DraconicHollow_EventScript_ShowRegidrago::
	clearflag FLAG_HIDE_REGIDRAGO
	return

DraconicHollow_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED, DraconicHollow_EventScript_BigHoleInWall
	braillemsgbox DraconicHollow_Braille_UseRockSmash
	releaseall
	end

DraconicHollow_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

DraconicHollow_EventScript_CaveEntranceSide::
	lockall
	braillemsgbox DraconicHollow_Braille_UseRockSmash
	releaseall
	end

DraconicHollow_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DraconicHollow_EventScript_DefeatedRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DraconicHollow_EventScript_RanFromRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DraconicHollow_EventScript_RanFromRegidrago
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

DraconicHollow_EventScript_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

DraconicHollow_EventScript_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end
