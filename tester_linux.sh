if [[ "$1" != '' && "$2" != '' && "$3" != '' ]]
then
	while [ 1 ]
	do
		ARG=$(seq $1 $2 | sort -R);
		PUSH_SWAP_RESULT=$(./push_swap $ARG);
		PUSH_SWAP_COUNT=$(echo "$PUSH_SWAP_RESULT" | wc -l);
		if [[ $PUSH_SWAP_RESULT == '' ]]
		then
			PUSH_SWAP_STATUS=$(echo -n "$PUSH_SWAP_RESULT" | ./checker $ARG);
		else
			PUSH_SWAP_STATUS=$(echo "$PUSH_SWAP_RESULT" | ./checker $ARG);
		fi
		if [[ "$4" != "-s" ]]
		then
			echo -e $ARG '-' $PUSH_SWAP_STATUS '-' $PUSH_SWAP_COUNT "\n";
		fi
		if [[ "$PUSH_SWAP_STATUS" == "KO" ]]
		then
			echo "Checker returned KO"
			break
		fi
		if [[ "$PUSH_SWAP_COUNT" -gt "$3" ]]
		then
			echo "Instruction count bigger than" $3
			break
		fi
	done
else
	echo "Missing arguments."
fi