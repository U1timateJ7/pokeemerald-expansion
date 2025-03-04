.set LOCALID_RED, 1

RedRoom_MapScripts::
	.byte 0

RedRoom_EventScript_Leaf::
	trainerbattle_single TRAINER_LEAF, RedRoom_Text_LeafIntro, RedRoom_Text_LeafDefeat
	msgbox RedRoom_Text_LeafPostBattle, MSGBOX_AUTOCLOSE
	end

RedRoom_EventScript_Red::
	lock
	goto_if_set FLAG_DEFEATED_RED, RedRoom_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_RED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RED, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RedRoom_Text_DotDotDot, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_RED, RedRoom_Text_DotDotDot
	setflag FLAG_DEFEATED_RED
	release
	end

RedRoom_EventScript_Defeated::
	applymovement LOCALID_RED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RedRoom_Text_DotDotDot, MSGBOX_DEFAULT
	release
	end

RedRoom_Text_LeafIntro:
	.string "I strongly advise turning back.\p"
	.string "The challenge ahead is unlike any\n"
	.string "other you've faced so far.\p"
	.string "If you won't, I'll have to\n"
	.string "battle you now.$"

RedRoom_Text_LeafDefeat:
	.string "You've proven strong.\p"
	.string "What you do next is not my\n"
	.string "problem anymore.$"

RedRoom_Text_LeafPostBattle:
	.string "I've been on a long journey. I\n"
	.string "might go home now…$"

RedRoom_Text_DotDotDot:
	.string "…$"
