proctype gcd(int x, y) {
	
	if
		:: y==0 -> printf("gcd is %d",x);
		:: else -> 	run gcd(y, x%y);
	fi
}

init {
	
	run gcd(12,6);
	
}
