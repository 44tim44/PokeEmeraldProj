SootopolisCity_Gym_1F_MapScripts:: @ 8224E4C
	map_script 2, SootopolisCity_Gym_1F_MapScript2_224ECB
	map_script 5, SootopolisCity_Gym_1F_MapScript1_224E67
	map_script 1, SootopolisCity_Gym_1F_MapScript1_224E6A
	map_script 3, SootopolisCity_Gym_1F_MapScript1_224E61
	.byte 0

SootopolisCity_Gym_1F_MapScript1_224E61: @ 8224E61
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_MapScript1_224E67: @ 8224E67
	setstepcallback 4
	end

SootopolisCity_Gym_1F_MapScript1_224E6A: @ 8224E6A
	call SootopolisCity_Gym_1F_EventScript_224E73
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_224E73:: @ 8224E73
	compare VAR_ICE_STEP_COUNT, 8
	goto_if 0, SootopolisCity_Gym_1F_EventScript_224ECA
	compare VAR_ICE_STEP_COUNT, 28
	goto_if 0, SootopolisCity_Gym_1F_EventScript_224EB8
	compare VAR_ICE_STEP_COUNT, 67
	goto_if 0, SootopolisCity_Gym_1F_EventScript_224EA6
	setmetatile 8, 4, 519, 0
	setmetatile 8, 5, 519, 0

SootopolisCity_Gym_1F_EventScript_224EA6:: @ 8224EA6
	setmetatile 8, 10, 519, 0
	setmetatile 8, 11, 519, 0

SootopolisCity_Gym_1F_EventScript_224EB8:: @ 8224EB8
	setmetatile 8, 15, 519, 0
	setmetatile 8, 16, 519, 0

SootopolisCity_Gym_1F_EventScript_224ECA:: @ 8224ECA
	return

SootopolisCity_Gym_1F_MapScript2_224ECB: @ 8224ECB
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_224EED
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_224F01
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_224F15
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_224F29
	.2byte 0

SootopolisCity_Gym_1F_EventScript_224EED:: @ 8224EED
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_RU_GASHIN
	call SootopolisCity_Gym_1F_EventScript_224E73
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_224F01:: @ 8224F01
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_RU_GASHIN
	call SootopolisCity_Gym_1F_EventScript_224E73
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_224F15:: @ 8224F15
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_RU_GASHIN
	call SootopolisCity_Gym_1F_EventScript_224E73
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_224F29:: @ 8224F29
	lockall
	delay 20
	applymovement 255, SootopolisCity_Gym_1F_Movement_224F42
	waitmovement 0
	playse SE_RU_HYUU
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_224F42: @ 8224F42
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_224F44:: @ 8224F44
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_225268, SootopolisCity_Gym_1F_Text_225432, SootopolisCity_Gym_1F_EventScript_224F82, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_eq SootopolisCity_Gym_1F_EventScript_225025
	checkflag FLAG_0x0AC
	goto_if 0, SootopolisCity_Gym_1F_EventScript_224FF7
	checkflag FLAG_BADGE06_GET
	goto_if 0, SootopolisCity_Gym_1F_EventScript_22501B
	msgbox SootopolisCity_Gym_1F_Text_225778, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_224F82:: @ 8224F82
	message SootopolisCity_Gym_1F_Text_225598
	waitmessage
	call SootopolisCity_Gym_1F_EventScript_27207E
	msgbox SootopolisCity_Gym_1F_Text_2255BE, MSGBOX_DEFAULT
	setflag FLAG_0x4F7
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_0x405E, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call SootopolisCity_Gym_1F_EventScript_271F43
	call SootopolisCity_Gym_1F_EventScript_224FD4
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox SootopolisCity_Gym_1F_Text_22574D, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_0x1D9
	release
	end

