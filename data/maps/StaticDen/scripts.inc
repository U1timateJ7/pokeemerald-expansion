StaticDen_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, StaticDen_OnResume
	map_script MAP_SCRIPT_ON_LOAD, StaticDen_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, StaticDen_OnTransition
	.byte 0

StaticDen_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, StaticDen_EventScript_TryRemoveRegieleki
	end

StaticDen_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

StaticDen_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, StaticDen_EventScript_HideRegiEntrance
	end

StaticDen_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

StaticDen_OnTransition:
	setflag FLAG_LANDMARK_STATIC_DEN
	call StaticDen_EventScript_ClearSteps
	call_if_unset FLAG_DEFEATED_REGIELEKI, StaticDen_EventScript_ShowRegieleki
	end

StaticDen_EventScript_ShowRegieleki::
	clearflag FLAG_HIDE_REGIELEKI
	return

StaticDen_EventScript_OpenRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED
	end

StaticDen_EventScript_CaveEntranceMiddle::
	lockall
	call_if_set FLAG_TEMP_REGIELEKI_PUZZLE_FAILED, StaticDen_EventScript_ClearSteps
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, StaticDen_EventScript_BigHoleInWall
	braillemessage StaticDen_Braille_RunLapAroundWall
	setflag FLAG_TEMP_REGIELEKI_PUZZLE_STARTED
	special ShouldDoBrailleRegielekiPuzzle
	goto StaticDen_EventScript_CloseBrailleMsg
	end

StaticDen_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

StaticDen_EventScript_CaveEntranceSide::
	lockall
	call_if_set FLAG_TEMP_REGIELEKI_PUZZLE_FAILED, StaticDen_EventScript_ClearSteps
	braillemessage StaticDen_Braille_RunLapAroundWall
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, StaticDen_EventScript_CloseBrailleMsg
	setflag FLAG_TEMP_REGIELEKI_PUZZLE_STARTED
	special ShouldDoBrailleRegielekiPuzzle
	goto StaticDen_EventScript_CloseBrailleMsg
	end

StaticDen_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

StaticDen_EventScript_ClearSteps::
	setvar VAR_REGIELEKI_STEPS_1, 0
	setvar VAR_REGIELEKI_STEPS_2, 0
	setvar VAR_REGIELEKI_STEPS_3, 0
	clearflag FLAG_TEMP_REGIELEKI_PUZZLE_FAILED
	return

StaticDen_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, StaticDen_EventScript_DefeatedRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, StaticDen_EventScript_RanFromRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, StaticDen_EventScript_RanFromRegieleki
	setflag FLAG_DEFEATED_REGIELEKI
	release
	end

StaticDen_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

StaticDen_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end
