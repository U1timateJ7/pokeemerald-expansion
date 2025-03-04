.set LOCALID_NURSE, 1
.set LOCALID_SCOTT, 4

EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman::
	message EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad
	waitmessage
	goto EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu1
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu1::
	multichoice 0, 0, MULTI_TERA1, FALSE
	switch VAR_RESULT
	case 0, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraNormal
	case 1, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraFighting
	case 2, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraFlying
	case 3, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraPoison
	case 4, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu2
	case 5, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	case MULTI_B_PRESSED, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu2::
	multichoice 0, 0, MULTI_TERA2, FALSE
	switch VAR_RESULT
	case 0, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraGround
	case 1, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraRock
	case 2, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraBug
	case 3, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraGhost
	case 4, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu3
	case 5, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	case MULTI_B_PRESSED, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu3::
	multichoice 0, 0, MULTI_TERA3, FALSE
	switch VAR_RESULT
	case 0, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraSteel
	case 1, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraFire
	case 2, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraWater
	case 3, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraGrass
	case 4, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu4
	case 5, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	case MULTI_B_PRESSED, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu4::
	multichoice 0, 0, MULTI_TERA4, FALSE
	switch VAR_RESULT
	case 0, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraElectric
	case 1, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraPsychic
	case 2, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraIce
	case 3, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraDragon
	case 4, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu5
	case 5, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	case MULTI_B_PRESSED, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu5::
	multichoice 0, 0, MULTI_TERA5, FALSE
	switch VAR_RESULT
	case 0, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraDark
	case 1, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraFairy
	case 2, EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraStellar
	case 3, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenu1
	case 4, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	case MULTI_B_PRESSED, EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TeraMenuExit::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraNormal::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_NORMAL
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraFighting::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_FIGHTING
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraFlying::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_FLYING
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraPoison::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_POISON
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraGround::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_GROUND
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraRock::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_ROCK
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraBug::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_BUG
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraGhost::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_GHOST
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraSteel::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_STEEL
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraFire::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_FIRE
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraWater::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_WATER
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraGrass::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_GRASS
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraElectric::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_ELECTRIC
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraPsychic::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_PSYCHIC
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraIce::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_ICE
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraDragon::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_DRAGON
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraDark::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_DARK
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraFairy::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_FAIRY
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ChangeTeraStellar::
	special ChoosePartyMon
	waitstate
	setmonteratype TYPE_STELLAR
	msgbox EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth::
	applymovement LOCALID_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit::
	applymovement LOCALID_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad:
	.string "The POKéMON LEAGUE is only a short\n"
	.string "distance after the VICTORY ROAD.\p"
	.string "If you've come this far, what choice\n"
	.string "do you have but to keep going?\p"
	.string "Do you want me to change one of your\n"
	.string "POKéMONs Tera Type?$"

EverGrandeCity_PokemonCenter_1F_Text_HaveANiceDay:
	.string "Have a nice day!$"

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon:
	.string "The long and harrowing VICTORY ROAD…\p"
	.string "It's like reliving the path one has\n"
	.string "traveled in life…\p"
	.string "Believe in your POKéMON and give it\n"
	.string "your very best!$"

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou:
	.string "SCOTT: {PLAYER}{KUN}, you've clawed your\n"
	.string "way up to face the POKéMON LEAGUE!\p"
	.string "I'm happy for you!\n"
	.string "You made my cheering worthwhile!\p"
	.string "{PLAYER}{KUN}, if you were to become\n"
	.string "the POKéMON LEAGUE CHAMPION…\p"
	.string "I'll get in touch with you then.\p"
	.string "Okay, {PLAYER}{KUN}.\n"
	.string "Go for greatness!$"