SootopolisCity_Gym_1F_EventScript_224FD4:: @ 8224FD4
	giveitem_std ITEM_TM03
	compare VAR_RESULT, 0
	goto_eq SootopolisCity_Gym_1F_EventScript_27205E
	msgbox SootopolisCity_Gym_1F_Text_2256C1, MSGBOX_DEFAULT
	setflag FLAG_0x0AC
	return

SootopolisCity_Gym_1F_EventScript_224FF7:: @ 8224FF7
	giveitem_std ITEM_TM03
	compare VAR_RESULT, 0
	goto_eq SootopolisCity_Gym_1F_EventScript_272054
	msgbox SootopolisCity_Gym_1F_Text_2256C1, MSGBOX_DEFAULT
	setflag FLAG_0x0AC
	release
	end

SootopolisCity_Gym_1F_EventScript_22501B:: @ 822501B
	msgbox SootopolisCity_Gym_1F_Text_225865, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_225025:: @ 8225025
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_225950, SootopolisCity_Gym_1F_Text_225A2E, SootopolisCity_Gym_1F_Text_225B48
	msgbox SootopolisCity_Gym_1F_Text_225A67, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_225040:: @ 8225040
	lock
	faceplayer
	checkflag FLAG_0x4F7
	goto_eq SootopolisCity_Gym_1F_EventScript_225055
	msgbox SootopolisCity_Gym_1F_Text_225093, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_225055:: @ 8225055
	msgbox SootopolisCity_Gym_1F_Text_2251AF, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_22505F:: @ 822505F
	lockall
	checkflag FLAG_BADGE08_GET
	goto_eq SootopolisCity_Gym_1F_EventScript_22507F
	goto SootopolisCity_Gym_1F_EventScript_225089
	end

SootopolisCity_Gym_1F_EventScript_22506F:: @ 822506F
	lockall
	checkflag FLAG_BADGE08_GET
	goto_eq SootopolisCity_Gym_1F_EventScript_22507F
	goto SootopolisCity_Gym_1F_EventScript_225089
	end

SootopolisCity_Gym_1F_EventScript_22507F:: @ 822507F
	msgbox SootopolisCity_Gym_1F_Text_225916, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_225089:: @ 8225089
	msgbox SootopolisCity_Gym_1F_Text_2258FA, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_225093: @ 8225093
	.string "Yo! How's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "SOOTOPOLIS's GYM LEADER JUAN is\n"
	.string "a master of WATER-type POKéMON.\p"
	.string "And, to get to JUAN, an icy floor\n"
	.string "will hamper your progress…\p"
	.string "Listen, I'm sorry, but that's all the\n"
	.string "advice that I have for you.\p"
	.string "The rest of the way, you have to\n"
	.string "go for it yourself!$"

SootopolisCity_Gym_1F_Text_2251AF: @ 82251AF
	.string "Yow! You've beaten even JUAN, who\n"
	.string "was supposedly the best in all HOENN!\p"
	.string "Okay! Check out your TRAINER CARD.\p"
	.string "If you've gotten all the BADGES, you're\n"
	.string "set for the POKéMON LEAGUE challenge!$"

SootopolisCity_Gym_1F_Text_225268: @ 8225268
	.string "Let me ask you.\n"
	.string "Did you know?\l"
	.string "Ah, I should not be so coy.\p"
	.string "It was I who taught WALLACE everything\n"
	.string "there is to know about POKéMON.\p"
	.string "Once, I had given up my position as\n"
	.string "the GYM LEADER.\p"
	.string "In my place, I had entrusted WALLACE\n"
	.string "with the GYM.\p"
	.string "However, a compelling reason arose for\n"
	.string "me to make a comeback.\p"
	.string "Ah, but enough chatter.\n"
	.string "Let us begin our match, shall we?\p"
	.string "Please, you shall bear witness to\n"
	.string "our artistry.\p"
	.string "A grand illusion of water sculpted\n"
	.string "by POKéMON and myself!$"

