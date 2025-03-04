.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MeteorFalls_StevensCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorFalls_StevensCave_OnTransition
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MeteorFalls_StevensCave_EventScript_TryRemoveTerapagos
	end

MeteorFalls_StevensCave_EventScript_TryRemoveTerapagos::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MeteorFalls_StevensCave_OnTransition::
	call_if_unset FLAG_DEFEATED_TERAPAGOS, MeteorFalls_StevensCave_EventScript_ShowTerapagos
	end

MeteorFalls_StevensCave_EventScript_ShowTerapagos::
	clearflag FLAG_HIDE_TERAPAGOS
	return

MeteorFalls_StevensCave_EventScript_Terapagos::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TERAPAGOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_TERAPAGOS, 85
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MeteorFalls_StevensCave_EventScript_DefeatedTerapagos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MeteorFalls_StevensCave_EventScript_RanFromTerapagos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MeteorFalls_StevensCave_EventScript_RanFromTerapagos
	setflag FLAG_DEFEATED_TERAPAGOS
	release
	end

MeteorFalls_StevensCave_EventScript_DefeatedTerapagos::
	setflag FLAG_DEFEATED_TERAPAGOS
	goto Common_EventScript_RemoveStaticPokemon
	end

MeteorFalls_StevensCave_EventScript_RanFromTerapagos::
	setvar VAR_0x8004, SPECIES_TERAPAGOS
	goto Common_EventScript_LegendaryFlewAway
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "Do you, uh…maybe think of me as\n"
	.string "just a rock maniac?\p"
	.string "No, that can't be right.\p"
	.string "We battled alongside each other at\n"
	.string "the SOOTOPOLIS SPACE CENTER.\p"
	.string "You should have a very good idea\n"
	.string "about how good I am.\p"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
	.string "a serious challenge, expect the worst!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "You…\n"
	.string "I had no idea you'd become so strong…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Come to think of it, ever since\n"
	.string "our paths first crossed in GRANITE\l"
	.string "CAVE in DEWFORD, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become the CHAMPION.\p"
	.string "My predictions usually come true.\p"
	.string "And where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"

