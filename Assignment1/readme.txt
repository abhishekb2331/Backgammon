In my program i am using Expectimax Search ..

Initially I find all the possible states with reference to the given input upto depth of 2 level
After finding all the states i defined an evaluation function such that the maximum of all the states is my best state.
Evaluation Function:
		The evaluation function I took takes the following parameters into consideration.
		1)The number of blots of white checkers
		2)The number of blots of black checkers
		3)Number of pairs of white checkers formed
		4)anchors of 18th and 20th position
		5)Number of anchors on opponents homeboard
		6)Distance of checkers from 6th position
		7)Pip count
	Now my evaluation function is as follows
	
	  eval=0.1*(ni+mi)+0.025*(barb-barw)+0.37025*(bblot-wblot)+0.025*(anc_wh-anc_bl)+0.0025*(bpip-pip)+0.0925625*(pairs)+0.2776875*(good_pos)+0.185125*(altpos-good_pos)+0.13884375*(anc_home-anc_opp)+0.32396875*(cont_anc_opp-opp_anc_opp)+0.23140625*(cont_anc_home-opp_anc_home)+0.185125*(cont_anc-opp_anc);
	eval2=0.0025*(bpip-pip)



 
Additional Features:
	2)All the checkers condition are satisfied.
	3)Combination of 2 strategies(evaluation functions) are used based on defence and attack.