SootopolisCity_Gym_1F_Text_225432: @ 8225432
	.string "Ahahaha, excellent!\n"
	.string "Very well, you are the winner.\p"
	.string "From you, I sense the brilliant shine\n"
	.string "of skill that will overcome all.\p"
	.string "However, compared with me or even\n"
	.string "WALLACE, you are lacking in elegance.\p"
	.string "Perhaps I should make you a loan\n"
	.string "of my outfit?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hahaha, I merely jest!\p"
	.string "Rather than my clothes, I shall reward\n"
	.string "you with this, the RAIN BADGE!$"

SootopolisCity_Gym_1F_Text_225598: @ 8225598
	.string "{PLAYER} received the RAIN BADGE\n"
	.string "from JUAN.$"

SootopolisCity_Gym_1F_Text_2255BE: @ 82255BE
	.string "Having the RAIN BADGE shall assure you\n"
	.string "the full obedience of all your POKéMON\l"
	.string "to your every command.\p"
	.string "The RAIN BADGE also allows the use\n"
	.string "of the HM move WATERFALL to scale\l"
	.string "walls of cascading water.\p"
	.string "And, so that you never forget the\n"
	.string "battle we shared, take this…$"

SootopolisCity_Gym_1F_Text_2256C1: @ 82256C1
	.string "The TECHNICAL MACHINE I handed you\n"
	.string "contains WATER PULSE.\p"
	.string "In use, it will occasionally confuse\n"
	.string "the target with ultrasonic waves.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_22574D: @ 822574D
	.string "Registered GYM LEADER JUAN\n"
	.string "in the POKéNAV.$"

SootopolisCity_Gym_1F_Text_225778: @ 8225778
	.string "The TRAINERS who have gathered all\n"
	.string "the GYM BADGES of HOENN should make\l"
	.string "way to the ultimate destination.\p"
	.string "The POKéMON LEAGUE.\p"
	.string "Travel to the easternmost reaches\n"
	.string "of HOENN, to the island EVER GRANDE.\p"
	.string "There, you shall find the POKéMON\n"
	.string "LEAGUE.$"

SootopolisCity_Gym_1F_Text_225865: @ 8225865
	.string "There remains but one BADGE to\n"
	.string "obtain in HOENN.\p"
	.string "If you wish to challenge the POKéMON\n"
	.string "LEAGUE, you must obtain the last\l"
	.string "BADGE from the GYM in FORTREE.$"

SootopolisCity_Gym_1F_Text_2258FA: @ 82258FA
	.string "SOOTOPOLIS CITY POKéMON GYM$"

SootopolisCity_Gym_1F_Text_225916: @ 8225916
	.string "SOOTOPOLIS CITY POKéMON GYM\p"
	.string "JUAN'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_225950: @ 8225950
	.string "JUAN: Ah, this GYM had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\p"
	.string "I shall be delighted to dance with you\n"
	.string "as often as you wish!$"

SootopolisCity_Gym_1F_Text_225A2E: @ 8225A2E
	.string "Ahahaha, you are the winner!\n"
	.string "You have defeated me again!$"

SootopolisCity_Gym_1F_Text_225A67: @ 8225A67
	.string "JUAN: If I told you to become my\n"
	.string "apprentice, you will refuse, I am sure.\p"
	.string "I would like to make a gift of my coat\n"
	.string "to you.\p"
	.string "But again, you will refuse.\n"
	.string "I imagine that to be so.\p"
	.string "And that, my friend, is a certain sign\n"
	.string "of nobility!$"

SootopolisCity_Gym_1F_Text_225B48: @ 8225B48
	.string "JUAN: Ah, this GYM had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\n"
	.string "I shall be delighted to dance with you…\p"
	.string "Ah, no, no, no.\n"
	.string "You have with you but one POKéMON.\p"
	.string "I wish that you would return with\n"
	.string "two, perhaps more, POKéMON, please.$"
