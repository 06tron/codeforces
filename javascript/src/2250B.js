let t = ar.nextInt();
const out = [];
while (t--) {
	let n = ar.nextInt();
	let k = ar.nextInt();
	const nOdd = (n & 1) == 1;
	const kOdd = (k & 1) == 1;
	if (k > n-2) {
		// a length n binary string containing only 0 will have n-1 pairs of adjacent equal characters
		// if the string contains both 0 and 1, then it can have at most n-2 pairs
		out.push("-1");
		continue;
	}
	let binary = new Uint8Array(n);
	if (!nOdd && k == n-3) {
		// a one followed by n/2 zeros, followed by n/2-1 ones
		binary[0] = 1
		for (let i = n/2 + 1; i < n; ++i) {
			binary[i] = 1;
		}
		out.push(binary.join(""));
		continue;
	}
	let i = 0;
	if (nOdd) {
		n -= 1;
		if (kOdd) {
			k -= 1;
		}
	} else if (kOdd) {
		// adds a single pair
		binary[0] = binary[3] = 0;
		binary[1] = binary[2] = 1;
		i = 4;
		k -= 1;
	}
	// now n and k will be even
	const m = (k + 2) / 2;
	for (let j = 0; j < m; ++j) {
		// creates 2m-2=k pairs 
		binary[i] = 1;
		binary[i+m] = 0;
		++i;
	}
	for (i += m; i < n; i += 2) {
		// fills remaining space with alternating bits, creating no pairs
		binary[i] = 1;
		binary[i+1] = 0;
	}
	if (nOdd) {
		// adds another pair if k was odd
		binary[i] = kOdd ? 0 : 1;
	}
	out.push(binary.join(""));
}
process.stdout.write(out.join('\n'));
// Began: 1785078236
// Ended: 1785084609
